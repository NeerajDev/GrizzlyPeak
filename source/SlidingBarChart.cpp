#include <QDebug>
#include <QFile>
#include <QGraphicsOpacityEffect>
#include "SlidingBarChart.h"
#include "CarouselControl.h"
#include "Common.h"

SlidingBarChart::SlidingBarChart(const std::vector<QString> &vector_x_axis_labels,
                                 const unsigned int uint_number_of_bars,
                                 QWidget *parent)
                        :QWidget(parent),
                         m_uint_number_of_bars(uint_number_of_bars),
                         m_enum_selected_source(SOURCE_NONE)
    {
    setupUi(this);

    m_ptr_total_bar_growth_animation_timer = new QTimer(this);
    m_ptr_source_bar_growth_animation_timer = new QTimer(this);
    m_ptr_source_bar_fadeout_animation_timer = new QTimer(this);

    connect(m_ptr_total_bar_growth_animation_timer,
            SIGNAL(timeout()),
            this,
            SLOT(on_total_bar_growth_animation_timer_update()));

    connect(m_ptr_source_bar_growth_animation_timer,
            SIGNAL(timeout()),
            this,
            SLOT(on_source_bar_growth_animation_timer_update()));

    connect(m_ptr_source_bar_fadeout_animation_timer,
            SIGNAL(timeout()),
            this,
            SLOT(on_source_bar_fadeout_animation_timer_update()));

    CarouselControl * carousel = new CarouselControl("background-color:transparent;border-top:0px solid  rgb(0, 0, 0, 50);border-bottom:0px; vertical-align: top;",m_bar_charts_container_widget);


    carousel->setCarouselInfiniteLoop(false);

         carousel->slot_setCarouselSize(QSize(200,656), QSize(500,700));
         carousel->slot_setScaleFactor(0);
         carousel->slot_setItemSize(QSize(75,50), QSize(75,656));
         carousel->slot_setPosition(0,12);

         carousel->slot_setOrientation(Horizontal);
         carousel->initializeItemList();

//         QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect();

//         QLinearGradient alphaGradient(0,0,500,0);
//          alphaGradient.setColorAt(0.0, Qt::transparent);
//          alphaGradient.setColorAt(0.05,Qt::black);
//          alphaGradient.setColorAt(0.95, Qt::black);
//          alphaGradient.setColorAt(1.0, Qt::transparent);

//          effect->setOpacityMask(alphaGradient);

//         m_bar_charts_container_widget-> setGraphicsEffect(effect);


    setAppStyle();

    for (unsigned int counter = 0;
         counter < m_uint_number_of_bars;
         counter++)
        {
        if (counter < vector_x_axis_labels.size())
            {
            BarChartSingleBar *const ptr_new_data_bar_widget = new BarChartSingleBar(vector_x_axis_labels[counter],
                                                                                     carousel);

            m_vector_data_bar_widgets.push_back(ptr_new_data_bar_widget);

           //m_bar_charts_container_widget_horizontal_layout->addWidget(ptr_new_data_bar_widget);
             carousel->slot_addItem(ptr_new_data_bar_widget,"");
            }

        else
            {
            qDebug() << "Attempted to add BarChartSingleBars that don't even have define x axis labels. This should not happen.\n";
            }
        }

    m_vector_source_usage_totals.resize(m_uint_number_of_bars);
    }

void SlidingBarChart::set_selected_source(const SourcesEnum enum_selected_source)
    {
    // Only continue if the source has been changed

    if (enum_selected_source != m_enum_selected_source)
        {
        // Check to see if the first source bar is visible. If it is, it means that a fadeout is needed first to
        // change to the newly selected source

        const bool bool_source_bar_previously_drawn = ((m_vector_data_bar_widgets.size() > 0) &&
                                                       (m_vector_data_bar_widgets[0]->m_ptr_secondary_level_source_bar_container->isVisible()));

        m_enum_selected_source = enum_selected_source;

        /*
        qDebug() << "Selected data source changed to "
                 << enum_selected_source
                 << " in Sliding Bar Chart with bool_source_bar_previously_drawn set to "
                 << bool_source_bar_previously_drawn
                 << " and source growth animation timer is "
                 << m_ptr_source_bar_growth_animation_timer->isActive()
                 << "\n";*/

        // We only attempt to do animations if the growth animation timer is off

//        if (!(m_ptr_source_bar_growth_animation_timer->isActive()))
            {
            // If there was a previous source bar drawn, we need to animate a fadeout,
            // otherwise we just animate the growth back in of the selected source bar

            if (bool_source_bar_previously_drawn)
                {
                animate_source_bar_fadeout();
                }

            else
                {
                set_source_sizes();

                animate_source_bar_growth();
                }
            }
        }
    }

