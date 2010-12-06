/********************************************************************************
** Form generated from reading UI file 'InteractiveSegmentedBar.ui'
**
** Created: Sat Dec 4 16:17:07 2010
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERACTIVESEGMENTEDBAR_H
#define UI_INTERACTIVESEGMENTEDBAR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InteractiveSegmentedBar
{
public:
    QFrame *m_ptr_bubble_frame;
    QLabel *m_ptr_bubble_usage_text_label;
    QLabel *m_ptr_bubble_source_text_label;
    QFrame *m_ptr_segmented_bar_frame;
    QWidget *layoutWidget;
    QHBoxLayout *m_ptr_segmented_bar_frame_layout;
    QRadioButton *m_ptr_src_1_bar;
    QRadioButton *m_ptr_src_2_bar;
    QRadioButton *m_ptr_src_3_bar;
    QRadioButton *m_ptr_src_4_bar;
    QRadioButton *m_ptr_other_bar;
    QSlider *m_ptr_arrow_slider;
    QLabel *m_ptr_origin_help_text_bubble;

    void setupUi(QWidget *InteractiveSegmentedBar)
    {
        if (InteractiveSegmentedBar->objectName().isEmpty())
            InteractiveSegmentedBar->setObjectName(QString::fromUtf8("InteractiveSegmentedBar"));
        InteractiveSegmentedBar->resize(699, 262);
        InteractiveSegmentedBar->setStyleSheet(QString::fromUtf8(""));
        m_ptr_bubble_frame = new QFrame(InteractiveSegmentedBar);
        m_ptr_bubble_frame->setObjectName(QString::fromUtf8("m_ptr_bubble_frame"));
        m_ptr_bubble_frame->setGeometry(QRect(190, 10, 160, 84));
        m_ptr_bubble_frame->setFrameShape(QFrame::StyledPanel);
        m_ptr_bubble_frame->setFrameShadow(QFrame::Raised);
        m_ptr_bubble_usage_text_label = new QLabel(m_ptr_bubble_frame);
        m_ptr_bubble_usage_text_label->setObjectName(QString::fromUtf8("m_ptr_bubble_usage_text_label"));
        m_ptr_bubble_usage_text_label->setGeometry(QRect(0, 38, 160, 20));
        m_ptr_bubble_usage_text_label->setAlignment(Qt::AlignCenter);
        m_ptr_bubble_source_text_label = new QLabel(m_ptr_bubble_frame);
        m_ptr_bubble_source_text_label->setObjectName(QString::fromUtf8("m_ptr_bubble_source_text_label"));
        m_ptr_bubble_source_text_label->setGeometry(QRect(0, 15, 160, 20));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(m_ptr_bubble_source_text_label->sizePolicy().hasHeightForWidth());
        m_ptr_bubble_source_text_label->setSizePolicy(sizePolicy);
        m_ptr_bubble_source_text_label->setAlignment(Qt::AlignCenter);
        m_ptr_segmented_bar_frame = new QFrame(InteractiveSegmentedBar);
        m_ptr_segmented_bar_frame->setObjectName(QString::fromUtf8("m_ptr_segmented_bar_frame"));
        m_ptr_segmented_bar_frame->setGeometry(QRect(80, 105, 440, 36));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(m_ptr_segmented_bar_frame->sizePolicy().hasHeightForWidth());
        m_ptr_segmented_bar_frame->setSizePolicy(sizePolicy1);
        m_ptr_segmented_bar_frame->setStyleSheet(QString::fromUtf8(""));
        m_ptr_segmented_bar_frame->setFrameShape(QFrame::StyledPanel);
        m_ptr_segmented_bar_frame->setFrameShadow(QFrame::Raised);
        m_ptr_segmented_bar_frame->setLineWidth(0);
        layoutWidget = new QWidget(m_ptr_segmented_bar_frame);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 521, 41));
        m_ptr_segmented_bar_frame_layout = new QHBoxLayout(layoutWidget);
        m_ptr_segmented_bar_frame_layout->setSpacing(0);
        m_ptr_segmented_bar_frame_layout->setObjectName(QString::fromUtf8("m_ptr_segmented_bar_frame_layout"));
        m_ptr_segmented_bar_frame_layout->setSizeConstraint(QLayout::SetFixedSize);
        m_ptr_segmented_bar_frame_layout->setContentsMargins(0, 0, 0, 0);
        m_ptr_src_1_bar = new QRadioButton(layoutWidget);
        m_ptr_src_1_bar->setObjectName(QString::fromUtf8("m_ptr_src_1_bar"));
        sizePolicy1.setHeightForWidth(m_ptr_src_1_bar->sizePolicy().hasHeightForWidth());
        m_ptr_src_1_bar->setSizePolicy(sizePolicy1);
        m_ptr_src_1_bar->setMinimumSize(QSize(0, 36));
        m_ptr_src_1_bar->setSizeIncrement(QSize(0, 0));
        m_ptr_src_1_bar->setStyleSheet(QString::fromUtf8(""));

        m_ptr_segmented_bar_frame_layout->addWidget(m_ptr_src_1_bar);

        m_ptr_src_2_bar = new QRadioButton(layoutWidget);
        m_ptr_src_2_bar->setObjectName(QString::fromUtf8("m_ptr_src_2_bar"));
        sizePolicy1.setHeightForWidth(m_ptr_src_2_bar->sizePolicy().hasHeightForWidth());
        m_ptr_src_2_bar->setSizePolicy(sizePolicy1);
        m_ptr_src_2_bar->setMinimumSize(QSize(0, 36));
        m_ptr_src_2_bar->setStyleSheet(QString::fromUtf8(""));

        m_ptr_segmented_bar_frame_layout->addWidget(m_ptr_src_2_bar);

        m_ptr_src_3_bar = new QRadioButton(layoutWidget);
        m_ptr_src_3_bar->setObjectName(QString::fromUtf8("m_ptr_src_3_bar"));
        sizePolicy1.setHeightForWidth(m_ptr_src_3_bar->sizePolicy().hasHeightForWidth());
        m_ptr_src_3_bar->setSizePolicy(sizePolicy1);
        m_ptr_src_3_bar->setMinimumSize(QSize(0, 36));
        m_ptr_src_3_bar->setStyleSheet(QString::fromUtf8(""));

        m_ptr_segmented_bar_frame_layout->addWidget(m_ptr_src_3_bar);

        m_ptr_src_4_bar = new QRadioButton(layoutWidget);
        m_ptr_src_4_bar->setObjectName(QString::fromUtf8("m_ptr_src_4_bar"));
        sizePolicy1.setHeightForWidth(m_ptr_src_4_bar->sizePolicy().hasHeightForWidth());
        m_ptr_src_4_bar->setSizePolicy(sizePolicy1);
        m_ptr_src_4_bar->setMinimumSize(QSize(0, 36));
        m_ptr_src_4_bar->setStyleSheet(QString::fromUtf8(""));

        m_ptr_segmented_bar_frame_layout->addWidget(m_ptr_src_4_bar);

        m_ptr_other_bar = new QRadioButton(layoutWidget);
        m_ptr_other_bar->setObjectName(QString::fromUtf8("m_ptr_other_bar"));
        m_ptr_other_bar->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(m_ptr_other_bar->sizePolicy().hasHeightForWidth());
        m_ptr_other_bar->setSizePolicy(sizePolicy2);
        m_ptr_other_bar->setMinimumSize(QSize(0, 36));
        m_ptr_other_bar->setStyleSheet(QString::fromUtf8(""));

        m_ptr_segmented_bar_frame_layout->addWidget(m_ptr_other_bar);

        m_ptr_other_bar->raise();
        m_ptr_src_4_bar->raise();
        m_ptr_src_3_bar->raise();
        m_ptr_src_2_bar->raise();
        m_ptr_src_1_bar->raise();
        m_ptr_arrow_slider = new QSlider(InteractiveSegmentedBar);
        m_ptr_arrow_slider->setObjectName(QString::fromUtf8("m_ptr_arrow_slider"));
        m_ptr_arrow_slider->setGeometry(QRect(62, 150, 440, 55));
        m_ptr_arrow_slider->setOrientation(Qt::Horizontal);
        m_ptr_arrow_slider->setTickPosition(QSlider::NoTicks);
        m_ptr_origin_help_text_bubble = new QLabel(InteractiveSegmentedBar);
        m_ptr_origin_help_text_bubble->setObjectName(QString::fromUtf8("m_ptr_origin_help_text_bubble"));
        m_ptr_origin_help_text_bubble->setGeometry(QRect(110, 150, 307, 56));
        m_ptr_origin_help_text_bubble->setStyleSheet(QString::fromUtf8(""));
        m_ptr_origin_help_text_bubble->setAlignment(Qt::AlignCenter);

        retranslateUi(InteractiveSegmentedBar);

        QMetaObject::connectSlotsByName(InteractiveSegmentedBar);
    } // setupUi

    void retranslateUi(QWidget *InteractiveSegmentedBar)
    {
        InteractiveSegmentedBar->setWindowTitle(QApplication::translate("InteractiveSegmentedBar", "Form", 0, QApplication::UnicodeUTF8));
        m_ptr_bubble_usage_text_label->setText(QApplication::translate("InteractiveSegmentedBar", "10", 0, QApplication::UnicodeUTF8));
        m_ptr_bubble_source_text_label->setText(QApplication::translate("InteractiveSegmentedBar", "Source 2", 0, QApplication::UnicodeUTF8));
        m_ptr_src_1_bar->setText(QString());
        m_ptr_src_2_bar->setText(QString());
        m_ptr_src_3_bar->setText(QString());
        m_ptr_src_4_bar->setText(QString());
        m_ptr_other_bar->setText(QString());
        m_ptr_origin_help_text_bubble->setText(QApplication::translate("InteractiveSegmentedBar", "Slide to view usage by individual source.", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class InteractiveSegmentedBar: public Ui_InteractiveSegmentedBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERACTIVESEGMENTEDBAR_H
