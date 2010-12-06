/********************************************************************************
** Form generated from reading UI file 'BarChartSingleBar.ui'
**
** Created: Sat Dec 4 16:17:07 2010
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BARCHARTSINGLEBAR_H
#define UI_BARCHARTSINGLEBAR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BarChartSingleBar
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *m_ptr_top_level_vertical_layout;
    QLabel *m_ptr_top_level_header_spacer;
    QWidget *m_ptr_top_level_bar_container;
    QLabel *m_remainder_percentage_bar_label;
    QWidget *m_ptr_secondary_level_source_bar_container;
    QWidget *layoutWidget1;
    QVBoxLayout *m_ptr_secondary_level_source_bar_vertical_layout;
    QLabel *m_ptr_secondary_level_header_spacer;
    QLabel *m_selected_source_percentage_bar_label;
    QLabel *m_time_label;

    void setupUi(QWidget *BarChartSingleBar)
    {
        if (BarChartSingleBar->objectName().isEmpty())
            BarChartSingleBar->setObjectName(QString::fromUtf8("BarChartSingleBar"));
        BarChartSingleBar->resize(196, 496);
        BarChartSingleBar->setStyleSheet(QString::fromUtf8(""));
        layoutWidget = new QWidget(BarChartSingleBar);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 86, 311));
        m_ptr_top_level_vertical_layout = new QVBoxLayout(layoutWidget);
        m_ptr_top_level_vertical_layout->setSpacing(0);
        m_ptr_top_level_vertical_layout->setObjectName(QString::fromUtf8("m_ptr_top_level_vertical_layout"));
        m_ptr_top_level_vertical_layout->setContentsMargins(0, 0, 0, 0);
        m_ptr_top_level_header_spacer = new QLabel(layoutWidget);
        m_ptr_top_level_header_spacer->setObjectName(QString::fromUtf8("m_ptr_top_level_header_spacer"));

        m_ptr_top_level_vertical_layout->addWidget(m_ptr_top_level_header_spacer);

        m_ptr_top_level_bar_container = new QWidget(layoutWidget);
        m_ptr_top_level_bar_container->setObjectName(QString::fromUtf8("m_ptr_top_level_bar_container"));
        m_ptr_top_level_bar_container->setMinimumSize(QSize(35, 0));
        m_ptr_top_level_bar_container->setMaximumSize(QSize(35, 16777215));
        m_remainder_percentage_bar_label = new QLabel(m_ptr_top_level_bar_container);
        m_remainder_percentage_bar_label->setObjectName(QString::fromUtf8("m_remainder_percentage_bar_label"));
        m_remainder_percentage_bar_label->setGeometry(QRect(0, -10, 35, 121));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(m_remainder_percentage_bar_label->sizePolicy().hasHeightForWidth());
        m_remainder_percentage_bar_label->setSizePolicy(sizePolicy);
        m_remainder_percentage_bar_label->setMinimumSize(QSize(35, 100));
        m_remainder_percentage_bar_label->setMaximumSize(QSize(35, 16777215));
        m_remainder_percentage_bar_label->setStyleSheet(QString::fromUtf8(""));
        m_remainder_percentage_bar_label->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        m_ptr_secondary_level_source_bar_container = new QWidget(m_ptr_top_level_bar_container);
        m_ptr_secondary_level_source_bar_container->setObjectName(QString::fromUtf8("m_ptr_secondary_level_source_bar_container"));
        m_ptr_secondary_level_source_bar_container->setGeometry(QRect(0, 0, 35, 121));
        m_ptr_secondary_level_source_bar_container->setMinimumSize(QSize(35, 0));
        m_ptr_secondary_level_source_bar_container->setMaximumSize(QSize(35, 16777215));
        layoutWidget1 = new QWidget(m_ptr_secondary_level_source_bar_container);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(0, -10, 81, 131));
        m_ptr_secondary_level_source_bar_vertical_layout = new QVBoxLayout(layoutWidget1);
        m_ptr_secondary_level_source_bar_vertical_layout->setObjectName(QString::fromUtf8("m_ptr_secondary_level_source_bar_vertical_layout"));
        m_ptr_secondary_level_source_bar_vertical_layout->setSizeConstraint(QLayout::SetFixedSize);
        m_ptr_secondary_level_source_bar_vertical_layout->setContentsMargins(0, 0, 0, 0);
        m_ptr_secondary_level_header_spacer = new QLabel(layoutWidget1);
        m_ptr_secondary_level_header_spacer->setObjectName(QString::fromUtf8("m_ptr_secondary_level_header_spacer"));

        m_ptr_secondary_level_source_bar_vertical_layout->addWidget(m_ptr_secondary_level_header_spacer);

        m_selected_source_percentage_bar_label = new QLabel(layoutWidget1);
        m_selected_source_percentage_bar_label->setObjectName(QString::fromUtf8("m_selected_source_percentage_bar_label"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(m_selected_source_percentage_bar_label->sizePolicy().hasHeightForWidth());
        m_selected_source_percentage_bar_label->setSizePolicy(sizePolicy1);
        m_selected_source_percentage_bar_label->setMinimumSize(QSize(35, 0));
        m_selected_source_percentage_bar_label->setMaximumSize(QSize(35, 16777215));
        m_selected_source_percentage_bar_label->setStyleSheet(QString::fromUtf8(""));
        m_selected_source_percentage_bar_label->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        m_ptr_secondary_level_source_bar_vertical_layout->addWidget(m_selected_source_percentage_bar_label);


        m_ptr_top_level_vertical_layout->addWidget(m_ptr_top_level_bar_container);

        m_time_label = new QLabel(layoutWidget);
        m_time_label->setObjectName(QString::fromUtf8("m_time_label"));
        sizePolicy.setHeightForWidth(m_time_label->sizePolicy().hasHeightForWidth());
        m_time_label->setSizePolicy(sizePolicy);
        m_time_label->setMinimumSize(QSize(70, 32));
        m_time_label->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        m_ptr_top_level_vertical_layout->addWidget(m_time_label);


        retranslateUi(BarChartSingleBar);

        QMetaObject::connectSlotsByName(BarChartSingleBar);
    } // setupUi

    void retranslateUi(QWidget *BarChartSingleBar)
    {
        BarChartSingleBar->setWindowTitle(QApplication::translate("BarChartSingleBar", "Bar Chart - Single Bar", 0, QApplication::UnicodeUTF8));
        m_ptr_top_level_header_spacer->setText(QString());
        m_remainder_percentage_bar_label->setText(QString());
        m_ptr_secondary_level_header_spacer->setText(QString());
        m_selected_source_percentage_bar_label->setText(QString());
        m_time_label->setText(QApplication::translate("BarChartSingleBar", "4:00pm", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BarChartSingleBar: public Ui_BarChartSingleBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BARCHARTSINGLEBAR_H