void SlidingBarChart::set_new_y_axis_percentile_data_labels()
    {
    m_y_axis_100_percentile_data_label->setText(QString::number(m_uint_maximum_source_usage_total));
    m_y_axis_80_percentile_data_label->setText(QString::number(m_uint_maximum_source_usage_total * 80 / 100));
    m_y_axis_60_percentile_data_label->setText(QString::number(m_uint_maximum_source_usage_total * 60 / 100));
    m_y_axis_40_percentile_data_label->setText(QString::number(m_uint_maximum_source_usage_total * 40 / 100));
    m_y_axis_20_percentile_data_label->setText(QString::number(m_uint_maximum_source_usage_total * 20 / 100));
    m_y_axis_0_percentile_data_label->setText(QString::number(0));
    }

void SlidingBarChart::set_source_usage_totals(const std::vector<VectorOfUsageDataForOtherAndSpecificSources> &vector_vector_source_usages)
    {
    //qDebug() << "Setting source usage totals in Sliding Bar Chart\n";

    // Ensure that the data coming in has exactly the right amount to match up to the number of bars desired

    if (vector_vector_source_usages.size() == m_uint_number_of_bars)
        {
        //qDebug() << "Setting source usage totals in Sliding Bar Chart - Sizes of data vectors match\n";

        m_vector_vector_source_usages = vector_vector_source_usages;

        recalculate_source_usage_totals_per_bar_and_maximum();

        set_new_y_axis_percentile_data_labels();

        // Set the heights of each of the vertical bars (each of which is actually 2 bars)

        set_non_source_sizes();
        }
    }

void SlidingBarChart::recalculate_source_usage_totals_per_bar_and_maximum()
    {
    m_uint_maximum_source_usage_total = 0;

    // Iterate over all the source usage vectors for each bar and get totals and put them into the totals vector

    for (std::vector<VectorOfUsageDataForOtherAndSpecificSources>::const_iterator iterator_vector_of_usages_per_source = m_vector_vector_source_usages.begin();
         iterator_vector_of_usages_per_source != m_vector_vector_source_usages.end();
         iterator_vector_of_usages_per_source++)
        {
        // Ensure there are 5 sources total

        if (iterator_vector_of_usages_per_source->size() == 5)
            {
            const unsigned int uint_total_usage_for_current_vector = (*iterator_vector_of_usages_per_source)[0] +
                                                                     (*iterator_vector_of_usages_per_source)[1] +
                                                                     (*iterator_vector_of_usages_per_source)[2] +
                                                                     (*iterator_vector_of_usages_per_source)[3] +
                                                                     (*iterator_vector_of_usages_per_source)[4];

            m_vector_source_usage_totals[iterator_vector_of_usages_per_source - m_vector_vector_source_usages.begin()] = uint_total_usage_for_current_vector;

            m_uint_maximum_source_usage_total = (m_uint_maximum_source_usage_total > uint_total_usage_for_current_vector ? m_uint_maximum_source_usage_total
                                                                                                                         : uint_total_usage_for_current_vector);
            }

        else
            {
            //qDebug() << "WIERD -- recalculate_source_usage_totals_per_bar\n";
            }
        }

    // Adjust the maximum source usage total to be a multiple of 5, for the purposes of better usability for the y axis data labels.

    m_uint_maximum_source_usage_total = ((m_uint_maximum_source_usage_total % 5) != 0) ? (m_uint_maximum_source_usage_total + (5 - (m_uint_maximum_source_usage_total % 5)))
                                                                                       : m_uint_maximum_source_usage_total;
    }

