#include <QDebug>
#include "InteractiveSegmentedBar.h"

InteractiveSegmentedBar::InteractiveSegmentedBar(const QString &qst_source_1_name,
                                                 const QString &qst_source_2_name,
                                                 const QString &qst_source_3_name,
                                                 const QString &qst_source_4_name,
                                                 QWidget *parent)
                        :QWidget(parent),
                         m_qst_source_1_name(qst_source_1_name),
                         m_qst_source_2_name(qst_source_2_name),
                         m_qst_source_3_name(qst_source_3_name),
                         m_qst_source_4_name(qst_source_4_name),
                         m_uint_source_1_usage(0),
                         m_uint_source_2_usage(0),
                         m_uint_source_3_usage(0),
                         m_uint_source_4_usage(0),
                         m_uint_other_usage(0)
    {
    setupUi(this);

    m_ptr_arrow_slider->setMinimum(0);
    m_ptr_arrow_slider->setMaximum(SEGMENTED_BAR_SLIDER_RANGE);

    connect(m_ptr_arrow_slider,
            SIGNAL(sliderReleased()),
            this,
            SLOT(on_slider_released()));

    connect(m_ptr_arrow_slider,
            SIGNAL(valueChanged(int)),
            this,
            SLOT(on_slider_value_changed(int)));

    connect(m_ptr_src_1_bar,
            SIGNAL(clicked(bool)),
            this,
            SLOT(on_source_1_selected()));

    connect(m_ptr_src_2_bar,
            SIGNAL(clicked(bool)),
            this,
            SLOT(on_source_2_selected()));

    connect(m_ptr_src_3_bar,
            SIGNAL(clicked(bool)),
            this,
            SLOT(on_source_3_selected()));

    connect(m_ptr_src_4_bar,
            SIGNAL(clicked(bool)),
            this,
            SLOT(on_source_4_selected()));

    connect(m_ptr_other_bar,
            SIGNAL(clicked(bool)),
            this,
            SLOT(on_other_selected()));
    }

void InteractiveSegmentedBar::set_source(const SourcesEnum enum_new_source)
    {
    switch(enum_new_source)
        {
        case SOURCE_1:
            {
            on_source_1_selected();
            }
        break;

        case SOURCE_2:
            {
            on_source_2_selected();
            }
        break;

        case SOURCE_3:
            {
            on_source_3_selected();
            }
        break;

        case SOURCE_4:
            {
            on_source_4_selected();
            }
        break;

        case SOURCE_OTHER:
            {
            on_other_selected();
            }
        break;
        }
    }

void InteractiveSegmentedBar::on_slider_released()
    {
//   qDebug () << "on_slider_released() called\n";
//   qDebug ()  << m_ptr_arrow_slider->value();
//   qDebug () << "Slider max : " <<  m_ptr_arrow_slider ->maximum();
     on_snap_slider();
    }

void InteractiveSegmentedBar::on_source_1_selected()
    {
//    qDebug() << "Source 1 selected\n";

    emit signal_new_source_selected(SOURCE_1);

    m_ptr_src_1_bar->setChecked(true);

    // Calculate the new location of the arrow selected on the qslider, and move the arrow there (a snap to the center of the selected bar)

    const unsigned int uint_new_qslider_value = int((m_ptr_src_1_bar->width() / 2));
//    qDebug() << "Setting value of slider to " << uint_new_qslider_value << "\n";

//    qDebug() << "Data Max value is  " << m_ptr_src_1_bar->width()+m_ptr_src_2_bar->width()+m_ptr_src_3_bar->width()+m_ptr_src_4_bar->width()+m_ptr_other_bar->width() << "\n";

    m_ptr_arrow_slider->setValue(uint_new_qslider_value );

    // Calculate the location of the arrow pointer, and move bubble accordingly to be over that location

    QRect qrect_bubble_frame_rectangle = m_ptr_bubble_frame->rect();
   /*  qrect_bubble_frame_rectangle.moveCenter(QPoint(int((uint_new_qslider_value * 1.0 / m_ptr_arrow_slider->maximum()) * m_ptr_arrow_slider->width()) + m_ptr_arrow_slider->x(),
                                                   m_ptr_bubble_frame->geometry().center().y()));
                                                   */

    qrect_bubble_frame_rectangle.moveCenter(QPoint(uint_new_qslider_value + 80,
                                                   m_ptr_bubble_frame->geometry().center().y()));

    m_ptr_bubble_frame->setGeometry(qrect_bubble_frame_rectangle);

    m_ptr_bubble_source_text_label->setText(m_qst_source_1_name);
    m_ptr_bubble_usage_text_label->setText(QString::number(m_uint_source_1_usage));
    }

