/********************************************************************************
** Form generated from reading UI file 'SlidingBarChart.ui'
**
** Created: Mon Dec 6 17:06:12 2010
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SLIDINGBARCHART_H
#define UI_SLIDINGBARCHART_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SlidingBarChart
{
public:
    QFrame *m_bar_charts_container_widget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *m_bar_charts_container_widget_horizontal_layout;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *m_y_axis_percentile_data_labels_layout;
    QLabel *m_y_axis_100_percentile_data_label;
    QLabel *m_y_axis_80_percentile_data_label;
    QLabel *m_y_axis_60_percentile_data_label;
    QLabel *m_y_axis_40_percentile_data_label;
    QLabel *m_y_axis_20_percentile_data_label;
    QLabel *m_y_axis_0_percentile_data_label;
    QLabel *xAxisSeperator;
    QLabel *yAxisSeperator;
    QLabel *lblgraphSeperator_10;
    QLabel *lblgraphSeperator_8;
    QLabel *lblgraphSeperator_6;
    QLabel *lblgraphSeperator_4;
    QLabel *lblgraphSeperator_2;
    QLabel *lblFaderLeft;
    QLabel *lblFaderRight;

    void setupUi(QWidget *SlidingBarChart)
    {
        if (SlidingBarChart->objectName().isEmpty())
            SlidingBarChart->setObjectName(QString::fromUtf8("SlidingBarChart"));
        SlidingBarChart->resize(2090, 656);
        SlidingBarChart->setStyleSheet(QString::fromUtf8(""));
        m_bar_charts_container_widget = new QFrame(SlidingBarChart);
        m_bar_charts_container_widget->setObjectName(QString::fromUtf8("m_bar_charts_container_widget"));
        m_bar_charts_container_widget->setGeometry(QRect(60, 0, 510, 331));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(m_bar_charts_container_widget->sizePolicy().hasHeightForWidth());
        m_bar_charts_container_widget->setSizePolicy(sizePolicy);
        m_bar_charts_container_widget->setLayoutDirection(Qt::LeftToRight);
        m_bar_charts_container_widget->setStyleSheet(QString::fromUtf8(""));
        m_bar_charts_container_widget->setFrameShape(QFrame::Box);
        m_bar_charts_container_widget->setFrameShadow(QFrame::Plain);
        m_bar_charts_container_widget->setLineWidth(0);
        horizontalLayoutWidget = new QWidget(m_bar_charts_container_widget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 1761, 331));
        m_bar_charts_container_widget_horizontal_layout = new QHBoxLayout(horizontalLayoutWidget);
        m_bar_charts_container_widget_horizontal_layout->setSpacing(0);
        m_bar_charts_container_widget_horizontal_layout->setObjectName(QString::fromUtf8("m_bar_charts_container_widget_horizontal_layout"));
        m_bar_charts_container_widget_horizontal_layout->setSizeConstraint(QLayout::SetMaximumSize);
        m_bar_charts_container_widget_horizontal_layout->setContentsMargins(0, 0, 0, 0);
        verticalLayoutWidget = new QWidget(SlidingBarChart);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 61, 301));
        m_y_axis_percentile_data_labels_layout = new QVBoxLayout(verticalLayoutWidget);
        m_y_axis_percentile_data_labels_layout->setSpacing(0);
        m_y_axis_percentile_data_labels_layout->setObjectName(QString::fromUtf8("m_y_axis_percentile_data_labels_layout"));
        m_y_axis_percentile_data_labels_layout->setContentsMargins(0, 0, 0, 0);
        m_y_axis_100_percentile_data_label = new QLabel(verticalLayoutWidget);
        m_y_axis_100_percentile_data_label->setObjectName(QString::fromUtf8("m_y_axis_100_percentile_data_label"));
        m_y_axis_100_percentile_data_label->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);

        m_y_axis_percentile_data_labels_layout->addWidget(m_y_axis_100_percentile_data_label);

        m_y_axis_80_percentile_data_label = new QLabel(verticalLayoutWidget);
        m_y_axis_80_percentile_data_label->setObjectName(QString::fromUtf8("m_y_axis_80_percentile_data_label"));
        m_y_axis_80_percentile_data_label->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);

        m_y_axis_percentile_data_labels_layout->addWidget(m_y_axis_80_percentile_data_label);

        m_y_axis_60_percentile_data_label = new QLabel(verticalLayoutWidget);
        m_y_axis_60_percentile_data_label->setObjectName(QString::fromUtf8("m_y_axis_60_percentile_data_label"));
        m_y_axis_60_percentile_data_label->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);

        m_y_axis_percentile_data_labels_layout->addWidget(m_y_axis_60_percentile_data_label);

        m_y_axis_40_percentile_data_label = new QLabel(verticalLayoutWidget);
        m_y_axis_40_percentile_data_label->setObjectName(QString::fromUtf8("m_y_axis_40_percentile_data_label"));
        m_y_axis_40_percentile_data_label->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);

        m_y_axis_percentile_data_labels_layout->addWidget(m_y_axis_40_percentile_data_label);

        m_y_axis_20_percentile_data_label = new QLabel(verticalLayoutWidget);
        m_y_axis_20_percentile_data_label->setObjectName(QString::fromUtf8("m_y_axis_20_percentile_data_label"));
        m_y_axis_20_percentile_data_label->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);

        m_y_axis_percentile_data_labels_layout->addWidget(m_y_axis_20_percentile_data_label);

        m_y_axis_0_percentile_data_label = new QLabel(verticalLayoutWidget);
        m_y_axis_0_percentile_data_label->setObjectName(QString::fromUtf8("m_y_axis_0_percentile_data_label"));
        m_y_axis_0_percentile_data_label->setStyleSheet(QString::fromUtf8(""));
        m_y_axis_0_percentile_data_label->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);

        m_y_axis_percentile_data_labels_layout->addWidget(m_y_axis_0_percentile_data_label);

        xAxisSeperator = new QLabel(SlidingBarChart);
        xAxisSeperator->setObjectName(QString::fromUtf8("xAxisSeperator"));
        xAxisSeperator->setGeometry(QRect(60, 18, 1, 273));
        yAxisSeperator = new QLabel(SlidingBarChart);
        yAxisSeperator->setObjectName(QString::fromUtf8("yAxisSeperator"));
        yAxisSeperator->setGeometry(QRect(60, 290, 480, 1));
        lblgraphSeperator_10 = new QLabel(SlidingBarChart);
        lblgraphSeperator_10->setObjectName(QString::fromUtf8("lblgraphSeperator_10"));
        lblgraphSeperator_10->setGeometry(QRect(70, 38, 481, 1));
        lblgraphSeperator_8 = new QLabel(SlidingBarChart);
        lblgraphSeperator_8->setObjectName(QString::fromUtf8("lblgraphSeperator_8"));
        lblgraphSeperator_8->setGeometry(QRect(70, 88, 481, 1));
        lblgraphSeperator_6 = new QLabel(SlidingBarChart);
        lblgraphSeperator_6->setObjectName(QString::fromUtf8("lblgraphSeperator_6"));
        lblgraphSeperator_6->setGeometry(QRect(70, 138, 481, 1));
        lblgraphSeperator_4 = new QLabel(SlidingBarChart);
        lblgraphSeperator_4->setObjectName(QString::fromUtf8("lblgraphSeperator_4"));
        lblgraphSeperator_4->setGeometry(QRect(70, 188, 481, 1));
        lblgraphSeperator_2 = new QLabel(SlidingBarChart);
        lblgraphSeperator_2->setObjectName(QString::fromUtf8("lblgraphSeperator_2"));
        lblgraphSeperator_2->setGeometry(QRect(70, 238, 481, 1));
        lblFaderLeft = new QLabel(SlidingBarChart);
        lblFaderLeft->setObjectName(QString::fromUtf8("lblFaderLeft"));
        lblFaderLeft->setGeometry(QRect(60, 0, 60, 325));
        lblFaderLeft->setStyleSheet(QString::fromUtf8(""));
        lblFaderRight = new QLabel(SlidingBarChart);
        lblFaderRight->setObjectName(QString::fromUtf8("lblFaderRight"));
        lblFaderRight->setGeometry(QRect(500, 0, 100, 325));
        lblFaderRight->setStyleSheet(QString::fromUtf8(""));
        lblgraphSeperator_10->raise();
        lblgraphSeperator_2->raise();
        lblgraphSeperator_6->raise();
        lblgraphSeperator_4->raise();
        lblgraphSeperator_8->raise();
        m_bar_charts_container_widget->raise();
        verticalLayoutWidget->raise();
        lblFaderRight->raise();
        lblFaderLeft->raise();
        xAxisSeperator->raise();
        yAxisSeperator->raise();

        retranslateUi(SlidingBarChart);

        QMetaObject::connectSlotsByName(SlidingBarChart);
    } // setupUi

    void retranslateUi(QWidget *SlidingBarChart)
    {
        SlidingBarChart->setWindowTitle(QApplication::translate("SlidingBarChart", "Sliding Bar Chart", 0, QApplication::UnicodeUTF8));
        m_y_axis_100_percentile_data_label->setText(QApplication::translate("SlidingBarChart", "10", 0, QApplication::UnicodeUTF8));
        m_y_axis_80_percentile_data_label->setText(QApplication::translate("SlidingBarChart", "8", 0, QApplication::UnicodeUTF8));
        m_y_axis_60_percentile_data_label->setText(QApplication::translate("SlidingBarChart", "6", 0, QApplication::UnicodeUTF8));
        m_y_axis_40_percentile_data_label->setText(QApplication::translate("SlidingBarChart", "4", 0, QApplication::UnicodeUTF8));
        m_y_axis_20_percentile_data_label->setText(QApplication::translate("SlidingBarChart", "2", 0, QApplication::UnicodeUTF8));
        m_y_axis_0_percentile_data_label->setText(QApplication::translate("SlidingBarChart", "0", 0, QApplication::UnicodeUTF8));
        xAxisSeperator->setText(QString());
        yAxisSeperator->setText(QString());
        lblgraphSeperator_10->setText(QString());
        lblgraphSeperator_8->setText(QString());
        lblgraphSeperator_6->setText(QString());
        lblgraphSeperator_4->setText(QString());
        lblgraphSeperator_2->setText(QString());
        lblFaderLeft->setText(QString());
        lblFaderRight->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SlidingBarChart: public Ui_SlidingBarChart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SLIDINGBARCHART_H