void SlidingBarChart::set_object_opacity(QWidget &qwidget_target,
                                         const double double_new_opacity)
    {
    QGraphicsOpacityEffect *const ptr_opacity_effect = new QGraphicsOpacityEffect;

    ptr_opacity_effect->setOpacity(double_new_opacity);

    qwidget_target.setGraphicsEffect(ptr_opacity_effect);
    }

void SlidingBarChart::set_source_sizes()
    {
    //qDebug() << "Inside set_source_sizes()\n";

    if (m_vector_vector_source_usages.size() == m_vector_data_bar_widgets.size())
        {
        m_vector_source_data_bar_animated_destination_sizes.clear();
        m_vector_source_data_bar_animated_destination_sizes.resize(m_vector_vector_source_usages.size());

        // Iterate over all the source usage vectors for each bar

        for (std::vector<VectorOfUsageDataForOtherAndSpecificSources>::const_iterator iterator_vector_of_usages_per_source = m_vector_vector_source_usages.begin();
             iterator_vector_of_usages_per_source != m_vector_vector_source_usages.end();
             iterator_vector_of_usages_per_source++)
            {
            const unsigned int uint_current_bar_index = iterator_vector_of_usages_per_source - m_vector_vector_source_usages.begin();
            const unsigned int uint_current_bar_total_height = m_vector_source_usage_totals[uint_current_bar_index] * VERTICAL_DATA_BAR_MAXIMUM_HEIGHT_PIXELS / m_uint_maximum_source_usage_total;

            // If a source is selected, we set the height of source bar to its respective value

            if (m_enum_selected_source != SOURCE_NONE)
                {
//                qDebug() << "Current bar's total is " << m_vector_source_usage_totals[uint_current_bar_index] << " and current source's usage is: " << (*iterator_vector_of_usages_per_source)[m_enum_selected_source] << "\n";

                // The height of the source bar container should always be exactly the same as the total bar itself. Within that container we set the sizes
                // of the spacer and the actual source bar itself to be appropriate.

                m_vector_data_bar_widgets[uint_current_bar_index]->m_ptr_secondary_level_source_bar_container->show();
                m_vector_data_bar_widgets[uint_current_bar_index]->m_ptr_secondary_level_source_bar_container->setMinimumHeight(uint_current_bar_total_height);
                m_vector_data_bar_widgets[uint_current_bar_index]->m_ptr_secondary_level_source_bar_container->setMaximumHeight(uint_current_bar_total_height);
                m_vector_data_bar_widgets[uint_current_bar_index]->m_ptr_secondary_level_source_bar_container->move(0,
                                                                                                                    0);

                // We need to calculate the height of the selected source bar first. It is a percentage of the total usage for the current bar..

                const unsigned int uint_selected_source_bar_height = (*iterator_vector_of_usages_per_source)[m_enum_selected_source] * uint_current_bar_total_height / m_vector_source_usage_totals[uint_current_bar_index];
                m_vector_source_data_bar_animated_destination_sizes[uint_current_bar_index] = uint_selected_source_bar_height; // c, in pixels, for each source bar

                m_vector_data_bar_widgets[uint_current_bar_index]->m_ptr_secondary_level_header_spacer->setMinimumHeight(0);
                m_vector_data_bar_widgets[uint_current_bar_index]->m_ptr_secondary_level_header_spacer->setMaximumHeight(0);

                m_vector_data_bar_widgets[uint_current_bar_index]->m_selected_source_percentage_bar_label->setMinimumHeight(0);
                m_vector_data_bar_widgets[uint_current_bar_index]->m_selected_source_percentage_bar_label->setMaximumHeight(0);

                // Ensure the source bar is fully visible

                set_object_opacity(*(m_vector_data_bar_widgets[uint_current_bar_index]->m_selected_source_percentage_bar_label),
                                   SLIDING_BAR_CHART_FADEOUT_STARTING_OPACITY);

//                qDebug() << "Source bar #" << uint_current_bar_index << " geometry is " << m_vector_data_bar_widgets[uint_current_bar_index]->m_selected_source_percentage_bar_label->geometry() << " and usage height is " << uint_selected_source_bar_height << " and total height is " << uint_current_bar_total_height << "\n";

                // Set the color of the current source bar

                switch(m_enum_selected_source)
                    {
                    case SOURCE_1:
                        {
                        m_vector_data_bar_widgets[uint_current_bar_index]->m_selected_source_percentage_bar_label->setObjectName(QString::fromUtf8("lblSource2Selected"));
                        }
                    break;

                    case SOURCE_2:
                        {
                        m_vector_data_bar_widgets[uint_current_bar_index]->m_selected_source_percentage_bar_label->setObjectName(QString::fromUtf8("m_selected_source_percentage_bar_label"));
                        }
                    break;

                    case SOURCE_3:
                        {
                        m_vector_data_bar_widgets[uint_current_bar_index]->m_selected_source_percentage_bar_label->setObjectName(QString::fromUtf8("lblSource3Selected"));
                        }
                    break;

                    case SOURCE_4:
                        {
                        m_vector_data_bar_widgets[uint_current_bar_index]->m_selected_source_percentage_bar_label->setObjectName(QString::fromUtf8("lblSource4Selected"));
                        }
                    break;
                    }
                }

            else
                {
                m_vector_data_bar_widgets[uint_current_bar_index]->m_ptr_secondary_level_source_bar_container->hide();
                }
            }
        }

    setAppStyle();
    }