void InteractiveSegmentedBar::on_source_2_selected()
    {
//    qDebug() << "Source 2 selected\n";

    emit signal_new_source_selected(SOURCE_2);

    m_ptr_src_2_bar->setChecked(true);

    // Calculate the new location of the arrow selected on the qslider, and move the arrow there (a snap to the center of the selected bar)

    const unsigned int uint_new_qslider_value = int((m_ptr_src_1_bar->width() + m_ptr_src_2_bar->width()/2)  );

//    qDebug() << "Setting value of slider to " << uint_new_qslider_value << "\n";

      m_ptr_arrow_slider->setValue(uint_new_qslider_value );

    // Calculate the location of the arrow pointer, and move bubble accordingly to be over that location

    QRect qrect_bubble_frame_rectangle = m_ptr_bubble_frame->rect();
/*    qrect_bubble_frame_rectangle.moveCenter(QPoint(int((uint_new_qslider_value * 1.0 / m_ptr_arrow_slider->maximum()) * m_ptr_arrow_slider->width()) + m_ptr_arrow_slider->x(),
                                                   m_ptr_bubble_frame->geometry().center().y()));
  */
    qrect_bubble_frame_rectangle.moveCenter(QPoint(uint_new_qslider_value + 80,
                                                   m_ptr_bubble_frame->geometry().center().y()));

    m_ptr_bubble_frame->setGeometry(qrect_bubble_frame_rectangle);

    m_ptr_bubble_source_text_label->setText(m_qst_source_2_name);
    m_ptr_bubble_usage_text_label->setText(QString::number(m_uint_source_2_usage));
    }

void InteractiveSegmentedBar::on_source_3_selected()
    {
//    qDebug() << "Source 3 selected\n";

    emit signal_new_source_selected(SOURCE_3);

    m_ptr_src_3_bar->setChecked(true);

    // Calculate the new location of the arrow selected on the qslider, and move the arrow there (a snap to the center of the selected bar)

    const unsigned int uint_new_qslider_value = int((m_ptr_src_1_bar->width() + m_ptr_src_2_bar->width() + m_ptr_src_3_bar->width()/2));

//    qDebug() << "Setting value of slider to " << uint_new_qslider_value << "\n";

    m_ptr_arrow_slider->setValue(uint_new_qslider_value );
    // Calculate the location of the arrow pointer, and move bubble accordingly to be over that location

    QRect qrect_bubble_frame_rectangle = m_ptr_bubble_frame->rect();
  /*  qrect_bubble_frame_rectangle.moveCenter(QPoint(int((uint_new_qslider_value * 1.0 / m_ptr_arrow_slider->maximum()) * m_ptr_arrow_slider->width()) + m_ptr_arrow_slider->x(),
                                                   m_ptr_bubble_frame->geometry().center().y()));
 */
    qrect_bubble_frame_rectangle.moveCenter(QPoint(uint_new_qslider_value + 80,
                                                   m_ptr_bubble_frame->geometry().center().y()));

    m_ptr_bubble_frame->setGeometry(qrect_bubble_frame_rectangle);

    m_ptr_bubble_source_text_label->setText(m_qst_source_3_name);
    m_ptr_bubble_usage_text_label->setText(QString::number(m_uint_source_3_usage));
    }

