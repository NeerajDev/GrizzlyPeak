//#define QT_NO_DEBUG_OUTPUT

#include <QPainter>
#include <QDebug>
#include <math.h>
#include "UsageGradientCircle.h"
#include "Common.h"

UsageGradientCircle::UsageGradientCircle(const unsigned int uint_source_number,
                                         const QString &qstr_name,
                                         const std::vector<GradientStopRGBAVectorValuesPair> &vector_gradient_stops,
                                         QWidget *ptr_parent)
                    :QWidget(ptr_parent),
                     m_uint_source_number(uint_source_number),
                     m_uint_current_usage(0),
                     m_qstr_name(qstr_name)
    {
    m_ptr_animation_timer = new QTimer(this);

    connect(m_ptr_animation_timer,
            SIGNAL(timeout()),
            this,
            SLOT(on_animation_timer_update()));

    // Loop over the gradients and their stops and build up the gradient. We are in fact looping over each stop

    for (std::vector<GradientStopRGBAVectorValuesPair>::const_iterator GradientStopRGBAVectorValuesPair_iterator = vector_gradient_stops.begin();
         GradientStopRGBAVectorValuesPair_iterator != vector_gradient_stops.end();
         GradientStopRGBAVectorValuesPair_iterator++)
        {
//        qDebug() << "Setting gradient with stop # " << int(GradientStopRGBAVectorValuesPair_iterator - vector_gradient_stops.begin()) << "\n";

        // Ensure there is an rgba value (4 values) in the vector portion of the pair

        if (GradientStopRGBAVectorValuesPair_iterator->second.size() == 4)
            {
//            qDebug() << "Found 4 colors so proceeeding\n";

            m_radial_gradient.setColorAt(GradientStopRGBAVectorValuesPair_iterator->first,
                                         QColor::fromRgbF(GradientStopRGBAVectorValuesPair_iterator->second[0],
                                                          GradientStopRGBAVectorValuesPair_iterator->second[1],
                                                          GradientStopRGBAVectorValuesPair_iterator->second[2],
                                                          GradientStopRGBAVectorValuesPair_iterator->second[3]));
            }
        }

    }

void UsageGradientCircle::paintEvent(QPaintEvent *ptr_event)
    {
    QPainter painter(this);

//    painter.setPen(Qt::blue);
//    painter.setFont(QFont("Arial", 20));
//    painter.drawText(rect(), Qt::AlignCenter, "Qt");

    painter.setPen(Qt::NoPen);
//    painter.setPen(qcolor_main_source_color);

    m_radial_gradient.setCenter(width() / 2,
                                height() / 2);
    m_radial_gradient.setRadius(width() / 2);
    m_radial_gradient.setFocalPoint(width() / 2,
                                    height() / 2);

    QBrush brush(m_radial_gradient);

    const QBrush standard_brush = painter.brush();

    painter.setBrush(brush);

    const QPoint qpoint_circle_center(geometry().center().x() - geometry().x(), geometry().center().y() - geometry().y());

    painter.drawEllipse(qpoint_circle_center,
                        width() / 2,
                        height() / 2);

    // Draw the center disc

    const QColor qcolor_center_disc = QColor::fromRgbF((255) / 255.0,
                                                       (255) / 255.0,
                                                       (255) / 255.0,
                                                       VIEW_1_CENTER_DISC_ALPHA_CHANNEL_FLOAT);

    const QBrush qbrush_center_disc(qcolor_center_disc);
    painter.setBrush(qbrush_center_disc);

    painter.setPen(qcolor_center_disc);

    painter.drawEllipse(qpoint_circle_center,
                        VIEW_1_CENTER_DISC_RADIUS,
                        VIEW_1_CENTER_DISC_RADIUS);
    }

void UsageGradientCircle::apply_usage_delta(const int int_delta)
    {
//    qDebug() << "Applying usage delta of " << int_delta << "\n";

    // If the delta value when added to the current usage exceeds the max, set to the max.

    if ((m_uint_current_usage < SOURCE_USAGE_MAXIMUM) &&
        ((int(m_uint_current_usage) + int_delta) > SOURCE_USAGE_MAXIMUM))
        {
        /*
        qDebug() << "Usage for " << m_qstr_name
                 << " is being set to the maximum\n";
*/

        set_usage(SOURCE_USAGE_MAXIMUM);
        }

    // If the delta value when added to the current usage is less than zero, set to zero

    else if ((m_uint_current_usage > 0) &&
             ((int(m_uint_current_usage) + int_delta) < 0))
        {
        /*
        qDebug() << "Usage for " << m_qstr_name
                 << " is being set to 0\n";
*/

        set_usage(0);
        }

    // If the delta value, when added to the current usage, falls outside of the
    // valid usability range, we negate its value.

    else if (((int(m_uint_current_usage) + int_delta) < 0) ||
             ((int(m_uint_current_usage) + int_delta) > SOURCE_USAGE_MAXIMUM))
        {
        /*
        qDebug() << "Usage for " << m_qstr_name
                 << " is currently " << m_uint_current_usage
                 << " and we are applying a negated delta value of " << int_delta
                 << "\n";
*/

        set_usage(m_uint_current_usage - int_delta);
        }

    else
        {
        /*
        qDebug() << "Usage for " << m_qstr_name
                 << " is currently " << m_uint_current_usage
                 << " and we are applying a delta value of " << int_delta
                 << "\n";
                 */

        set_usage(m_uint_current_usage + int_delta);
        }
    }