void SlidingBarChart::set_non_source_sizes()
    {
    //qDebug() << "Inside set_non_source_sizes()\n";

    if (m_vector_vector_source_usages.size() == m_vector_data_bar_widgets.size())
        {
        m_vector_total_data_bar_animated_destination_sizes.clear();
        m_vector_total_data_bar_animated_destination_sizes.resize(m_vector_vector_source_usages.size());

        // Iterate over all the source usage vectors for each bar

        for (std::vector<VectorOfUsageDataForOtherAndSpecificSources>::const_iterator iterator_vector_of_usages_per_source = m_vector_vector_source_usages.begin();
             iterator_vector_of_usages_per_source != m_vector_vector_source_usages.end();
             iterator_vector_of_usages_per_source++)
            {
            const unsigned int uint_current_bar_index = iterator_vector_of_usages_per_source - m_vector_vector_source_usages.begin();

            m_vector_data_bar_widgets[uint_current_bar_index]->setMinimumHeight(VERTICAL_DATA_BAR_MAXIMUM_HEIGHT_PIXELS + VERTICAL_DATA_BAR_TIME_LABEL_HEIGHT_PIXELS);
            m_vector_data_bar_widgets[uint_current_bar_index]->setMaximumHeight(VERTICAL_DATA_BAR_MAXIMUM_HEIGHT_PIXELS + VERTICAL_DATA_BAR_TIME_LABEL_HEIGHT_PIXELS);

            m_vector_data_bar_widgets[uint_current_bar_index]->m_time_label->setMinimumHeight(VERTICAL_DATA_BAR_TIME_LABEL_HEIGHT_PIXELS);
            m_vector_data_bar_widgets[uint_current_bar_index]->m_time_label->setMaximumHeight(VERTICAL_DATA_BAR_TIME_LABEL_HEIGHT_PIXELS);

            // Calculate the total height of the current bar. That height is the proportion of the current bar's total with respect to the highest total for all bars

            const unsigned int uint_current_bar_total_height = m_vector_source_usage_totals[uint_current_bar_index] * VERTICAL_DATA_BAR_MAXIMUM_HEIGHT_PIXELS / m_uint_maximum_source_usage_total;

            m_vector_total_data_bar_animated_destination_sizes[uint_current_bar_index] = uint_current_bar_total_height; // c, in pixels, for each total bar

            m_vector_data_bar_widgets[uint_current_bar_index]->m_ptr_secondary_level_source_bar_container->hide();
            }
        }

    animate_total_bar_growth();
    }