void InteractiveSegmentedBar::on_source_4_selected()
    {
//    qDebug() << "Source 4 selected\n";

    emit signal_new_source_selected(SOURCE_4);

    m_ptr_src_4_bar->setChecked(true);

    // Calculate the new location of the arrow selected on the qslider, and move the arrow there (a snap to the center of the selected bar)

    const unsigned int uint_new_qslider_value = int((m_ptr_src_1_bar->width() + m_ptr_src_2_bar->width() + m_ptr_src_3_bar->width() + m_ptr_src_4_bar->width()/2));

//    qDebug() << "Setting value of slider to " << uint_new_qslider_value << "\n";

   m_ptr_arrow_slider->setValue(uint_new_qslider_value );

    // Calculate the location of the arrow pointer, and move bubble accordingly to be over that location

    QRect qrect_bubble_frame_rectangle = m_ptr_bubble_frame->rect();
    /* qrect_bubble_frame_rectangle.moveCenter(QPoint(int((uint_new_qslider_value * 1.0 / m_ptr_arrow_slider->maximum()) * m_ptr_arrow_slider->width()) + m_ptr_arrow_slider->x(),
                                                   m_ptr_bubble_frame->geometry().center().y()));
*/
    qrect_bubble_frame_rectangle.moveCenter(QPoint(uint_new_qslider_value + 80,
                                                   m_ptr_bubble_frame->geometry().center().y()));


    m_ptr_bubble_frame->setGeometry(qrect_bubble_frame_rectangle);

    m_ptr_bubble_source_text_label->setText(m_qst_source_4_name);
    m_ptr_bubble_usage_text_label->setText(QString::number(m_uint_source_4_usage));
    }

void InteractiveSegmentedBar::on_other_selected()
    {
//    qDebug() << "Other selected\n";

    emit signal_new_source_selected(SOURCE_OTHER);

    m_ptr_other_bar->setChecked(true);

    // Calculate the new location of the arrow selected on the qslider, and move the arrow there (a snap to the center of the selected bar)

    const unsigned int uint_new_qslider_value = int((m_ptr_src_1_bar->width() + m_ptr_src_2_bar->width() + m_ptr_src_3_bar->width() + m_ptr_src_4_bar->width() + m_ptr_other_bar->width() /2));


//     const unsigned int uint_new_qslider_value = int((m_uint_source_1_usage + m_uint_source_2_usage + m_uint_source_3_usage + m_uint_source_4_usage + m_uint_other_usage / 2) * 1.0 / m_uint_total_usage * m_ptr_arrow_slider->maximum());

//    qDebug() << "Setting value of slider to " << uint_new_qslider_value << "\n";

    m_ptr_arrow_slider->setValue(uint_new_qslider_value);

    // Calculate the location of the arrow pointer, and move bubble accordingly to be over that location

    QRect qrect_bubble_frame_rectangle = m_ptr_bubble_frame->rect();
/*     qrect_bubble_frame_rectangle.moveCenter(QPoint(int((uint_new_qslider_value * 1.0 / m_ptr_arrow_slider->maximum()) * m_ptr_arrow_slider->width()) + m_ptr_arrow_slider->x(),
                                                   m_ptr_bubble_frame->geometry().center().y()));
 */
    qrect_bubble_frame_rectangle.moveCenter(QPoint(uint_new_qslider_value + 80,
                                                   m_ptr_bubble_frame->geometry().center().y()));


    m_ptr_bubble_frame->setGeometry(qrect_bubble_frame_rectangle);

    m_ptr_bubble_source_text_label->setText(VIEW_2_OTHER_SOURCES_LABEL);
    m_ptr_bubble_usage_text_label->setText(QString::number(m_uint_other_usage));
    }