void UsageGradientCircle::set_usage(const unsigned int uint_new_usage)
    {
    if (uint_new_usage <= SOURCE_USAGE_MAXIMUM)
        {
//        qDebug() << "Applying new usage of " << uint_new_usage << "\n";

        m_uint_current_usage = uint_new_usage;

        // If the new usage is greater than 0, set the new animated size change to that. If not greater than 0 (ie: equal to zero),
        // set the new animated size change to be the minimum actually viewable.

        const unsigned int uint_actual_visual_represented_usage = (m_uint_current_usage > 0 ? m_uint_current_usage
                                                                                            : VIEW_1_MINIMUM_ACTUAL_VISIBLE_USAGE);

        // Animate the new size change as a ratio of the actual maximum disc size (converting from usage to pixels).

        animate_size_change(uint_actual_visual_represented_usage * 1.0 / SOURCE_USAGE_MAXIMUM * VIEW_1_USAGE_MAXIMUM_DISC_SIZE);
        }
    }

void UsageGradientCircle::resize_and_recenter(const unsigned int uint_new_size)
    {
    // First, get the current center of the circle.

    const QPoint qpoint_current_center = geometry().center();

//    qDebug() << "New size is: " << uint_new_size << " and Geometry center is: " << geometry().center() << " and geometry is: " << geometry() << "\n";
//    qDebug() << "Rect center is: " << rect().center() << " and rect is: " << rect() << "\n";

    // Next, create a new rectangle for the geometry of the circle

    QRect qrect_new_geometry(0,
                             0,
                             uint_new_size,
                             uint_new_size);

    // Next, center the new rectangle where the current center is

    qrect_new_geometry.moveCenter(qpoint_current_center);

    /*
    qDebug() << "Resizing and moving circle. Old geometry is: " << geometry()
             << " and new geometry is: " << qrect_new_geometry
             << "\n";
*/

    setGeometry(qrect_new_geometry);
    }



/****************************************
* Notes on how ease in and out are done *
****************************************/

/*
quadratic easing in/out - acceleration until halfway, then deceleration

    Math.easeInOutQuad = function (t, b, c, d) {
        t /= d/2;
        if (t < 1) return c/2*t*t + b;
        t--;
        return -c/2 * (t*(t-2) - 1) + b;
    };

c = desired total change in value (a total delta that represents the change from start to end)
d = total duration
t = current time (total change since start of animation, so if frame 1 or second 1 after start, this would be 1, etc..)
b = start value

t and d both need to be either frames or units of time
b and c are CONSISTENT but unit-agnostic and simply state what the start value is and how much you want that value to change by over the course of the animation
*/

/************
* END Notes *
************/

void UsageGradientCircle::animate_size_change(const unsigned int uint_new_size)
    {
//    qDebug() << "Animating size change to " << uint_new_size << "\n";

    m_ptr_animation_timer->stop();

    m_int_total_change_in_circle_size = (int(uint_new_size) - width()); // c, in pixels
    m_uint_animation_start_size = width(); // b, in pixels
    m_uint_total_frames = VIEW_1_ANIMATION_NUMBER_OF_FRAMES; // d, in frames
    m_uint_current_frame_count = 0; // t, in frames

/*
    qDebug() << "Starting animation with total change in circle (c) size of " << m_int_total_change_in_circle_size << " pixels and "
             << "start size (b) of " << m_uint_animation_start_size << " pixels and "
             << "total # of frames (d) of " << m_uint_total_frames << " and "
             << "current frame count (t) of " << m_uint_current_frame_count << "\n";
             */

    // Start the timer so animation can proceed.

    m_ptr_animation_timer->start(VIEW_1_ANIMATION_FRAME_PERIOD_MILLISECONDS);
    }

void UsageGradientCircle::on_animation_timer_update()
    {
    m_uint_current_frame_count++;

    if (m_uint_current_frame_count <= VIEW_1_ANIMATION_NUMBER_OF_FRAMES)
        {
        double t = m_uint_current_frame_count;

        t /= (m_uint_total_frames * 1.0 /2);

        double double_new_animation_size_of_circle;

//        qDebug() << "Circle t is " << t << "\n";

        if (t < 1.0)
            {
            double_new_animation_size_of_circle = int(m_int_total_change_in_circle_size) * 1.0 / 2.0 * t * t + (int(m_uint_animation_start_size) * 1.0);
            }

        else
            {
            t = t - 1.0;

            double_new_animation_size_of_circle = (-(int(m_int_total_change_in_circle_size)) * 1.0) / 2.0 * (t * (t - 2.0) - 1.0) + (int(m_uint_animation_start_size) * 1.0);
            }

//        qDebug() << "Animating with new animation size of " << double_new_animation_size_of_circle << " and "
//                 << "current frame count (t) of " << m_uint_current_frame_count << "\n";

        unsigned int int_new_circle_diameter = round(double_new_animation_size_of_circle);

        // If the diameter is an even number, we add one to it, as we want the center point to always have an equal number
        // of pixels to its left and right and above and below.

        if (int_new_circle_diameter % 2 == 0)
            {
            int_new_circle_diameter++;
            }

        resize_and_recenter(int_new_circle_diameter);
        }

    else
        {
//        qDebug() << "Stopping animation\n";

        m_ptr_animation_timer->stop();

        emit source_circle_animation_done(m_uint_source_number);
        }
    }