void SlidingBarChart::setAppStyle()
    {
    QFile file(":/styles.qss");
    file.open(QFile::ReadOnly);
    setStyleSheet(file.readAll());
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

void SlidingBarChart::animate_total_bar_growth()
    {
    //qDebug() << "Inside animate_total_bar_growth()\n";

    m_ptr_total_bar_growth_animation_timer->stop();
    m_ptr_source_bar_growth_animation_timer->stop();

    // c is provided in the array m_vector_total_data_bar_animated_destination_sizes, defining the desired total height of each total bar

    m_uint_total_bar_growth_animation_start_size = 0; // b, in pixels. All total bars start at zero and grow from there
    m_uint_total_bar_growth_total_frames = SLIDING_BAR_CHART_ANIMATION_NUMBER_OF_FRAMES; // d, in frames
    m_uint_total_bar_growth_current_frame_count = 0; // t, in frames

    // Start the timer so animation can proceed.

    m_ptr_total_bar_growth_animation_timer->start(SLIDING_BAR_CHART_ANIMATION_FRAME_PERIOD_MILLISECONDS);
    }

void SlidingBarChart::on_total_bar_growth_animation_timer_update()
    {
    m_uint_total_bar_growth_current_frame_count++;

    if (m_uint_total_bar_growth_current_frame_count <= SLIDING_BAR_CHART_ANIMATION_NUMBER_OF_FRAMES)
        {
        double base_t = m_uint_total_bar_growth_current_frame_count;

        base_t /= (m_uint_total_bar_growth_total_frames * 1.0 /2);

        // Loop over all the total bars and animate them

        for (std::vector<unsigned int>::const_iterator iterator_current_total_bar_destination_size = m_vector_total_data_bar_animated_destination_sizes.begin();
             iterator_current_total_bar_destination_size != m_vector_total_data_bar_animated_destination_sizes.end();
             iterator_current_total_bar_destination_size++)
            {
            double t = base_t;

            const unsigned int uint_current_bar_index = iterator_current_total_bar_destination_size - m_vector_total_data_bar_animated_destination_sizes.begin();

            double double_new_animation_height_of_bar;

            if (t < 1.0)
                {
                double_new_animation_height_of_bar = (int(*iterator_current_total_bar_destination_size)) * 1.0 / 2.0 * t * t + (int(m_uint_total_bar_growth_animation_start_size) * 1.0);
                }

            else
                {
                t = t - 1.0;

                double_new_animation_height_of_bar = (-(int(*iterator_current_total_bar_destination_size)) * 1.0) / 2.0 * (t * (t - 2.0) - 1.0) + (int(m_uint_total_bar_growth_animation_start_size) * 1.0);
                }

            unsigned int int_new_bar_height = round(double_new_animation_height_of_bar);

            /*
            qDebug() << "Animating with new animation size of " << int_new_bar_height << " and "
                     << " float value of " << double_new_animation_height_of_bar << " and "
                     << "current frame count (t) of " << m_uint_current_frame_count << " for bar #" << uint_current_bar_index
                     << " that has a target height of " << (*iterator_current_total_bar_destination_size)
                     << " and total frames is supposed to be " << SLIDING_BAR_CHART_ANIMATION_NUMBER_OF_FRAMES << "\n";
                     */

            // Set the size of the top level spacer on top.

            m_vector_data_bar_widgets[uint_current_bar_index]->m_ptr_top_level_header_spacer->setMinimumHeight(VERTICAL_DATA_BAR_MAXIMUM_HEIGHT_PIXELS - int_new_bar_height);
            m_vector_data_bar_widgets[uint_current_bar_index]->m_ptr_top_level_header_spacer->setMaximumHeight(VERTICAL_DATA_BAR_MAXIMUM_HEIGHT_PIXELS - int_new_bar_height);

            // Set the size of the top level container (below the top level spacer).

            m_vector_data_bar_widgets[uint_current_bar_index]->m_ptr_top_level_bar_container->setMinimumHeight(int_new_bar_height);
            m_vector_data_bar_widgets[uint_current_bar_index]->m_ptr_top_level_bar_container->setMaximumHeight(int_new_bar_height);

            // The height of the remainder bar is the total bar itself.

            m_vector_data_bar_widgets[uint_current_bar_index]->m_remainder_percentage_bar_label->setMinimumHeight(int_new_bar_height);
            m_vector_data_bar_widgets[uint_current_bar_index]->m_remainder_percentage_bar_label->setMaximumHeight(int_new_bar_height);
            m_vector_data_bar_widgets[uint_current_bar_index]->m_remainder_percentage_bar_label->move(0,
                                                                                                      0);
            }
        }

    else
        {
        //qDebug() << "Stopping total bars animation\n";

        m_ptr_total_bar_growth_animation_timer->stop();

        emit total_bars_growth_animation_done();

        set_source_sizes();

        animate_source_bar_growth();
        }
    }

void SlidingBarChart::animate_source_bar_growth()
    {
//    qDebug() << "Inside animate_source_bar_growth()\n";

    m_ptr_source_bar_growth_animation_timer->stop();

    // c is provided in the array m_vector_source_data_bar_animated_destination_sizes, defining the desired total height of each source bar

    m_uint_source_bar_growth_animation_start_size = 0; // b, in pixels. All source bars start at zero and grow from there
    m_uint_source_bar_growth_total_frames = SLIDING_BAR_CHART_SOURCE_ANIMATION_NUMBER_OF_FRAMES; // d, in frames
    m_uint_source_bar_growth_current_frame_count = 0; // t, in frames

    // Start the timer so animation can proceed.

    m_ptr_source_bar_growth_animation_timer->start(SLIDING_BAR_CHART_SOURCE_ANIMATION_FRAME_PERIOD_MILLISECONDS);
    }

void SlidingBarChart::on_source_bar_growth_animation_timer_update()
    {
    m_uint_source_bar_growth_current_frame_count++;

    if (m_uint_source_bar_growth_current_frame_count <= SLIDING_BAR_CHART_SOURCE_ANIMATION_NUMBER_OF_FRAMES)
        {
        double base_t = m_uint_source_bar_growth_current_frame_count;

        base_t /= (m_uint_source_bar_growth_total_frames * 1.0 /2);

        // Loop over all the source bars and animate them

        for (std::vector<unsigned int>::const_iterator iterator_current_source_bar_destination_size = m_vector_source_data_bar_animated_destination_sizes.begin();
             iterator_current_source_bar_destination_size != m_vector_source_data_bar_animated_destination_sizes.end();
             iterator_current_source_bar_destination_size++)
            {
            double t = base_t;

            const unsigned int uint_current_bar_index = iterator_current_source_bar_destination_size - m_vector_source_data_bar_animated_destination_sizes.begin();

            double double_new_animation_height_of_bar;

            if (t < 1.0)
                {
                double_new_animation_height_of_bar = (int(*iterator_current_source_bar_destination_size)) * 1.0 / 2.0 * t * t + (int(m_uint_source_bar_growth_animation_start_size) * 1.0);
                }

            else
                {
                t = t - 1.0;

                double_new_animation_height_of_bar = (-(int(*iterator_current_source_bar_destination_size)) * 1.0) / 2.0 * (t * (t - 2.0) - 1.0) + (int(m_uint_source_bar_growth_animation_start_size) * 1.0);
                }

            unsigned int int_new_bar_height = round(double_new_animation_height_of_bar);

            /*
            qDebug() << "Animating with new animation size of " << int_new_bar_height << " and "
                     << " float value of " << double_new_animation_height_of_bar << " and "
                     << "current frame count (t) of " << m_uint_current_frame_count << " for bar #" << uint_current_bar_index
                     << " that has a target height of " << (*iterator_current_total_bar_destination_size)
                     << " and total frames is supposed to be " << SLIDING_BAR_CHART_ANIMATION_NUMBER_OF_FRAMES << "\n";
                     */

            m_vector_data_bar_widgets[uint_current_bar_index]->m_ptr_secondary_level_header_spacer->setMinimumHeight(m_vector_data_bar_widgets[uint_current_bar_index]->m_ptr_secondary_level_source_bar_container->height() - int_new_bar_height);
            m_vector_data_bar_widgets[uint_current_bar_index]->m_ptr_secondary_level_header_spacer->setMaximumHeight(m_vector_data_bar_widgets[uint_current_bar_index]->m_ptr_secondary_level_source_bar_container->height() - int_new_bar_height);

            m_vector_data_bar_widgets[uint_current_bar_index]->m_selected_source_percentage_bar_label->setMinimumHeight(int_new_bar_height + 10);
            m_vector_data_bar_widgets[uint_current_bar_index]->m_selected_source_percentage_bar_label->setMaximumHeight(int_new_bar_height + 10);
            }
        }

    else
        {
        //qDebug() << "Stopping source bars animation\n";

        m_ptr_source_bar_growth_animation_timer->stop();

        emit source_bars_growth_animation_done();
        }
    }

void SlidingBarChart::animate_source_bar_fadeout()
    {
//    qDebug() << "Inside animate_source_bar_fadeout() -- starting fadeout\n";

    m_ptr_source_bar_fadeout_animation_timer->stop();

    // c is always -1, defining that all source bars should have opacity that changed by -1.0 by the end of the fadeout.
    // b is always 1, defining that all source bars should have opacity 1.0 at the start of the fadeout.

    m_uint_source_bar_fadeout_total_frames = SLIDING_BAR_CHART_FADEOUT_NUMBER_OF_FRAMES; // d, in frames
    m_uint_source_bar_fadeout_current_frame_count = 0; // t, in frames

    // Start the timer so animation can proceed.

    m_ptr_source_bar_fadeout_animation_timer->start(SLIDING_BAR_CHART_FADEOUT_FRAME_PERIOD_MILLISECONDS);
    }

void SlidingBarChart::on_source_bar_fadeout_animation_timer_update()
    {
    m_uint_source_bar_fadeout_current_frame_count++;

    if (m_uint_source_bar_fadeout_current_frame_count <= SLIDING_BAR_CHART_FADEOUT_NUMBER_OF_FRAMES)
        {
        double base_t = m_uint_source_bar_fadeout_current_frame_count;

        base_t /= (m_uint_source_bar_fadeout_total_frames * 1.0 /2);

        double t = base_t;
        double double_new_opacity_of_bar;

        if (t < 1.0)
            {
            double_new_opacity_of_bar = (SLIDING_BAR_CHART_FADEOUT_DELTA_OPACITY) * 1.0 / 2.0 * t * t + (SLIDING_BAR_CHART_FADEOUT_STARTING_OPACITY * 1.0);
            }

        else
            {
            t = t - 1.0;

            double_new_opacity_of_bar = ((-(SLIDING_BAR_CHART_FADEOUT_DELTA_OPACITY)) * 1.0) / 2.0 * (t * (t - 2.0) - 1.0) + (SLIDING_BAR_CHART_FADEOUT_STARTING_OPACITY * 1.0);
            }

//        qDebug() << "Fading out with opacity " << double_new_opacity_of_bar << "\n";

        // Loop over all the source bars and fade then out

        for (std::vector<BarChartSingleBar *>::iterator iterator_current_source_bar = m_vector_data_bar_widgets.begin();
             iterator_current_source_bar != m_vector_data_bar_widgets.end();
             iterator_current_source_bar++)
            {
            const unsigned int uint_current_bar_index = iterator_current_source_bar - m_vector_data_bar_widgets.begin();

            set_object_opacity(*((*(iterator_current_source_bar))->m_selected_source_percentage_bar_label),
                               double_new_opacity_of_bar);
            }
        }

    else
        {
//        qDebug() << "Stopping source bar fadeout\n";

        m_ptr_source_bar_fadeout_animation_timer->stop();

        emit source_bars_fadeout_done();

        set_source_sizes();

        animate_source_bar_growth();
        }
    }