void InteractiveSegmentedBar::reselect_selected_source()
    {
    if (m_ptr_src_1_bar->isChecked())
        {
        on_source_1_selected();
        }

    else if (m_ptr_src_2_bar->isChecked())
        {
        on_source_2_selected();
        }

    else if (m_ptr_src_3_bar->isChecked())
        {
        on_source_3_selected();
        }

    else if (m_ptr_src_4_bar->isChecked())
        {
        on_source_4_selected();
        }

    else if (m_ptr_other_bar->isChecked())
        {
        on_other_selected();
        }

    else
        {
        m_ptr_bubble_frame->hide();

        m_ptr_origin_help_text_bubble->show();
        }
    }

void InteractiveSegmentedBar::on_snap_slider()
    {
//    qDebug() << "In on_snap_slider() where arrow slider value is " << m_ptr_arrow_slider->value() << "\n";

    // Now, we interpolate within the width of the entire segmented bar frame (the middle part) which
    // source area the arrow was stopped within. We do this simply by seeing how much of the total usage
    // for the selected time period is actually represented by the arrow stop position, relative to the
    // maximum arrow stop position. With this usage, we can calculate in which source's range does this fall
    // into.

    const unsigned int uint_arrow_stop_position_as_usage = int(m_ptr_arrow_slider->value() * 1.0 / m_ptr_arrow_slider->maximum() * m_uint_total_usage);

    m_ptr_bubble_frame->show();

    m_ptr_origin_help_text_bubble->hide();

    /*
    qDebug() << "Slider was released. Value is now " << m_ptr_arrow_slider->value()
             << " and width of segmented bar is " << m_ptr_segmented_bar_frame->width()
             << " and interpolated position of arrow stop position relative to this segmented bar is " << uint_interpolated_segmented_bar_frame_arrow_stop_position
             << "\n";
*/

    // Now, we figure out within which of the 5 sources was selected.

    if (uint_arrow_stop_position_as_usage < m_uint_source_1_usage)
        {
        on_source_1_selected();
        }

    else if (uint_arrow_stop_position_as_usage < m_uint_source_1_usage + m_uint_source_2_usage)
        {
        on_source_2_selected();
        }

    else if (uint_arrow_stop_position_as_usage < m_uint_source_1_usage + m_uint_source_2_usage + m_uint_source_3_usage)
        {
        on_source_3_selected();
        }

    else if (uint_arrow_stop_position_as_usage < m_uint_source_1_usage + m_uint_source_2_usage + m_uint_source_3_usage + m_uint_source_4_usage)
        {
        on_source_4_selected();
        }

    else
        {
        on_other_selected();
        }
    }

void InteractiveSegmentedBar::on_slider_value_changed(int int_new_value)
    {
     if (!(m_ptr_arrow_slider->isSliderDown()))
        {
//        qDebug() << "Slider value was changed to " << int_new_value << "\n";

      on_snap_slider();
        }



    }

