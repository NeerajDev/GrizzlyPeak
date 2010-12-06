/********************************************************************************
** Form generated from reading UI file 'MyMainWindow.ui'
**
** Created: Mon Dec 6 16:41:55 2010
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYMAINWINDOW_H
#define UI_MYMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyMainWindow
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *m_ptr_copyright_label;
    QHBoxLayout *layoutHeader;
    QPushButton *m_ptr_home_button;
    QLabel *m_ptr_title_label;
    QLabel *m_ptr_clock_label;
    QTabWidget *m_ptr_tab_widget;
    QWidget *view1;
    QWidget *widgetView1;
    QLabel *m_ptr_no_sources_label;
    QLabel *m_ptr_source_1_idle_label;
    QLabel *m_ptr_source_3_label;
    QLabel *m_ptr_source_2_label;
    QLabel *m_ptr_source_1_label;
    QLabel *m_ptr_source_4_label;
    QLabel *m_ptr_source_2_idle_label;
    QLabel *m_ptr_source_3_idle_label;
    QLabel *m_ptr_source_4_idle_label;
    QLabel *m_ptr_source_1_labelBg;
    QLabel *m_ptr_source_2_labelBg;
    QLabel *m_ptr_source_3_labelBg;
    QLabel *m_ptr_source_4_labelBg;
    QWidget *view2;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *m_ptr_view_2_weather_icon_label;
    QLabel *m_ptr_view_2_high_temperature_label;
    QLabel *m_ptr_view_2_low_temperature_label;
    QLabel *lblTotal;
    QLabel *lblTotalValue;
    QLabel *lblSeperator;
    QLabel *lblSeperator2;
    QLabel *m_ptr_view_2_title_label;
    QLabel *m_ptr_view_2_date_label;
    QPushButton *m_ptr_view_2_previous_day_push_button;
    QPushButton *m_ptr_view_2_note_push_button;
    QPushButton *m_ptr_view_2_next_day_push_button;
    QLabel *lblSeperator3;
    QWidget *view3;
    QPushButton *m_ptr_view_3_previous_month_push_button;
    QLabel *m_ptr_view_3_month_label;
    QPushButton *m_ptr_view_3_next_month_push_button;
    QLabel *lblSeperator_view3_1;
    QLabel *lblSeperator_view3_2;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *m_ptr_view_3_total_label;
    QLabel *m_ptr_view_3_total_value_label;
    QWidget *view4;
    QPushButton *m_ptr_view_4_next_year_push_button;
    QPushButton *m_ptr_view_4_previous_year_push_button;
    QLabel *m_ptr_view_4_year_label;
    QLabel *lblSeperator_4_1;
    QLabel *lblSeperator_4_2;
    QLabel *lblSeperator_4_3;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lblThisYearGraph;
    QLabel *lblThisYearTxt;
    QLabel *lblLastYearGraph;
    QLabel *lblLastYearTxt;
    QLabel *lblBaselineGraph;
    QLabel *lblBaseLineTxt;
    QLabel *m_ptr_view_4_total_label;
    QLabel *m_ptr_view_4_total_value_label;

    void setupUi(QWidget *MyMainWindow)
    {
        if (MyMainWindow->objectName().isEmpty())
            MyMainWindow->setObjectName(QString::fromUtf8("MyMainWindow"));
        MyMainWindow->resize(600, 1024);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MyMainWindow->sizePolicy().hasHeightForWidth());
        MyMainWindow->setSizePolicy(sizePolicy);
        MyMainWindow->setMaximumSize(QSize(600, 1024));
        verticalLayoutWidget = new QWidget(MyMainWindow);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 1, 601, 81));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        m_ptr_copyright_label = new QLabel(verticalLayoutWidget);
        m_ptr_copyright_label->setObjectName(QString::fromUtf8("m_ptr_copyright_label"));
        m_ptr_copyright_label->setTextFormat(Qt::AutoText);
        m_ptr_copyright_label->setScaledContents(false);
        m_ptr_copyright_label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(m_ptr_copyright_label);

        layoutHeader = new QHBoxLayout();
        layoutHeader->setSpacing(0);
        layoutHeader->setObjectName(QString::fromUtf8("layoutHeader"));
        layoutHeader->setSizeConstraint(QLayout::SetMaximumSize);
        layoutHeader->setContentsMargins(40, 0, 40, -1);
        m_ptr_home_button = new QPushButton(verticalLayoutWidget);
        m_ptr_home_button->setObjectName(QString::fromUtf8("m_ptr_home_button"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(m_ptr_home_button->sizePolicy().hasHeightForWidth());
        m_ptr_home_button->setSizePolicy(sizePolicy1);
        m_ptr_home_button->setMaximumSize(QSize(41, 36));
        m_ptr_home_button->setCursor(QCursor(Qt::PointingHandCursor));
        m_ptr_home_button->setFocusPolicy(Qt::NoFocus);
        m_ptr_home_button->setLayoutDirection(Qt::LeftToRight);

        layoutHeader->addWidget(m_ptr_home_button);

        m_ptr_title_label = new QLabel(verticalLayoutWidget);
        m_ptr_title_label->setObjectName(QString::fromUtf8("m_ptr_title_label"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(m_ptr_title_label->sizePolicy().hasHeightForWidth());
        m_ptr_title_label->setSizePolicy(sizePolicy2);
        m_ptr_title_label->setMinimumSize(QSize(440, 0));
        m_ptr_title_label->setMaximumSize(QSize(16777215, 16777215));
        m_ptr_title_label->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        layoutHeader->addWidget(m_ptr_title_label);

        m_ptr_clock_label = new QLabel(verticalLayoutWidget);
        m_ptr_clock_label->setObjectName(QString::fromUtf8("m_ptr_clock_label"));
        sizePolicy1.setHeightForWidth(m_ptr_clock_label->sizePolicy().hasHeightForWidth());
        m_ptr_clock_label->setSizePolicy(sizePolicy1);
        m_ptr_clock_label->setMaximumSize(QSize(16777215, 16777215));
        m_ptr_clock_label->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);

        layoutHeader->addWidget(m_ptr_clock_label);


        verticalLayout->addLayout(layoutHeader);

        m_ptr_tab_widget = new QTabWidget(MyMainWindow);
        m_ptr_tab_widget->setObjectName(QString::fromUtf8("m_ptr_tab_widget"));
        m_ptr_tab_widget->setGeometry(QRect(0, 130, 600, 895));
        m_ptr_tab_widget->setCursor(QCursor(Qt::ArrowCursor));
        m_ptr_tab_widget->setStyleSheet(QString::fromUtf8(""));
        m_ptr_tab_widget->setTabPosition(QTabWidget::South);
        view1 = new QWidget();
        view1->setObjectName(QString::fromUtf8("view1"));
        view1->setStyleSheet(QString::fromUtf8(""));
        widgetView1 = new QWidget(view1);
        widgetView1->setObjectName(QString::fromUtf8("widgetView1"));
        widgetView1->setGeometry(QRect(0, 0, 591, 871));
        widgetView1->setStyleSheet(QString::fromUtf8(""));
        m_ptr_no_sources_label = new QLabel(widgetView1);
        m_ptr_no_sources_label->setObjectName(QString::fromUtf8("m_ptr_no_sources_label"));
        m_ptr_no_sources_label->setGeometry(QRect(0, 400, 600, 30));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(m_ptr_no_sources_label->sizePolicy().hasHeightForWidth());
        m_ptr_no_sources_label->setSizePolicy(sizePolicy3);
        m_ptr_no_sources_label->setAlignment(Qt::AlignCenter);
        m_ptr_source_1_idle_label = new QLabel(widgetView1);
        m_ptr_source_1_idle_label->setObjectName(QString::fromUtf8("m_ptr_source_1_idle_label"));
        m_ptr_source_1_idle_label->setGeometry(QRect(300, 142, 10, 140));
        m_ptr_source_1_idle_label->setStyleSheet(QString::fromUtf8(""));
        m_ptr_source_1_idle_label->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        m_ptr_source_3_label = new QLabel(widgetView1);
        m_ptr_source_3_label->setObjectName(QString::fromUtf8("m_ptr_source_3_label"));
        m_ptr_source_3_label->setGeometry(QRect(40, 450, 571, 35));
        m_ptr_source_2_label = new QLabel(widgetView1);
        m_ptr_source_2_label->setObjectName(QString::fromUtf8("m_ptr_source_2_label"));
        m_ptr_source_2_label->setGeometry(QRect(40, 310, 571, 35));
        m_ptr_source_1_label = new QLabel(widgetView1);
        m_ptr_source_1_label->setObjectName(QString::fromUtf8("m_ptr_source_1_label"));
        m_ptr_source_1_label->setGeometry(QRect(40, 180, 571, 35));
        m_ptr_source_4_label = new QLabel(widgetView1);
        m_ptr_source_4_label->setObjectName(QString::fromUtf8("m_ptr_source_4_label"));
        m_ptr_source_4_label->setGeometry(QRect(40, 585, 571, 35));
        m_ptr_source_2_idle_label = new QLabel(widgetView1);
        m_ptr_source_2_idle_label->setObjectName(QString::fromUtf8("m_ptr_source_2_idle_label"));
        m_ptr_source_2_idle_label->setGeometry(QRect(300, 271, 10, 140));
        m_ptr_source_2_idle_label->setStyleSheet(QString::fromUtf8(""));
        m_ptr_source_2_idle_label->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        m_ptr_source_3_idle_label = new QLabel(widgetView1);
        m_ptr_source_3_idle_label->setObjectName(QString::fromUtf8("m_ptr_source_3_idle_label"));
        m_ptr_source_3_idle_label->setGeometry(QRect(300, 412, 10, 140));
        m_ptr_source_3_idle_label->setStyleSheet(QString::fromUtf8(""));
        m_ptr_source_3_idle_label->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        m_ptr_source_4_idle_label = new QLabel(widgetView1);
        m_ptr_source_4_idle_label->setObjectName(QString::fromUtf8("m_ptr_source_4_idle_label"));
        m_ptr_source_4_idle_label->setGeometry(QRect(300, 548, 10, 140));
        m_ptr_source_4_idle_label->setStyleSheet(QString::fromUtf8(""));
        m_ptr_source_4_idle_label->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        m_ptr_source_1_labelBg = new QLabel(widgetView1);
        m_ptr_source_1_labelBg->setObjectName(QString::fromUtf8("m_ptr_source_1_labelBg"));
        m_ptr_source_1_labelBg->setGeometry(QRect(20, 180, 571, 35));
        m_ptr_source_2_labelBg = new QLabel(widgetView1);
        m_ptr_source_2_labelBg->setObjectName(QString::fromUtf8("m_ptr_source_2_labelBg"));
        m_ptr_source_2_labelBg->setGeometry(QRect(20, 310, 571, 35));
        m_ptr_source_3_labelBg = new QLabel(widgetView1);
        m_ptr_source_3_labelBg->setObjectName(QString::fromUtf8("m_ptr_source_3_labelBg"));
        m_ptr_source_3_labelBg->setGeometry(QRect(20, 450, 571, 35));
        m_ptr_source_4_labelBg = new QLabel(widgetView1);
        m_ptr_source_4_labelBg->setObjectName(QString::fromUtf8("m_ptr_source_4_labelBg"));
        m_ptr_source_4_labelBg->setGeometry(QRect(20, 585, 571, 35));
        m_ptr_tab_widget->addTab(view1, QString());
        view2 = new QWidget();
        view2->setObjectName(QString::fromUtf8("view2"));
        view2->setStyleSheet(QString::fromUtf8(""));
        horizontalLayoutWidget = new QWidget(view2);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(50, 730, 501, 37));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(5);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        m_ptr_view_2_weather_icon_label = new QLabel(horizontalLayoutWidget);
        m_ptr_view_2_weather_icon_label->setObjectName(QString::fromUtf8("m_ptr_view_2_weather_icon_label"));
        m_ptr_view_2_weather_icon_label->setMinimumSize(QSize(0, 0));
        m_ptr_view_2_weather_icon_label->setMaximumSize(QSize(45, 16777215));
        m_ptr_view_2_weather_icon_label->setPixmap(QPixmap(QString::fromUtf8("images/sunny.png")));
        m_ptr_view_2_weather_icon_label->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(m_ptr_view_2_weather_icon_label);

        m_ptr_view_2_high_temperature_label = new QLabel(horizontalLayoutWidget);
        m_ptr_view_2_high_temperature_label->setObjectName(QString::fromUtf8("m_ptr_view_2_high_temperature_label"));
        m_ptr_view_2_high_temperature_label->setMaximumSize(QSize(40, 16777215));
        m_ptr_view_2_high_temperature_label->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(m_ptr_view_2_high_temperature_label);

        m_ptr_view_2_low_temperature_label = new QLabel(horizontalLayoutWidget);
        m_ptr_view_2_low_temperature_label->setObjectName(QString::fromUtf8("m_ptr_view_2_low_temperature_label"));
        m_ptr_view_2_low_temperature_label->setMaximumSize(QSize(16777215, 16777215));
        m_ptr_view_2_low_temperature_label->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(m_ptr_view_2_low_temperature_label);


        horizontalLayout_5->addLayout(horizontalLayout_2);

        lblTotal = new QLabel(horizontalLayoutWidget);
        lblTotal->setObjectName(QString::fromUtf8("lblTotal"));
        lblTotal->setMaximumSize(QSize(16777215, 16777215));
        lblTotal->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);

        horizontalLayout_5->addWidget(lblTotal);

        lblTotalValue = new QLabel(horizontalLayoutWidget);
        lblTotalValue->setObjectName(QString::fromUtf8("lblTotalValue"));
        lblTotalValue->setMaximumSize(QSize(50, 16777215));
        lblTotalValue->setSizeIncrement(QSize(0, 0));
        lblTotalValue->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(lblTotalValue);

        lblSeperator = new QLabel(view2);
        lblSeperator->setObjectName(QString::fromUtf8("lblSeperator"));
        lblSeperator->setGeometry(QRect(13, 715, 578, 2));
        lblSeperator->setMaximumSize(QSize(578, 2));
        lblSeperator->setStyleSheet(QString::fromUtf8(""));
        lblSeperator2 = new QLabel(view2);
        lblSeperator2->setObjectName(QString::fromUtf8("lblSeperator2"));
        lblSeperator2->setGeometry(QRect(13, 90, 578, 2));
        lblSeperator2->setMaximumSize(QSize(578, 2));
        lblSeperator2->setStyleSheet(QString::fromUtf8(""));
        m_ptr_view_2_title_label = new QLabel(view2);
        m_ptr_view_2_title_label->setObjectName(QString::fromUtf8("m_ptr_view_2_title_label"));
        m_ptr_view_2_title_label->setGeometry(QRect(80, 150, 500, 16));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(m_ptr_view_2_title_label->sizePolicy().hasHeightForWidth());
        m_ptr_view_2_title_label->setSizePolicy(sizePolicy4);
        m_ptr_view_2_date_label = new QLabel(view2);
        m_ptr_view_2_date_label->setObjectName(QString::fromUtf8("m_ptr_view_2_date_label"));
        m_ptr_view_2_date_label->setGeometry(QRect(0, 42, 600, 23));
        m_ptr_view_2_date_label->setMinimumSize(QSize(600, 0));
        m_ptr_view_2_date_label->setMaximumSize(QSize(300, 16777215));
        m_ptr_view_2_date_label->setAlignment(Qt::AlignCenter);
        m_ptr_view_2_previous_day_push_button = new QPushButton(view2);
        m_ptr_view_2_previous_day_push_button->setObjectName(QString::fromUtf8("m_ptr_view_2_previous_day_push_button"));
        m_ptr_view_2_previous_day_push_button->setGeometry(QRect(40, 35, 41, 36));
        m_ptr_view_2_previous_day_push_button->setMaximumSize(QSize(41, 36));
        m_ptr_view_2_note_push_button = new QPushButton(view2);
        m_ptr_view_2_note_push_button->setObjectName(QString::fromUtf8("m_ptr_view_2_note_push_button"));
        m_ptr_view_2_note_push_button->setGeometry(QRect(460, 35, 41, 36));
        m_ptr_view_2_note_push_button->setMaximumSize(QSize(60, 36));
        m_ptr_view_2_next_day_push_button = new QPushButton(view2);
        m_ptr_view_2_next_day_push_button->setObjectName(QString::fromUtf8("m_ptr_view_2_next_day_push_button"));
        m_ptr_view_2_next_day_push_button->setGeometry(QRect(520, 35, 41, 36));
        m_ptr_view_2_next_day_push_button->setMaximumSize(QSize(41, 36));
        lblSeperator3 = new QLabel(view2);
        lblSeperator3->setObjectName(QString::fromUtf8("lblSeperator3"));
        lblSeperator3->setGeometry(QRect(13, 340, 578, 2));
        lblSeperator3->setMaximumSize(QSize(578, 2));
        lblSeperator3->setStyleSheet(QString::fromUtf8(""));
        m_ptr_tab_widget->addTab(view2, QString());
        m_ptr_view_2_date_label->raise();
        horizontalLayoutWidget->raise();
        lblSeperator->raise();
        lblSeperator2->raise();
        m_ptr_view_2_title_label->raise();
        lblSeperator3->raise();
        m_ptr_view_2_previous_day_push_button->raise();
        m_ptr_view_2_note_push_button->raise();
        m_ptr_view_2_next_day_push_button->raise();
        view3 = new QWidget();
        view3->setObjectName(QString::fromUtf8("view3"));
        view3->setStyleSheet(QString::fromUtf8(""));
        m_ptr_view_3_previous_month_push_button = new QPushButton(view3);
        m_ptr_view_3_previous_month_push_button->setObjectName(QString::fromUtf8("m_ptr_view_3_previous_month_push_button"));
        m_ptr_view_3_previous_month_push_button->setGeometry(QRect(40, 35, 41, 36));
        m_ptr_view_3_previous_month_push_button->setMinimumSize(QSize(41, 36));
        m_ptr_view_3_previous_month_push_button->setMaximumSize(QSize(41, 36));
        m_ptr_view_3_previous_month_push_button->setStyleSheet(QString::fromUtf8(""));
        m_ptr_view_3_month_label = new QLabel(view3);
        m_ptr_view_3_month_label->setObjectName(QString::fromUtf8("m_ptr_view_3_month_label"));
        m_ptr_view_3_month_label->setGeometry(QRect(0, 42, 600, 23));
        m_ptr_view_3_month_label->setAlignment(Qt::AlignCenter);
        m_ptr_view_3_next_month_push_button = new QPushButton(view3);
        m_ptr_view_3_next_month_push_button->setObjectName(QString::fromUtf8("m_ptr_view_3_next_month_push_button"));
        m_ptr_view_3_next_month_push_button->setGeometry(QRect(520, 35, 41, 36));
        m_ptr_view_3_next_month_push_button->setMinimumSize(QSize(41, 36));
        m_ptr_view_3_next_month_push_button->setMaximumSize(QSize(41, 36));
        m_ptr_view_3_next_month_push_button->setStyleSheet(QString::fromUtf8(""));
        lblSeperator_view3_1 = new QLabel(view3);
        lblSeperator_view3_1->setObjectName(QString::fromUtf8("lblSeperator_view3_1"));
        lblSeperator_view3_1->setGeometry(QRect(13, 90, 576, 2));
        lblSeperator_view3_1->setMaximumSize(QSize(578, 2));
        lblSeperator_view3_1->setStyleSheet(QString::fromUtf8(""));
        lblSeperator_view3_2 = new QLabel(view3);
        lblSeperator_view3_2->setObjectName(QString::fromUtf8("lblSeperator_view3_2"));
        lblSeperator_view3_2->setGeometry(QRect(13, 715, 576, 2));
        lblSeperator_view3_2->setMaximumSize(QSize(578, 2));
        lblSeperator_view3_2->setStyleSheet(QString::fromUtf8(""));
        layoutWidget = new QWidget(view3);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(470, 730, 121, 16));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 15, 0);
        m_ptr_view_3_total_label = new QLabel(layoutWidget);
        m_ptr_view_3_total_label->setObjectName(QString::fromUtf8("m_ptr_view_3_total_label"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(m_ptr_view_3_total_label->sizePolicy().hasHeightForWidth());
        m_ptr_view_3_total_label->setSizePolicy(sizePolicy5);
        m_ptr_view_3_total_label->setMaximumSize(QSize(16777215, 16777215));
        m_ptr_view_3_total_label->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);

        horizontalLayout->addWidget(m_ptr_view_3_total_label);

        m_ptr_view_3_total_value_label = new QLabel(layoutWidget);
        m_ptr_view_3_total_value_label->setObjectName(QString::fromUtf8("m_ptr_view_3_total_value_label"));
        sizePolicy5.setHeightForWidth(m_ptr_view_3_total_value_label->sizePolicy().hasHeightForWidth());
        m_ptr_view_3_total_value_label->setSizePolicy(sizePolicy5);
        m_ptr_view_3_total_value_label->setSizeIncrement(QSize(0, 0));
        m_ptr_view_3_total_value_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(m_ptr_view_3_total_value_label);

        m_ptr_tab_widget->addTab(view3, QString());
        m_ptr_view_3_month_label->raise();
        layoutWidget->raise();
        lblSeperator_view3_1->raise();
        lblSeperator_view3_2->raise();
        m_ptr_view_3_previous_month_push_button->raise();
        m_ptr_view_3_next_month_push_button->raise();
        view4 = new QWidget();
        view4->setObjectName(QString::fromUtf8("view4"));
        view4->setStyleSheet(QString::fromUtf8(""));
        m_ptr_view_4_next_year_push_button = new QPushButton(view4);
        m_ptr_view_4_next_year_push_button->setObjectName(QString::fromUtf8("m_ptr_view_4_next_year_push_button"));
        m_ptr_view_4_next_year_push_button->setGeometry(QRect(520, 35, 41, 36));
        m_ptr_view_4_previous_year_push_button = new QPushButton(view4);
        m_ptr_view_4_previous_year_push_button->setObjectName(QString::fromUtf8("m_ptr_view_4_previous_year_push_button"));
        m_ptr_view_4_previous_year_push_button->setGeometry(QRect(40, 35, 41, 36));
        m_ptr_view_4_year_label = new QLabel(view4);
        m_ptr_view_4_year_label->setObjectName(QString::fromUtf8("m_ptr_view_4_year_label"));
        m_ptr_view_4_year_label->setGeometry(QRect(0, 42, 600, 23));
        m_ptr_view_4_year_label->setAlignment(Qt::AlignCenter);
        lblSeperator_4_1 = new QLabel(view4);
        lblSeperator_4_1->setObjectName(QString::fromUtf8("lblSeperator_4_1"));
        lblSeperator_4_1->setGeometry(QRect(13, 90, 576, 2));
        lblSeperator_4_1->setMaximumSize(QSize(578, 2));
        lblSeperator_4_1->setStyleSheet(QString::fromUtf8(""));
        lblSeperator_4_2 = new QLabel(view4);
        lblSeperator_4_2->setObjectName(QString::fromUtf8("lblSeperator_4_2"));
        lblSeperator_4_2->setGeometry(QRect(13, 340, 576, 2));
        lblSeperator_4_2->setMaximumSize(QSize(578, 2));
        lblSeperator_4_2->setStyleSheet(QString::fromUtf8(""));
        lblSeperator_4_3 = new QLabel(view4);
        lblSeperator_4_3->setObjectName(QString::fromUtf8("lblSeperator_4_3"));
        lblSeperator_4_3->setGeometry(QRect(13, 715, 578, 2));
        lblSeperator_4_3->setMaximumSize(QSize(578, 2));
        lblSeperator_4_3->setStyleSheet(QString::fromUtf8(""));
        layoutWidget1 = new QWidget(view4);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(4, 740, 591, 31));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(35, 0, 25, 0);
        lblThisYearGraph = new QLabel(layoutWidget1);
        lblThisYearGraph->setObjectName(QString::fromUtf8("lblThisYearGraph"));
        sizePolicy5.setHeightForWidth(lblThisYearGraph->sizePolicy().hasHeightForWidth());
        lblThisYearGraph->setSizePolicy(sizePolicy5);
        lblThisYearGraph->setMaximumSize(QSize(33, 13));
        lblThisYearGraph->setStyleSheet(QString::fromUtf8(""));
        lblThisYearGraph->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        horizontalLayout_3->addWidget(lblThisYearGraph);

        lblThisYearTxt = new QLabel(layoutWidget1);
        lblThisYearTxt->setObjectName(QString::fromUtf8("lblThisYearTxt"));
        QSizePolicy sizePolicy6(QSizePolicy::Fixed, QSizePolicy::MinimumExpanding);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(lblThisYearTxt->sizePolicy().hasHeightForWidth());
        lblThisYearTxt->setSizePolicy(sizePolicy6);

        horizontalLayout_3->addWidget(lblThisYearTxt);

        lblLastYearGraph = new QLabel(layoutWidget1);
        lblLastYearGraph->setObjectName(QString::fromUtf8("lblLastYearGraph"));
        sizePolicy5.setHeightForWidth(lblLastYearGraph->sizePolicy().hasHeightForWidth());
        lblLastYearGraph->setSizePolicy(sizePolicy5);
        lblLastYearGraph->setMaximumSize(QSize(33, 13));
        lblLastYearGraph->setStyleSheet(QString::fromUtf8(""));
        lblLastYearGraph->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        horizontalLayout_3->addWidget(lblLastYearGraph);

        lblLastYearTxt = new QLabel(layoutWidget1);
        lblLastYearTxt->setObjectName(QString::fromUtf8("lblLastYearTxt"));
        sizePolicy6.setHeightForWidth(lblLastYearTxt->sizePolicy().hasHeightForWidth());
        lblLastYearTxt->setSizePolicy(sizePolicy6);

        horizontalLayout_3->addWidget(lblLastYearTxt);

        lblBaselineGraph = new QLabel(layoutWidget1);
        lblBaselineGraph->setObjectName(QString::fromUtf8("lblBaselineGraph"));
        sizePolicy5.setHeightForWidth(lblBaselineGraph->sizePolicy().hasHeightForWidth());
        lblBaselineGraph->setSizePolicy(sizePolicy5);
        lblBaselineGraph->setMaximumSize(QSize(33, 13));
        lblBaselineGraph->setStyleSheet(QString::fromUtf8(""));
        lblBaselineGraph->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        horizontalLayout_3->addWidget(lblBaselineGraph);

        lblBaseLineTxt = new QLabel(layoutWidget1);
        lblBaseLineTxt->setObjectName(QString::fromUtf8("lblBaseLineTxt"));
        sizePolicy6.setHeightForWidth(lblBaseLineTxt->sizePolicy().hasHeightForWidth());
        lblBaseLineTxt->setSizePolicy(sizePolicy6);

        horizontalLayout_3->addWidget(lblBaseLineTxt);

        m_ptr_view_4_total_label = new QLabel(layoutWidget1);
        m_ptr_view_4_total_label->setObjectName(QString::fromUtf8("m_ptr_view_4_total_label"));
        sizePolicy.setHeightForWidth(m_ptr_view_4_total_label->sizePolicy().hasHeightForWidth());
        m_ptr_view_4_total_label->setSizePolicy(sizePolicy);
        m_ptr_view_4_total_label->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);

        horizontalLayout_3->addWidget(m_ptr_view_4_total_label);

        m_ptr_view_4_total_value_label = new QLabel(layoutWidget1);
        m_ptr_view_4_total_value_label->setObjectName(QString::fromUtf8("m_ptr_view_4_total_value_label"));
        QSizePolicy sizePolicy7(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(m_ptr_view_4_total_value_label->sizePolicy().hasHeightForWidth());
        m_ptr_view_4_total_value_label->setSizePolicy(sizePolicy7);
        m_ptr_view_4_total_value_label->setSizeIncrement(QSize(0, 0));
        m_ptr_view_4_total_value_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(m_ptr_view_4_total_value_label);

        m_ptr_tab_widget->addTab(view4, QString());
        m_ptr_view_4_year_label->raise();
        lblSeperator_4_1->raise();
        lblSeperator_4_2->raise();
        lblSeperator_4_3->raise();
        layoutWidget->raise();
        m_ptr_view_4_next_year_push_button->raise();
        m_ptr_view_4_previous_year_push_button->raise();

        retranslateUi(MyMainWindow);

        m_ptr_tab_widget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MyMainWindow);
    } // setupUi

    void retranslateUi(QWidget *MyMainWindow)
    {
        MyMainWindow->setWindowTitle(QApplication::translate("MyMainWindow", "Form", 0, QApplication::UnicodeUTF8));
        m_ptr_copyright_label->setText(QString());
        m_ptr_home_button->setText(QString());
        m_ptr_title_label->setText(QApplication::translate("MyMainWindow", "Grizzly Peak", 0, QApplication::UnicodeUTF8));
        m_ptr_clock_label->setText(QApplication::translate("MyMainWindow", "3:38pm", 0, QApplication::UnicodeUTF8));
        m_ptr_no_sources_label->setText(QApplication::translate("MyMainWindow", "Error - No Sources", 0, QApplication::UnicodeUTF8));
        m_ptr_source_1_idle_label->setText(QString());
        m_ptr_source_3_label->setText(QApplication::translate("MyMainWindow", "Source 3", 0, QApplication::UnicodeUTF8));
        m_ptr_source_2_label->setText(QApplication::translate("MyMainWindow", "Source 2", 0, QApplication::UnicodeUTF8));
        m_ptr_source_1_label->setText(QApplication::translate("MyMainWindow", "Source 1", 0, QApplication::UnicodeUTF8));
        m_ptr_source_4_label->setText(QApplication::translate("MyMainWindow", "Source 4", 0, QApplication::UnicodeUTF8));
        m_ptr_source_2_idle_label->setText(QString());
        m_ptr_source_3_idle_label->setText(QString());
        m_ptr_source_4_idle_label->setText(QString());
        m_ptr_source_1_labelBg->setText(QString());
        m_ptr_source_2_labelBg->setText(QString());
        m_ptr_source_3_labelBg->setText(QString());
        m_ptr_source_4_labelBg->setText(QString());
        m_ptr_tab_widget->setTabText(m_ptr_tab_widget->indexOf(view1), QApplication::translate("MyMainWindow", "View 1", 0, QApplication::UnicodeUTF8));
        m_ptr_view_2_weather_icon_label->setText(QString());
        m_ptr_view_2_high_temperature_label->setText(QApplication::translate("MyMainWindow", "H: 85\302\260", 0, QApplication::UnicodeUTF8));
        m_ptr_view_2_low_temperature_label->setText(QApplication::translate("MyMainWindow", "L: 55\302\260", 0, QApplication::UnicodeUTF8));
        lblTotal->setText(QApplication::translate("MyMainWindow", "Total", 0, QApplication::UnicodeUTF8));
        lblTotalValue->setText(QApplication::translate("MyMainWindow", "100", 0, QApplication::UnicodeUTF8));
        lblSeperator->setText(QString());
        lblSeperator2->setText(QString());
        m_ptr_view_2_title_label->setText(QApplication::translate("MyMainWindow", "Title", 0, QApplication::UnicodeUTF8));
        m_ptr_view_2_date_label->setText(QApplication::translate("MyMainWindow", "Selected Date", 0, QApplication::UnicodeUTF8));
        m_ptr_view_2_previous_day_push_button->setText(QString());
        m_ptr_view_2_note_push_button->setText(QString());
        m_ptr_view_2_next_day_push_button->setText(QString());
        lblSeperator3->setText(QString());
        m_ptr_tab_widget->setTabText(m_ptr_tab_widget->indexOf(view2), QApplication::translate("MyMainWindow", "View 2", 0, QApplication::UnicodeUTF8));
        m_ptr_view_3_previous_month_push_button->setText(QString());
        m_ptr_view_3_month_label->setText(QApplication::translate("MyMainWindow", "Selected Month", 0, QApplication::UnicodeUTF8));
        m_ptr_view_3_next_month_push_button->setText(QString());
        lblSeperator_view3_1->setText(QString());
        lblSeperator_view3_2->setText(QString());
        m_ptr_view_3_total_label->setText(QApplication::translate("MyMainWindow", "Total", 0, QApplication::UnicodeUTF8));
        m_ptr_view_3_total_value_label->setText(QApplication::translate("MyMainWindow", "1,456", 0, QApplication::UnicodeUTF8));
        m_ptr_tab_widget->setTabText(m_ptr_tab_widget->indexOf(view3), QApplication::translate("MyMainWindow", "View 3", 0, QApplication::UnicodeUTF8));
        m_ptr_view_4_next_year_push_button->setText(QString());
        m_ptr_view_4_previous_year_push_button->setText(QString());
        m_ptr_view_4_year_label->setText(QApplication::translate("MyMainWindow", "Selected Year", 0, QApplication::UnicodeUTF8));
        lblSeperator_4_1->setText(QString());
        lblSeperator_4_2->setText(QString());
        lblSeperator_4_3->setText(QString());
        lblThisYearGraph->setText(QString());
        lblThisYearTxt->setText(QApplication::translate("MyMainWindow", "This year", 0, QApplication::UnicodeUTF8));
        lblLastYearGraph->setText(QString());
        lblLastYearTxt->setText(QApplication::translate("MyMainWindow", "Last year", 0, QApplication::UnicodeUTF8));
        lblBaselineGraph->setText(QString());
        lblBaseLineTxt->setText(QApplication::translate("MyMainWindow", "Baseline", 0, QApplication::UnicodeUTF8));
        m_ptr_view_4_total_label->setText(QApplication::translate("MyMainWindow", "Total", 0, QApplication::UnicodeUTF8));
        m_ptr_view_4_total_value_label->setText(QApplication::translate("MyMainWindow", "1976", 0, QApplication::UnicodeUTF8));
        m_ptr_tab_widget->setTabText(m_ptr_tab_widget->indexOf(view4), QApplication::translate("MyMainWindow", "View 4", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MyMainWindow: public Ui_MyMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYMAINWINDOW_H