void InteractiveSegmentedBar::set_usage_per_source(const std::vector<unsigned int> &vector_usage_per_source)
    {
//    qDebug() << "In set_usage_per_source\n";

    m_vector_usage_per_source = vector_usage_per_source;

    if (m_vector_usage_per_source.size() == 5)
        {
        m_uint_source_1_usage = m_vector_usage_per_source[1];
        m_uint_source_2_usage = m_vector_usage_per_source[2];
        m_uint_source_3_usage = m_vector_usage_per_source[3];
        m_uint_source_4_usage = m_vector_usage_per_source[4];
        m_uint_other_usage = m_vector_usage_per_source[0];

        // Calculate the total usage

        m_uint_total_usage = m_vector_usage_per_source[0] +
                             m_vector_usage_per_source[1] +
                             m_vector_usage_per_source[2] +
                             m_vector_usage_per_source[3] +
                             m_vector_usage_per_source[4];

        const unsigned int uint_source_1_width = m_vector_usage_per_source[1] * 1.0 / m_uint_total_usage * m_ptr_segmented_bar_frame->width();
        m_ptr_src_1_bar->setMinimumWidth(uint_source_1_width);
        m_ptr_src_1_bar->setMaximumWidth(uint_source_1_width);
/*        qDebug() << "Resizing source 1 to be " << uint_source_1_width << " which is a percentage of "
                 << int(m_vector_usage_per_source[1] * 1.0 / uint_total_usage * 100) << "\n"
                 << m_ptr_src_1_bar->geometry() << "\n";*/

        const unsigned int uint_source_2_width = m_vector_usage_per_source[2] * 1.0 / m_uint_total_usage * m_ptr_segmented_bar_frame->width();
        m_ptr_src_2_bar->setMinimumWidth(uint_source_2_width);
        m_ptr_src_2_bar->setMaximumWidth(uint_source_2_width);
/*        qDebug() << "Resizing source 2 to be " << uint_source_2_width << " which is a percentage of "
                 << int(m_vector_usage_per_source[2] * 1.0 / uint_total_usage * 100) << "\n"
                 << m_ptr_src_2_bar->geometry() << "\n";*/

        const unsigned int uint_source_3_width = m_vector_usage_per_source[3] * 1.0 / m_uint_total_usage * m_ptr_segmented_bar_frame->width();
        m_ptr_src_3_bar->setMinimumWidth(uint_source_3_width);
        m_ptr_src_3_bar->setMaximumWidth(uint_source_3_width);
/*        qDebug() << "Resizing source 3 to be " << uint_source_3_width << " which is a percentage of "
                 << int(m_vector_usage_per_source[3] * 1.0 / uint_total_usage * 100) << "\n"
                 << m_ptr_src_3_bar->geometry() << "\n";*/

        const unsigned int uint_source_4_width = m_vector_usage_per_source[4] * 1.0 / m_uint_total_usage * m_ptr_segmented_bar_frame->width();
        m_ptr_src_4_bar->setMinimumWidth(uint_source_4_width);
        m_ptr_src_4_bar->setMaximumWidth(uint_source_4_width);
/*        qDebug() << "Resizing source 4 to be " << uint_source_4_width << " which is a percentage of "
                 << int(m_vector_usage_per_source[4] * 1.0 / uint_total_usage * 100) << "\n"
                 << m_ptr_src_4_bar->geometry() << "\n";*/

        const unsigned int uint_other_source_width = m_vector_usage_per_source[0] * 1.0 / m_uint_total_usage * m_ptr_segmented_bar_frame->width();
        m_ptr_other_bar->setMinimumWidth(uint_other_source_width);
        m_ptr_other_bar->setMaximumWidth(uint_other_source_width);
/*        qDebug() << "Resizing other source to be " << uint_other_source_width << " which is a percentage of "
                 << int(m_vector_usage_per_source[0] * 1.0 / uint_total_usage * 100) << "\n"
                 << m_ptr_other_bar->geometry() << "\n";
*/
     //   m_ptr_arrow_slider->setMaximum(m_ptr_src_1_bar->width()+m_ptr_src_2_bar->width()+m_ptr_src_3_bar->width()+m_ptr_src_4_bar->width()+m_ptr_other_bar->width());
//        qDebug()<<"total width: "<<m_ptr_src_1_bar->width()+m_ptr_src_2_bar->width()+m_ptr_src_3_bar->width()+m_ptr_src_4_bar->width()+m_ptr_other_bar->width();
        m_ptr_arrow_slider->setMaximum(m_ptr_src_1_bar->width()+m_ptr_src_2_bar->width()+m_ptr_src_3_bar->width()+m_ptr_src_4_bar->width()+m_ptr_other_bar->width() );
        m_ptr_arrow_slider->setMinimumWidth(m_ptr_src_1_bar->width()+m_ptr_src_2_bar->width()+m_ptr_src_3_bar->width()+m_ptr_src_4_bar->width()+m_ptr_other_bar->width() - (SEGMENTED_BAR_OFFSET * 2));
        m_ptr_arrow_slider->setMaximumWidth(m_ptr_src_1_bar->width()+m_ptr_src_2_bar->width()+m_ptr_src_3_bar->width()+m_ptr_src_4_bar->width()+m_ptr_other_bar->width() - (SEGMENTED_BAR_OFFSET* 2));


        reselect_selected_source();
        }
    }
