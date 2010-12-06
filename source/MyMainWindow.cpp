#include <QDebug>
#include <QTime>
#include <QFile>
#include "MyMainWindow.h"
#include "Constants.h"
#include <QPainter>
#include <QMessageBox>


/////////////
// General //
/////////////

static char *array_view_2_weather_images[4] = {"images/cloudy.png",
                                               "images/partly_cloudy.png",
                                               "images/rain.png",
                                               "images/sunny.png"};

MyMainWindow::MyMainWindow(const QString &qstr_source_1_name,
                           const QString &qstr_source_2_name,
                           const QString &qstr_source_3_name,
                           const QString &qstr_source_4_name,
                           const QString &qstr_chrome_option,
                           const unsigned int uint_initial_tab,
                           QWidget *parent)
              :QWidget(parent),
               m_ptr_usage_1_circle(NULL),
               m_ptr_usage_2_circle(NULL),
               m_ptr_usage_3_circle(NULL),
               m_ptr_usage_4_circle(NULL),
               m_qdate_view_2_selected_date(QDate::currentDate()),
               m_uint_view_3_selected_month(QDate::currentDate().month()),
               m_uint_view_3_selected_year(QDate::currentDate().year()),
               m_uint_view_4_selected_month(QDate::currentDate().month()),
               m_uint_view_4_selected_year(QDate::currentDate().year()),
               m_int_view_2_high_temperature(0),
               m_int_view_2_low_temperature(0),
               m_bool_note_exists_for_selected_date(false),
               m_enum_selected_source_identifier(SOURCE_NONE)
    {



    QFile qfile_stylesheet(":/styles.qss");
       qfile_stylesheet.open(QFile::ReadOnly);
       m_qstring_array_stylesheet = (qfile_stylesheet.readAll());

       ///////////////////////////////////
       // Main application window setup //
       ///////////////////////////////////
    setupUi(this);
    setAppStyle();

    if (qstr_chrome_option == "chromeless")
        {
        setWindowFlags(Qt::Window |
                       Qt::FramelessWindowHint);
        }

    m_ptr_edit_note_dialog = new EditNoteDialog(this);
    m_ptr_view_note_dialog = new ViewNoteDialog(this);

    m_ptr_tab_widget->setCurrentIndex(uint_initial_tab - 1);

    connect(m_ptr_home_button,
            SIGNAL(clicked(bool)),
            this,
            SLOT(on_home_button_clicked()));

    m_ptr_clock_timer = new QTimer(this);

    connect(m_ptr_clock_timer,
            SIGNAL(timeout()),
            this,
            SLOT(on_clock_heartbeat()));

    m_ptr_clock_timer->setInterval(CLOCK_HEARTBEAT_PERIOD_MILLISECONDS);

    if (uint_initial_tab == 1)
        {
        m_ptr_clock_timer->start(CLOCK_HEARTBEAT_PERIOD_MILLISECONDS);
        }

    on_clock_heartbeat();

    connect(m_ptr_tab_widget,
            SIGNAL(currentChanged(int)),
            this,
            SLOT(on_tab_changed(const int)));



    //////////////////
    // View 1 setup //
    //////////////////

    m_ptr_source_1_idle_label->hide();
    m_ptr_source_2_idle_label->hide();
    m_ptr_source_3_idle_label->hide();
    m_ptr_source_4_idle_label->hide();

    if (qstr_source_1_name.length() > 0)
        {
        std::vector<GradientStopRGBAVectorValuesPair> vector_gradient_stops;

        VectorOfRGBAValues vector_rgba_values;

        // Put in the first stop

        vector_rgba_values.clear();
        vector_rgba_values.push_back(1.0 * VIEW_1_STOP_1_SOURCE_1_R_COLOR / 255.0);
        vector_rgba_values.push_back(1.0 * VIEW_1_STOP_1_SOURCE_1_G_COLOR / 255.0);
        vector_rgba_values.push_back(1.0 * VIEW_1_STOP_1_SOURCE_1_B_COLOR / 255.0);
        vector_rgba_values.push_back(1.0 * VIEW_1_STOP_1_SOURCE_1_A_COLOR / 255.0);
        vector_gradient_stops.push_back(GradientStopRGBAVectorValuesPair(VIEW_1_STOP_1_SOURCE_1,
                                                                         vector_rgba_values));

        // Put in the second stop

        vector_rgba_values.clear();
        vector_rgba_values.push_back(1.0 * VIEW_1_STOP_2_SOURCE_1_R_COLOR / 255.0);
        vector_rgba_values.push_back(1.0 * VIEW_1_STOP_2_SOURCE_1_G_COLOR / 255.0);
        vector_rgba_values.push_back(1.0 * VIEW_1_STOP_2_SOURCE_1_B_COLOR / 255.0);
        vector_rgba_values.push_back(1.0 * VIEW_1_STOP_2_SOURCE_1_A_COLOR / 255.0);
        vector_gradient_stops.push_back(GradientStopRGBAVectorValuesPair(VIEW_1_STOP_2_SOURCE_1,
                                                                         vector_rgba_values));

        // Put in the third stop

        vector_rgba_values.clear();
        vector_rgba_values.push_back(1.0 * VIEW_1_STOP_3_SOURCE_1_R_COLOR / 255.0);
        vector_rgba_values.push_back(1.0 * VIEW_1_STOP_3_SOURCE_1_G_COLOR / 255.0);
        vector_rgba_values.push_back(1.0 * VIEW_1_STOP_3_SOURCE_1_B_COLOR / 255.0);
        vector_rgba_values.push_back(1.0 * VIEW_1_STOP_3_SOURCE_1_A_COLOR / 255.0);
        vector_gradient_stops.push_back(GradientStopRGBAVectorValuesPair(VIEW_1_STOP_3_SOURCE_1,
                                                                         vector_rgba_values));

        m_ptr_usage_1_circle = new UsageGradientCircle(1,
                                                       qstr_source_1_name,
                                                       vector_gradient_stops,
                                                       view1);
        m_ptr_usage_1_circle->resize(0,
                                     0);
//        m_ptr_usage_1_circle->move(MAIN_WINDOW_WIDTH / 2 - m_ptr_usage_1_circle->width() / 2,
//                                   (DRAWING_AREA_HEIGHT / 50) * 10 - (m_ptr_usage_1_circle->height() / 2));
        m_ptr_usage_1_circle->move(SOURCE_1_X_POSITION,
                                   SOURCE_1_Y_POSITION);

        m_ptr_usage_1_circle->set_usage(10);

        m_ptr_source_1_label->setText(qstr_source_1_name);

        connect(m_ptr_usage_1_circle,
                SIGNAL(source_circle_animation_done(const unsigned int)),
                this,
                SLOT(on_view_1_source_circle_animation_done(const unsigned int)));
        }

    else
        {
        m_ptr_source_1_label->setText(VIEW_1_SOURCE_NOT_SETUP_MESSAGE);
        m_ptr_source_1_label->setObjectName(QString::fromUtf8("view_1_source_1_not_defined_label"));
        setAppStyle();
        }

    if (qstr_source_2_name.length() > 0)
        {
        std::vector<GradientStopRGBAVectorValuesPair> vector_gradient_stops;

        VectorOfRGBAValues vector_rgba_values;

        // Put in the first stop

        vector_rgba_values.clear();
        vector_rgba_values.push_back(1.0 * VIEW_1_STOP_1_SOURCE_2_R_COLOR / 255.0);
        vector_rgba_values.push_back(1.0 * VIEW_1_STOP_1_SOURCE_2_G_COLOR / 255.0);
        vector_rgba_values.push_back(1.0 * VIEW_1_STOP_1_SOURCE_2_B_COLOR / 255.0);
        vector_rgba_values.push_back(1.0 * VIEW_1_STOP_1_SOURCE_2_A_COLOR / 255.0);
        vector_gradient_stops.push_back(GradientStopRGBAVectorValuesPair(VIEW_1_STOP_1_SOURCE_2,
                                                                         vector_rgba_values));

        // Put in the second stop

        vector_rgba_values.clear();
        vector_rgba_values.push_back(1.0 * VIEW_1_STOP_2_SOURCE_2_R_COLOR / 255.0);
        vector_rgba_values.push_back(1.0 * VIEW_1_STOP_2_SOURCE_2_G_COLOR / 255.0);
        vector_rgba_values.push_back(1.0 * VIEW_1_STOP_2_SOURCE_2_B_COLOR / 255.0);
        vector_rgba_values.push_back(1.0 * VIEW_1_STOP_2_SOURCE_2_A_COLOR / 255.0);
        vector_gradient_stops.push_back(GradientStopRGBAVectorValuesPair(VIEW_1_STOP_2_SOURCE_2,
                                                                         vector_rgba_values));

        // Put in the third stop

        vector_rgba_values.clear();
        vector_rgba_values.push_back(1.0 * VIEW_1_STOP_3_SOURCE_2_R_COLOR / 255.0);
        vector_rgba_values.push_back(1.0 * VIEW_1_STOP_3_SOURCE_2_G_COLOR / 255.0);
        vector_rgba_values.push_back(1.0 * VIEW_1_STOP_3_SOURCE_2_B_COLOR / 255.0);
        vector_rgba_values.push_back(1.0 * VIEW_1_STOP_3_SOURCE_2_A_COLOR / 255.0);
        vector_gradient_stops.push_back(GradientStopRGBAVectorValuesPair(VIEW_1_STOP_3_SOURCE_2,
                                                                         vector_rgba_values));

        m_ptr_usage_2_circle = new UsageGradientCircle(2,
                                                       qstr_source_2_name,
                                                       vector_gradient_stops,
                                                       view1);
        m_ptr_usage_2_circle->resize(0,
                                     0);

//        m_ptr_usage_2_circle->move(MAIN_WINDOW_WIDTH / 2 - m_ptr_usage_2_circle->width() / 2,
//                                   (DRAWING_AREA_HEIGHT / 50) * 20 - (m_ptr_usage_2_circle->height() / 2));
        m_ptr_usage_2_circle->move(SOURCE_2_X_POSITION,
                                   SOURCE_2_Y_POSITION);

        m_ptr_usage_2_circle->set_usage(9);

        m_ptr_source_2_label->setText(qstr_source_2_name);

        connect(m_ptr_usage_2_circle,
                SIGNAL(source_circle_animation_done(const unsigned int)),
                this,
                SLOT(on_view_1_source_circle_animation_done(const unsigned int)));
        }

    else
        {
        m_ptr_source_2_label->setText(VIEW_1_SOURCE_NOT_SETUP_MESSAGE);
        m_ptr_source_2_label->setObjectName(QString::fromUtf8("view_1_source_2_not_defined_label"));
        setAppStyle();
        }

    if (qstr_source_3_name.length() > 0)
        {
        std::vector<GradientStopRGBAVectorValuesPair> vector_gradient_stops;

        VectorOfRGBAValues vector_rgba_values;

        // Put in the first stop

        vector_rgba_values.clear();
        vector_rgba_values.push_back(1.0 * VIEW_1_STOP_1_SOURCE_3_R_COLOR / 255.0);
        vector_rgba_values.push_back(1.0 * VIEW_1_STOP_1_SOURCE_3_G_COLOR / 255.0);
        vector_rgba_values.push_back(1.0 * VIEW_1_STOP_1_SOURCE_3_B_COLOR / 255.0);
        vector_rgba_values.push_back(1.0 * VIEW_1_STOP_1_SOURCE_3_A_COLOR / 255.0);
        vector_gradient_stops.push_back(GradientStopRGBAVectorValuesPair(VIEW_1_STOP_1_SOURCE_3,
                                                                         vector_rgba_values));

        // Put in the second stop

        vector_rgba_values.clear();
        vector_rgba_values.push_back(1.0 * VIEW_1_STOP_2_SOURCE_3_R_COLOR / 255.0);
        vector_rgba_values.push_back(1.0 * VIEW_1_STOP_2_SOURCE_3_G_COLOR / 255.0);
        vector_rgba_values.push_back(1.0 * VIEW_1_STOP_2_SOURCE_3_B_COLOR / 255.0);
        vector_rgba_values.push_back(1.0 * VIEW_1_STOP_2_SOURCE_3_A_COLOR / 255.0);
        vector_gradient_stops.push_back(GradientStopRGBAVectorValuesPair(VIEW_1_STOP_2_SOURCE_3,
                                                                         vector_rgba_values));

        // Put in the third stop

        vector_rgba_values.clear();
        vector_rgba_values.push_back(1.0 * VIEW_1_STOP_3_SOURCE_3_R_COLOR / 255.0);
        vector_rgba_values.push_back(1.0 * VIEW_1_STOP_3_SOURCE_3_G_COLOR / 255.0);
        vector_rgba_values.push_back(1.0 * VIEW_1_STOP_3_SOURCE_3_B_COLOR / 255.0);
        vector_rgba_values.push_back(1.0 * VIEW_1_STOP_3_SOURCE_3_A_COLOR / 255.0);
        vector_gradient_stops.push_back(GradientStopRGBAVectorValuesPair(VIEW_1_STOP_3_SOURCE_3,
                                                                         vector_rgba_values));

        m_ptr_usage_3_circle = new UsageGradientCircle(3,
                                                       qstr_source_3_name,
                                                       vector_gradient_stops,
                                                       view1);
        m_ptr_usage_3_circle->resize(0,
                                     0);
//        m_ptr_usage_3_circle->move(MAIN_WINDOW_WIDTH / 2 - m_ptr_usage_3_circle->width() / 2,
//                                   (DRAWING_AREA_HEIGHT / 50) * 30 - (m_ptr_usage_3_circle->height() / 2));
        m_ptr_usage_3_circle->move(SOURCE_3_X_POSITION,
                                   SOURCE_3_Y_POSITION);

        m_ptr_usage_3_circle->set_usage(9);

        m_ptr_source_3_label->setText(qstr_source_3_name);

        connect(m_ptr_usage_3_circle,
                SIGNAL(source_circle_animation_done(const unsigned int)),
                this,
                SLOT(on_view_1_source_circle_animation_done(const unsigned int)));
        }

    else
        {
        m_ptr_source_3_label->setText(VIEW_1_SOURCE_NOT_SETUP_MESSAGE);
        m_ptr_source_3_label->setObjectName(QString::fromUtf8("view_1_source_3_not_defined_label"));
        setAppStyle();
        }

    if (qstr_source_4_name.length() > 0)
        {
        std::vector<GradientStopRGBAVectorValuesPair> vector_gradient_stops;

        VectorOfRGBAValues vector_rgba_values;

        // Put in the first stop

        vector_rgba_values.clear();
        vector_rgba_values.push_back(1.0 * VIEW_1_STOP_1_SOURCE_4_R_COLOR / 255.0);
        vector_rgba_values.push_back(1.0 * VIEW_1_STOP_1_SOURCE_4_G_COLOR / 255.0);
        vector_rgba_values.push_back(1.0 * VIEW_1_STOP_1_SOURCE_4_B_COLOR / 255.0);
        vector_rgba_values.push_back(1.0 * VIEW_1_STOP_1_SOURCE_4_A_COLOR / 255.0);
        vector_gradient_stops.push_back(GradientStopRGBAVectorValuesPair(VIEW_1_STOP_1_SOURCE_4,
                                                                         vector_rgba_values));

        // Put in the second stop

        vector_rgba_values.clear();
        vector_rgba_values.push_back(1.0 * VIEW_1_STOP_2_SOURCE_4_R_COLOR / 255.0);
        vector_rgba_values.push_back(1.0 * VIEW_1_STOP_2_SOURCE_4_G_COLOR / 255.0);
        vector_rgba_values.push_back(1.0 * VIEW_1_STOP_2_SOURCE_4_B_COLOR / 255.0);
        vector_rgba_values.push_back(1.0 * VIEW_1_STOP_2_SOURCE_4_A_COLOR / 255.0);
        vector_gradient_stops.push_back(GradientStopRGBAVectorValuesPair(VIEW_1_STOP_2_SOURCE_4,
                                                                         vector_rgba_values));

        // Put in the third stop

        vector_rgba_values.clear();
        vector_rgba_values.push_back(1.0 * VIEW_1_STOP_3_SOURCE_4_R_COLOR / 255.0);
        vector_rgba_values.push_back(1.0 * VIEW_1_STOP_3_SOURCE_4_G_COLOR / 255.0);
        vector_rgba_values.push_back(1.0 * VIEW_1_STOP_3_SOURCE_4_B_COLOR / 255.0);
        vector_rgba_values.push_back(1.0 * VIEW_1_STOP_3_SOURCE_4_A_COLOR / 255.0);
        vector_gradient_stops.push_back(GradientStopRGBAVectorValuesPair(VIEW_1_STOP_3_SOURCE_4,
                                                                         vector_rgba_values));

        m_ptr_usage_4_circle = new UsageGradientCircle(4,
                                                       qstr_source_4_name,
                                                       vector_gradient_stops,
                                                       view1);
        m_ptr_usage_4_circle->resize(0,
                                     0);
//        m_ptr_usage_4_circle->move(MAIN_WINDOW_WIDTH / 2 - m_ptr_usage_4_circle->width() / 2,
//                                   (DRAWING_AREA_HEIGHT / 50) * 40 - (m_ptr_usage_4_circle->height() / 2));
        m_ptr_usage_4_circle->move(SOURCE_4_X_POSITION,
                                   SOURCE_4_Y_POSITION);

        m_ptr_usage_4_circle->set_usage(2);

        m_ptr_source_4_label->setText(qstr_source_4_name);

        connect(m_ptr_usage_4_circle,
                SIGNAL(source_circle_animation_done(const unsigned int)),
                this,
                SLOT(on_view_1_source_circle_animation_done(const unsigned int)));
        }

    else
        {
        m_ptr_source_4_label->setText(VIEW_1_SOURCE_NOT_SETUP_MESSAGE);
        m_ptr_source_4_label->setObjectName(QString::fromUtf8("view_1_source_4_not_defined_label"));
        setAppStyle();
        }

    // If none of the sources have been setup, display the view 1 error message

    if ((!m_ptr_usage_1_circle) &&
        (!m_ptr_usage_2_circle) &&
        (!m_ptr_usage_3_circle) &&
        (!m_ptr_usage_4_circle))
        {
        m_ptr_no_sources_label->show();

        m_ptr_source_1_label->hide();
        m_ptr_source_2_label->hide();
        m_ptr_source_3_label->hide();
        m_ptr_source_4_label->hide();
        }

    // Otherwise, hide the view 1 error message

    else
        {
        m_ptr_no_sources_label->hide();
        }

    m_ptr_view_1_heartbeat_timer = new QTimer(this);
    connect(m_ptr_view_1_heartbeat_timer,
            SIGNAL(timeout()),
            this,
            SLOT(on_view_1_heartbeat()));
    m_ptr_view_1_heartbeat_timer->setInterval(VIEW_1_HEARTBEAT_PERIOD_MILLISECONDS);

    if (uint_initial_tab == 1)
        {
        m_ptr_view_1_heartbeat_timer->start(VIEW_1_HEARTBEAT_PERIOD_MILLISECONDS);
        }



    //////////////////
    // View 2 setup //
    //////////////////

    m_ptr_view_2_next_day_push_button->setEnabled(false);
    m_ptr_view_2_next_day_push_button->setObjectName(QString::fromUtf8("m_ptr_view_2_next_day_push_button__disabled"));
    setAppStyle();

    m_ptr_view_2_interactive_segmented_bar = new InteractiveSegmentedBar(qstr_source_1_name,
                                                                         qstr_source_2_name,
                                                                         qstr_source_3_name,
                                                                         qstr_source_4_name,
                                                                         view2);

    m_ptr_view_2_interactive_segmented_bar->move(VIEW_2_SEGMENTED_BAR_X_POSITION,
                                                 VIEW_2_SEGMENTED_BAR_Y_POSITION);

    // Generate an array of x axis labels for view 2's sliding bar charts

    std::vector<QString> vector_view_2_x_axis_labels;

    for (unsigned int counter = 0;
         counter < 24;
         counter++)
        {
        char str_time_label[256];

        if (counter % 2 == 0)
            {
            unsigned int uint_current_hour = counter + 12;

            char char_am_pm;

            if (uint_current_hour >= 24)
                {
                char_am_pm = 'p';
                }

            else
                {
                char_am_pm = 'a';
                }

            if (uint_current_hour > 24)
                {
                uint_current_hour -= 24;
                }

            else if (uint_current_hour > 12)
                {
                uint_current_hour -= 12;
                }

            sprintf(str_time_label,
                    VERTICAL_DATA_BAR_TIME_FORMAT_STRING,
                    uint_current_hour,
                    char_am_pm);
            }

        else
            {
            str_time_label[0] = 0;
            }

        vector_view_2_x_axis_labels.push_back(str_time_label);
        }

    m_ptr_view_2_sliding_bar_chart_container = new SlidingBarChart(vector_view_2_x_axis_labels,
                                                                   24,
                                                                   view2);

    m_ptr_view_2_sliding_bar_chart_container->move(VIEW_2_SLIDING_BAR_CHAR_X_POSITION,
                                                   VIEW_2_SLIDING_BAR_CHAR_Y_POSITION);

    update_view_2_date();

    connect(m_ptr_view_2_previous_day_push_button,
            SIGNAL(clicked(bool)),
            this,
            SLOT(randomize_and_update_view_2_weather_temperature()));

    connect(m_ptr_view_2_next_day_push_button,
            SIGNAL(clicked(bool)),
            this,
            SLOT(randomize_and_update_view_2_weather_temperature()));

    randomize_and_update_view_2_weather_temperature();

    m_ptr_view_2_title_label->setText(VIEW_2_TITLE_TEXT);

    connect(m_ptr_view_2_previous_day_push_button,
            SIGNAL(clicked(bool)),
            this,
            SLOT(on_view_2_previous_day_push_button_clicked()));

    connect(m_ptr_view_2_next_day_push_button,
            SIGNAL(clicked(bool)),
            this,
            SLOT(on_view_2_next_day_push_button_clicked()));

    connect(m_ptr_view_2_interactive_segmented_bar,
            SIGNAL(signal_new_source_selected(const SourcesEnum)),
            this,
            SLOT(on_new_source_selected(const SourcesEnum)));

    connect(m_ptr_view_2_interactive_segmented_bar,
            SIGNAL(signal_new_source_selected(const SourcesEnum)),
            m_ptr_view_2_sliding_bar_chart_container,
            SLOT(set_selected_source(const SourcesEnum)));


    //////////////////
    // View 3 Setup //
    //////////////////

    carousel_view3 = new CarouselControl("background-color:transparent;border-top:0px solid  rgb(0, 0, 0, 50);border-bottom:0px; vertical-align: top;",view3);


    carousel_view3->setCarouselInfiniteLoop(true);

         carousel_view3->slot_setCarouselSize(QSize(200,424), QSize(1000,700));
         carousel_view3->slot_setScaleFactor(0);
         carousel_view3->slot_setItemSize(QSize(75,50), QSize(600,424));
         carousel_view3->slot_setPosition(15,350);

         carousel_view3->slot_setOrientation(Horizontal);
         carousel_view3->initializeItemList(false);


    m_ptr_view3_monthView = new MonthView(carousel_view3);
    m_ptr_view3_monthView->setDateSelectionEnabled(false);
    m_ptr_view3_monthView->Open();
    connect(m_ptr_view3_monthView, SIGNAL(data_updated(int)), this, SLOT(month_data_updated(int)));
    CurrentActiveMonth = m_ptr_view3_monthView;
    CurrentSource = SOURCE_OTHER;
    connect(m_ptr_view3_monthView, SIGNAL(DateChanged(QDate)), this, SLOT(slot_view3_dateSelected(QDate)));
    carousel_view3->slot_addItem(m_ptr_view3_monthView);

   m_ptr_view3_monthView_next = new MonthView(carousel_view3);
    m_ptr_view3_monthView_next->setDateSelectionEnabled(false);
    m_ptr_view3_monthView_next->Open();
      connect(m_ptr_view3_monthView_next, SIGNAL(data_updated(int)), this, SLOT(month_data_updated(int)));
       connect(m_ptr_view3_monthView_next, SIGNAL(DateChanged(QDate)), this, SLOT(slot_view3_dateSelected(QDate)));
    carousel_view3->slot_addItem(m_ptr_view3_monthView_next);

    m_ptr_view3_monthView_prev = new MonthView(carousel_view3);
     m_ptr_view3_monthView_prev->setDateSelectionEnabled(false);
     m_ptr_view3_monthView_prev->Open();
       connect(m_ptr_view3_monthView_prev, SIGNAL(data_updated(int)), this, SLOT(month_data_updated(int)));
        connect(m_ptr_view3_monthView_prev, SIGNAL(DateChanged(QDate)), this, SLOT(slot_view3_dateSelected(QDate)));
     carousel_view3->slot_addItem(m_ptr_view3_monthView_prev);



    m_ptr_view_3_next_month_push_button->setEnabled(false);
    m_ptr_view_3_next_month_push_button->setObjectName(QString::fromUtf8("m_ptr_view_3_next_month_push_button__disabled"));
    setAppStyle();

    m_ptr_view_3_interactive_segmented_bar = new InteractiveSegmentedBar(qstr_source_1_name,
                                                                         qstr_source_2_name,
                                                                         qstr_source_3_name,
                                                                         qstr_source_4_name,
                                                                         view3);

    m_ptr_view_3_interactive_segmented_bar->move(VIEW_3_SEGMENTED_BAR_X_POSITION,
                                                 VIEW_3_SEGMENTED_BAR_Y_POSITION);

    update_view_3_month(true,
                        true,
                        true);

    connect(m_ptr_view_3_previous_month_push_button,
            SIGNAL(clicked()),
            this,
            SLOT(on_view_3_previous_month_push_button_clicked()));

    connect(m_ptr_view_3_next_month_push_button,
            SIGNAL(clicked()),
            this,
            SLOT(on_view_3_next_month_push_button_clicked()));

    connect(m_ptr_view_3_interactive_segmented_bar,
            SIGNAL(signal_new_source_selected(const SourcesEnum)),
            this,
            SLOT(on_new_source_selected(const SourcesEnum)));

    //////////////////
    // View 4 Setup //
    //////////////////

    m_ptr_view_4_next_year_push_button->setEnabled(false);
    m_ptr_view_4_next_year_push_button->setObjectName(QString::fromUtf8("m_ptr_view_4_next_year_push_button__disabled"));
    setAppStyle();

    m_ptr_view_4_interactive_segmented_bar = new InteractiveSegmentedBar(qstr_source_1_name,
                                                                         qstr_source_2_name,
                                                                         qstr_source_3_name,
                                                                         qstr_source_4_name,
                                                                         view4);

    m_ptr_view_4_interactive_segmented_bar->move(VIEW_4_SEGMENTED_BAR_X_POSITION,
                                                 VIEW_4_SEGMENTED_BAR_Y_POSITION);

    // Generate an array of x axis labels for view 4's sliding bar charts

    std::vector<QString> vector_view_4_x_axis_labels;

    QDate qdate_view_4_date_counter = QDate::currentDate();
    qdate_view_4_date_counter = qdate_view_4_date_counter.addMonths(-11);

    for (unsigned int counter = 0;
         counter < 12;
         counter++)
        {
        if (qdate_view_4_date_counter.month() == 1)
            {
            vector_view_4_x_axis_labels.push_back(qdate_view_4_date_counter.toString("MMM\nyyyy"));
            }

        else
            {
            vector_view_4_x_axis_labels.push_back(qdate_view_4_date_counter.toString("MMM"));
            }

        qdate_view_4_date_counter = qdate_view_4_date_counter.addMonths(1);

//        qDebug() << qdate_view_4_date_counter << "\n";
        }

    m_ptr_view_4_sliding_bar_chart_container = new SlidingBarChart(vector_view_4_x_axis_labels,
                                                                   12,
                                                                   view4);

    m_ptr_view_4_sliding_bar_chart_container->move(VIEW_4_SLIDING_BAR_CHAR_X_POSITION,
                                                   VIEW_4_SLIDING_BAR_CHAR_Y_POSITION);

    update_view_4_year();

    connect(m_ptr_view_4_previous_year_push_button,
            SIGNAL(clicked(bool)),
            this,
            SLOT(on_view_4_previous_year_push_button_clicked()));

    connect(m_ptr_view_4_next_year_push_button,
            SIGNAL(clicked(bool)),
            this,
            SLOT(on_view_4_next_year_push_button_clicked()));

    connect(m_ptr_view_4_interactive_segmented_bar,
            SIGNAL(signal_new_source_selected(const SourcesEnum)),
            this,
            SLOT(on_new_source_selected(const SourcesEnum)));

    connect(m_ptr_view_4_interactive_segmented_bar,
            SIGNAL(signal_new_source_selected(const SourcesEnum)),
            m_ptr_view_4_sliding_bar_chart_container,
            SLOT(set_selected_source(const SourcesEnum)));



    ////////////////////////////
    // Edit Note Dialog Setup //
    ////////////////////////////

    connect(m_ptr_view_2_note_push_button,
            SIGNAL(clicked(bool)),
            this,
            SLOT(on_view_2_note_push_button_clicked()));
    }

void MyMainWindow::on_home_button_clicked()
    {
    QApplication::closeAllWindows();
    }

void MyMainWindow::on_clock_heartbeat()
    {
    const QString qstr_current_time_string = QTime::currentTime().toString("h:mmap");

    m_ptr_clock_label->setText(qstr_current_time_string);
    }

void MyMainWindow::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
        opt.init(this);
        QPainter p(this);
        style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void MyMainWindow::on_tab_changed(const int index)
    {
//    qDebug() << "Tab changed to " << index << "\n"

    if (index == 0)
        {
        m_ptr_view_1_heartbeat_timer->start();
        m_ptr_clock_timer->start();

//        qDebug() << "Turning on view 1 timers\n\n\n\n\n";
        }

    else
        {
        m_ptr_view_1_heartbeat_timer->stop();
        m_ptr_clock_timer->stop();

//        qDebug() << "Turning off view 1 timers\n\n\n\n";
        }

    m_ptr_view_2_interactive_segmented_bar->set_source(m_enum_selected_source_identifier);
    m_ptr_view_3_interactive_segmented_bar->set_source(m_enum_selected_source_identifier);
    m_ptr_view_4_interactive_segmented_bar->set_source(m_enum_selected_source_identifier);

    if (index == 1)
        {
        update_view_2_date();
        }

    if (index == 2)
        {
        CurrentActiveMonth->slot_fillData();
        }
    }



////////////
// View 1 //
////////////

int MyMainWindow::get_view_1_random_delta_value()
    {
//    return (qrand() % (VIEW_1_SIMULATED_PER_MINUTE_DELTA_MAXIMA * 2 + 1)) - VIEW_1_SIMULATED_PER_MINUTE_DELTA_MAXIMA;

    // Slightly favors larger usage over smaller ones, to make the visual display more interesting

    return (qrand() % (VIEW_1_SIMULATED_PER_MINUTE_DELTA_MAXIMA * 2)) - VIEW_1_SIMULATED_PER_MINUTE_DELTA_MAXIMA + 1;
}

// Fires whenever we want to start a new growth or shrinkage animage on the usage circles

void MyMainWindow::on_view_1_heartbeat()
    {
//    qDebug() << "View 1 heartbeat\n";

    if (m_ptr_usage_1_circle)
        {
        int int_random_delta_value = get_view_1_random_delta_value();

        m_ptr_usage_1_circle->apply_usage_delta(int_random_delta_value);

        // If the current usage is non-zero (not idle), turn off the idle image label for this source

        if (m_ptr_usage_1_circle->get_current_usage() > 0)
            {
            m_ptr_source_1_idle_label->hide();
            }
        }

    if (m_ptr_usage_2_circle)
        {
        int int_random_delta_value = get_view_1_random_delta_value();

        m_ptr_usage_2_circle->apply_usage_delta(int_random_delta_value);

        // If the current usage is non-zero (not idle), turn off the idle image label for this source

        if (m_ptr_usage_2_circle->get_current_usage() > 0)
            {
            m_ptr_source_2_idle_label->hide();
            }
        }

    if (m_ptr_usage_3_circle)
        {
        int int_random_delta_value = get_view_1_random_delta_value();

        m_ptr_usage_3_circle->apply_usage_delta(int_random_delta_value);

        // If the current usage is non-zero (not idle), turn off the idle image label for this source

        if (m_ptr_usage_3_circle->get_current_usage() > 0)
            {
            m_ptr_source_3_idle_label->hide();
            }
        }

    if (m_ptr_usage_4_circle)
        {
        int int_random_delta_value = get_view_1_random_delta_value();

        m_ptr_usage_4_circle->apply_usage_delta(int_random_delta_value);

        // If the current usage is non-zero (not idle), turn off the idle image label for this source

        if (m_ptr_usage_4_circle->get_current_usage() > 0)
            {
            m_ptr_source_4_idle_label->hide();
            }
        }
    }

// We have to turn off the idle label this way (using a signal and slot) because we need the animation
// for the circle to shrink down to zero to complete first, before the idle line is shown. The converse
// is not true -- we can immediately hide the idle line as soon as the circle is meant to grow.

void MyMainWindow::on_view_1_source_circle_animation_done(const unsigned int uint_source_number)
    {
    switch (uint_source_number)
        {
        case 1:
            {
            if (m_ptr_usage_1_circle &&
                (m_ptr_usage_1_circle->get_current_usage() == 0))
                {
                m_ptr_source_1_idle_label->show();
                }
            }
        break;

        case 2:
            {
            if (m_ptr_usage_2_circle &&
                (m_ptr_usage_2_circle->get_current_usage() == 0))
                {
                m_ptr_source_2_idle_label->show();
                }
            }
        break;

        case 3:
            {
            if (m_ptr_usage_3_circle &&
                (m_ptr_usage_3_circle->get_current_usage() == 0))
                {
                m_ptr_source_3_idle_label->show();
                }
            }
        break;

        case 4:
            {
            if (m_ptr_usage_4_circle &&
                (m_ptr_usage_4_circle->get_current_usage() == 0))
                {
                m_ptr_source_4_idle_label->show();
                }
            }
        break;
        }

    if (m_ptr_source_1_idle_label->isVisible())
        {
        if (m_ptr_source_2_idle_label->isVisible())
            {
            m_ptr_source_1_idle_label->setObjectName(QString::fromUtf8("View1IdleTaperTop"));
            }

        else
            {
            m_ptr_source_1_idle_label->setObjectName(QString::fromUtf8("View1IdleTaperBoth"));
            }
        }

    if (m_ptr_source_2_idle_label->isVisible())
        {
        if (m_ptr_source_1_idle_label->isVisible())
            {
            if (m_ptr_source_3_idle_label->isVisible())
                {
                m_ptr_source_2_idle_label->setObjectName(QString::fromUtf8("View1IdleTaperNone"));
                }

            else
                {
                m_ptr_source_2_idle_label->setObjectName(QString::fromUtf8("View1IdleTaperBottom"));
                }
            }

        else
            {
            if (m_ptr_source_3_idle_label->isVisible())
                {
                m_ptr_source_2_idle_label->setObjectName(QString::fromUtf8("View1IdleTaperTop"));
                }

            else
                {
                m_ptr_source_2_idle_label->setObjectName(QString::fromUtf8("View1IdleTaperBoth"));
                }
            }
        }

    if (m_ptr_source_3_idle_label->isVisible())
        {
        if (m_ptr_source_2_idle_label->isVisible())
            {
            if (m_ptr_source_4_idle_label->isVisible())
                {
                m_ptr_source_3_idle_label->setObjectName(QString::fromUtf8("View1IdleTaperNone"));
                }

            else
                {
                m_ptr_source_3_idle_label->setObjectName(QString::fromUtf8("View1IdleTaperBottom"));
                }
            }

        else
            {
            if (m_ptr_source_4_idle_label->isVisible())
                {
                m_ptr_source_3_idle_label->setObjectName(QString::fromUtf8("View1IdleTaperTop"));
                }

            else
                {
                m_ptr_source_3_idle_label->setObjectName(QString::fromUtf8("View1IdleTaperBoth"));
                }
            }
        }

    if (m_ptr_source_4_idle_label->isVisible())
        {
        if (m_ptr_source_3_idle_label->isVisible())
            {
            m_ptr_source_4_idle_label->setObjectName(QString::fromUtf8("View1IdleTaperBottom"));
            }

        else
            {
            m_ptr_source_4_idle_label->setObjectName(QString::fromUtf8("View1IdleTaperBoth"));
            }
        }

    //setAppStyle();
    setWidgetStyle(*m_ptr_source_1_idle_label);
       setWidgetStyle(*m_ptr_source_2_idle_label);
       setWidgetStyle(*m_ptr_source_3_idle_label);
       setWidgetStyle(*m_ptr_source_4_idle_label);
    }



////////////
// View 2 //
////////////

void MyMainWindow::update_view_2_note_data()
    {
    // Next, check to see if there is a note and get its contents too.

    QString qstr_note_contents;

    m_bool_note_exists_for_selected_date = get_note_for_view_2_date_from_disk(qstr_note_contents);

    if (m_bool_note_exists_for_selected_date)
        {
//        m_ptr_view_2_note_push_button->setText("Edit");
//        qDebug() << "Setting button for note exists. Current name is: " << m_ptr_view_2_note_push_button->objectName() << "\n";
        m_ptr_view_2_note_push_button->setObjectName(QString::fromUtf8("m_ptr_view_2_note_push_button"));
//        qDebug() << "Done setting button for note exists. Current name is: " << m_ptr_view_2_note_push_button->objectName() << "\n";

        m_ptr_edit_note_dialog->set_text(qstr_note_contents);
        m_ptr_view_note_dialog->set_text(qstr_note_contents);
        }

    else
        {
//        m_ptr_view_2_note_push_button->setText("Create");
//        qDebug() << "Setting button for note does not exist. Current name is: " << m_ptr_view_2_note_push_button->objectName() << "\n";
        m_ptr_view_2_note_push_button->setObjectName(QString::fromUtf8("m_ptr_view_2_note_push_off_button"));
//        qDebug() << "Done setting button for note does not exist. Current name is: " << m_ptr_view_2_note_push_button->objectName() << "\n";

        m_ptr_edit_note_dialog->set_text("");
        }

    //JS: styles need to be applied again after setting object name

    //setAppStyle();
      setWidgetStyle(*m_ptr_view_2_note_push_button);
    }

void MyMainWindow::get_view_2_usage_data()
    {
    // Clear out the vector of usage data vector

    m_vector_vector_view_2_selected_day_usage_values.clear();

    // Create 24 vectors of data in the array, one vector per hour

    m_vector_vector_view_2_selected_day_usage_values.resize(24);

    // Looping over each of the 24 hrs, grab all the usage data for the currently selected day for each hour

    for (std::vector<VectorOfUsageDataForOtherAndSpecificSources>::iterator iterator_vector_hourly_usage_data = m_vector_vector_view_2_selected_day_usage_values.begin();
         iterator_vector_hourly_usage_data != m_vector_vector_view_2_selected_day_usage_values.end();
         iterator_vector_hourly_usage_data++)
        {
        // Get usage data for the selected date and current hour for all the sources and put it into the vector representing
        // data for the current hour.

        MyDataSource::get_hourly_day_usage_data(iterator_vector_hourly_usage_data - m_vector_vector_view_2_selected_day_usage_values.begin(),
                                                m_qdate_view_2_selected_date,
                                                *iterator_vector_hourly_usage_data);
        }
    }

unsigned int MyMainWindow::get_total_time_period_usage_usage(const std::vector<VectorOfUsageDataForOtherAndSpecificSources> &vector_vector_selected_time_pediod_usage_values) const
    {
    unsigned int uint_retval = 0;

    // Loop over each of the sub-time-periods of the selected time period

    for (std::vector<VectorOfUsageDataForOtherAndSpecificSources>::const_iterator iterator_vector_sub_time_period_usage_data = vector_vector_selected_time_pediod_usage_values.begin();
         iterator_vector_sub_time_period_usage_data != vector_vector_selected_time_pediod_usage_values.end();
         iterator_vector_sub_time_period_usage_data++)
        {
        // Loop over all the source usages in the selected hour of the selected day

        for (VectorOfUsageDataForOtherAndSpecificSources::const_iterator iterator_source_usage_data = iterator_vector_sub_time_period_usage_data->begin();
             iterator_source_usage_data != iterator_vector_sub_time_period_usage_data->end();
             iterator_source_usage_data++)
            {
            uint_retval += (*iterator_source_usage_data);
            }
        }

    return uint_retval;
    }

void MyMainWindow::update_view_2_interactive_segmented_bar_with_data()
    {
    std::vector<unsigned int> vector_cumulative_usages_per_source;

    get_cumulative_time_period_usages(vector_cumulative_usages_per_source,
                                      m_vector_vector_view_2_selected_day_usage_values);

    m_ptr_view_2_interactive_segmented_bar->set_usage_per_source(vector_cumulative_usages_per_source);
    }

void MyMainWindow::get_cumulative_time_period_usages(std::vector<unsigned int> &vector_cumulative_usages_per_source,
                                                     const std::vector<VectorOfUsageDataForOtherAndSpecificSources> &vector_vector_selected_time_period_usage_values) const
    {
    vector_cumulative_usages_per_source.clear();

    // We need to calculate the total usage for the selected day, for each of the four sources, and for the other source

    vector_cumulative_usages_per_source.resize(5);

    // Loop over each of the sub-time-periods of the selected time period

    for (std::vector<VectorOfUsageDataForOtherAndSpecificSources>::const_iterator iterator_vector_sub_time_period_usage_data = vector_vector_selected_time_period_usage_values.begin();
         iterator_vector_sub_time_period_usage_data != vector_vector_selected_time_period_usage_values.end();
         iterator_vector_sub_time_period_usage_data++)
        {
        // Loop over all the source usages in the selected sub-time-period of the selected time-period

        for (VectorOfUsageDataForOtherAndSpecificSources::const_iterator iterator_source_usage_data = iterator_vector_sub_time_period_usage_data->begin();
             iterator_source_usage_data != iterator_vector_sub_time_period_usage_data->end();
             iterator_source_usage_data++)
            {
            // Get an index to the current source

            const unsigned int uint_current_source_index = (iterator_source_usage_data - iterator_vector_sub_time_period_usage_data->begin());

            if (uint_current_source_index < vector_cumulative_usages_per_source.size())
                {
                // Add the current sub-time-period's usage for the selected source to the total for that source

                vector_cumulative_usages_per_source[uint_current_source_index] +=  (*iterator_source_usage_data);
                }
            }
        }
    }

void MyMainWindow::on_new_source_selected(const SourcesEnum enum_source_identifier)
    {
                 m_enum_selected_source_identifier = enum_source_identifier;
                    CurrentSource = enum_source_identifier;
                    //For view 3 month view
                //if(bool_new_selected_month_data)
               // {

                    CurrentActiveMonth->UpdateSourceData(enum_source_identifier);
                 //}else if(bool_new_next_month_data)
               // {
                //     m_ptr_view3_monthView_next->UpdateSourceData(enum_source_identifier);
                //} else if (bool_new_previous_month_data)
               // {
               //     m_ptr_view3_monthView_prev->UpdateSourceData(enum_source_identifier);
                 //}
    }

void MyMainWindow::update_view_2_date()
    {
    // First, update the text for the date

    const QString qstr_selected_date_string = m_qdate_view_2_selected_date.toString("MMMM d, yyyy");

    m_ptr_view_2_date_label->setText(qstr_selected_date_string);

    update_view_2_note_data();

    get_view_2_usage_data();

    m_ptr_view_2_sliding_bar_chart_container->set_source_usage_totals(m_vector_vector_view_2_selected_day_usage_values);

    update_view_2_interactive_segmented_bar_with_data();

//    qDebug() << "Total usage is " << get_total_day_usage() << "\n";

    lblTotalValue->setText(QString::number(get_total_time_period_usage_usage(m_vector_vector_view_2_selected_day_usage_values)));
    }

void MyMainWindow::on_set_view_2_date(const QDate &qdate_new_date)
    {
    m_qdate_view_2_selected_date = qdate_new_date;

    update_view_2_date();

    // If the new selected date is the current date, we need to also disable the next day push button

    if (m_qdate_view_2_selected_date == QDate::currentDate())
        {
        m_ptr_view_2_next_day_push_button->setEnabled(false);
        m_ptr_view_2_next_day_push_button->setObjectName(QString::fromUtf8("m_ptr_view_2_next_day_push_button__disabled"));
         setWidgetStyle(*m_ptr_view_2_next_day_push_button);
       // setAppStyle();
        }

    // Otherwise, we enable the next day push button

    else
        {
        m_ptr_view_2_next_day_push_button->setEnabled(true);
        m_ptr_view_2_next_day_push_button->setObjectName(QString::fromUtf8("m_ptr_view_2_next_day_push_button"));
        setWidgetStyle(*m_ptr_view_2_next_day_push_button);
        //setAppStyle();
        }
    }

void MyMainWindow::on_view_2_previous_day_push_button_clicked()
    {
    m_qdate_view_2_selected_date = m_qdate_view_2_selected_date.addDays(-1);

    update_view_2_date();

    m_ptr_view_2_next_day_push_button->setEnabled(true);
    m_ptr_view_2_next_day_push_button->setObjectName(QString::fromUtf8("m_ptr_view_2_next_day_push_button"));

     setWidgetStyle(*m_ptr_view_2_next_day_push_button);

  //  setAppStyle();

    }

void MyMainWindow::on_view_2_next_day_push_button_clicked()
    {
    m_qdate_view_2_selected_date = m_qdate_view_2_selected_date.addDays(1);

    update_view_2_date();

    // If the new selected date is the current date, we need to also disable the next day push button

    if (m_qdate_view_2_selected_date == QDate::currentDate())
        {
        m_ptr_view_2_next_day_push_button->setEnabled(false);
        m_ptr_view_2_next_day_push_button->setObjectName(QString::fromUtf8("m_ptr_view_2_next_day_push_button__disabled"));

         setWidgetStyle(*m_ptr_view_2_next_day_push_button);

        // setAppStyle();
        }
    }

void MyMainWindow::randomize_and_update_view_2_weather_temperature()
    {
    // Choose a random weather condition

    m_enum_view_2_weather_condition = WeatherConditionEnum(qrand() % NUMBER_OF_WEATHER_CONDITIONS);

    m_ptr_view_2_weather_icon_label->setPixmap(QPixmap(QString::fromUtf8(array_view_2_weather_images[m_enum_view_2_weather_condition])));

    const int int_new_temperature_1 = (qrand() % (VIEW_2_MAX_TEMPERATURE - VIEW_2_MIN_TEMPERATURE + 1)) + VIEW_2_MIN_TEMPERATURE;
    const int int_new_temperature_2 = (qrand() % (VIEW_2_MAX_TEMPERATURE - VIEW_2_MIN_TEMPERATURE + 1)) + VIEW_2_MIN_TEMPERATURE;

    const int int_new_high_temperature = (int_new_temperature_1 > int_new_temperature_2 ? int_new_temperature_1 : int_new_temperature_2);
    const int int_new_low_temperature = (int_new_temperature_1 < int_new_temperature_2 ? int_new_temperature_1 : int_new_temperature_2);

    char str_new_temperature_text[64];

    sprintf(str_new_temperature_text,
            VIEW_2_HIGH_TEMPERATURE_FORMAT_STRING,
            int_new_high_temperature);

    m_ptr_view_2_high_temperature_label->setText(QApplication::translate("MyMainWindow",
                                                                         str_new_temperature_text,
                                                                         0,
                                                                         QApplication::UnicodeUTF8));

    sprintf(str_new_temperature_text,
            VIEW_2_LOW_TEMPERATURE_FORMAT_STRING,
            int_new_low_temperature);

    m_ptr_view_2_low_temperature_label->setText(QApplication::translate("MyMainWindow",
                                                                        str_new_temperature_text,
                                                                        0,
                                                                        QApplication::UnicodeUTF8));
    }

QString MyMainWindow::get_note_filename_from_view_2_selected_date() const
    {
    // Convert the selected date to an integer that we can lookup the filename for

    const int int_selected_julian_day = m_qdate_view_2_selected_date.toJulianDay();

    // Generate the filename

    char str_note_filename[128];

    sprintf(str_note_filename,
            VIEW_2_NOTE_FILENAME_TEMPLATE,
            int_selected_julian_day);

    return str_note_filename;
    }

QString read_file_into_string(const QString &qstr_filename)
    {
    QString qstr_retval;

    QFile file(qstr_filename);

    if (!file.open(QIODevice::ReadOnly |
                   QIODevice::Text))
        {
        return "";
        }

    while (!file.atEnd())
        {
        QByteArray line = file.readLine();

        qstr_retval += line;
        }

    return qstr_retval;
    }

bool MyMainWindow::get_note_for_view_2_date_from_disk(QString &qstr_note_contents) const
    {
    const QString qstr_note_filename = QString(VIEW_2_NOTES_FOLDER) + get_note_filename_from_view_2_selected_date();

//    qDebug() << "Looking for note with filename: " << qstr_note_filename << "\n";

    // Look on disk if the given file exists

    if (QFile::exists(qstr_note_filename))
        {
//        qDebug() << "Found note\n";

        // Read the contents of the file

        qstr_note_contents = read_file_into_string(qstr_note_filename);

        return true;
        }

    else
        {
//        qDebug() << "Did not find note\n";

        return false;
        }
    }

void MyMainWindow::show_edit_note_dialog()
    {
    char str_edit_note_title[256];

    sprintf(str_edit_note_title,
            VIEW_2_EDIT_NOTE_TITLE_TEMPLATE,
            m_qdate_view_2_selected_date.toString("MMMM d, yyyy").toStdString().c_str());

    m_ptr_edit_note_dialog->setWindowTitle(str_edit_note_title);
    m_ptr_edit_note_dialog->show();
    }

void MyMainWindow::show_view_note_dialog()
    {
    char str_view_note_title[256];

    sprintf(str_view_note_title,
            VIEW_2_VIEW_NOTE_TITLE_TEMPLATE,
            m_qdate_view_2_selected_date.toString("MMMM d, yyyy").toStdString().c_str());

    m_ptr_view_note_dialog->setWindowTitle(str_view_note_title);
    m_ptr_view_note_dialog->show();
    }

void MyMainWindow::on_view_2_note_push_button_clicked()
    {
    // If a note exists for the selected date, show the view dialog

    if (m_bool_note_exists_for_selected_date)
        {
        show_view_note_dialog();
        }

    // Otherwise, show the edit dialog

    else
        {
        show_edit_note_dialog();
        }
    }

void MyMainWindow::on_done_view_2_note_push_button_clicked()
    {
    const QString qstr_note_filename = QString(VIEW_2_NOTES_FOLDER) + get_note_filename_from_view_2_selected_date();

    // If the text is empty, delete the note if it exists on disk

    if (m_ptr_edit_note_dialog->get_text().length() == 0)
        {
        QFile::remove(qstr_note_filename);
        }

    // Otherwise, write the note to disk

    else
        {
        QFile file(qstr_note_filename);

        if (file.open(QIODevice::Truncate |
                      QIODevice::WriteOnly |
                      QIODevice::Text))
            {
            file.write(m_ptr_edit_note_dialog->get_text().toUtf8());
            }
        }

    update_view_2_note_data();
    }

void MyMainWindow::on_edit_view_2_note_push_button_clicked()
    {
    m_ptr_view_note_dialog->hide();

    show_edit_note_dialog();
    }


////////////
// View 3 //
////////////

void MyMainWindow::month_data_updated(int data)
{
    m_ptr_view_3_total_value_label->setText(QString::number(data));
}

void MyMainWindow::update_view_3_month(const bool bool_new_previous_month_data,
                                       const bool bool_new_selected_month_data,
                                       const bool bool_new_next_month_data)
    {


        const QString qstr_selected_month_string = QDate(m_uint_view_3_selected_year,
                                                     m_uint_view_3_selected_month,
                                                     1).toString("MMMM yyyy");

    m_ptr_view_3_month_label->setText(qstr_selected_month_string);
    int duration = VIEW_3_MONTH_SCROLLINGANIMATION_INTERVAL;
    get_view_3_usage_data(bool_new_previous_month_data,
                          bool_new_selected_month_data,
                          bool_new_next_month_data);




    QRect     geo =  m_ptr_view3_monthView->geometry();
    if(bool_new_selected_month_data)
    {


        m_ptr_view3_monthView ->setDataSource( m_vector_vector_view_3_selected_month_usage_values );
        m_ptr_view3_monthView->slot_createCalendar(QDate(m_uint_view_3_selected_year,
                                                     m_uint_view_3_selected_month,
                                                     1),   CurrentSource );

            m_ptr_view3_monthView->move(VIEW_3_MONTH_X, geo.y());
         m_ptr_view3_monthView_prev->move(-VIEW_3_PREV_MONTH_X, geo.y());
         m_ptr_view3_monthView_next->move(VIEW_3_NEXT_MONTH_X, geo.y());
         CurrentActiveMonth = m_ptr_view3_monthView;
    }
    else if(bool_new_next_month_data)
    {
 m_ptr_view3_monthView_next ->setDataSource( m_vector_vector_view_3_next_month_usage_values);
        m_ptr_view3_monthView_next->slot_createCalendar(QDate(m_uint_view_3_selected_year,
                                                     m_uint_view_3_selected_month,
                                                     1),   CurrentSource, false);


        QPropertyAnimation* animation = new QPropertyAnimation(m_ptr_view3_monthView,"geometry",this);
                    animation->setDuration(duration);
                    animation->setStartValue(QRect(VIEW_3_MONTH_X,geo.y(),geo.width(),geo.height()));
                    animation->setEndValue(QRect(-VIEW_3_PREV_MONTH_X,geo.y(),geo.width(),geo.height()));
                    animation->start();

                    geo =  m_ptr_view3_monthView_next->geometry();
                     animation = new QPropertyAnimation(m_ptr_view3_monthView_next,"geometry",this);
                    animation->setDuration(duration);
                    animation->setStartValue(QRect(VIEW_3_NEXT_MONTH_X,geo.y(),geo.width(),geo.height()));
                    animation->setEndValue(QRect(VIEW_3_MONTH_X,geo.y(),geo.width(),geo.height()));
                    connect(animation, SIGNAL(finished()), m_ptr_view3_monthView_next, SLOT(slot_fillData()));
                    animation->start();


                    geo =  m_ptr_view3_monthView_prev->geometry();
                    m_ptr_view3_monthView_prev->move(VIEW_3_NEXT_MONTH_X, geo.y());

                    m_ptr_view3_monthView->setObjectName(QString::fromUtf8("m_ptr_view3_monthView_prev"));
                    m_ptr_view3_monthView_next->setObjectName(QString::fromUtf8("m_ptr_view3_monthView"));
                    m_ptr_view3_monthView_prev->setObjectName(QString::fromUtf8("m_ptr_view3_monthView_next"));
                    CurrentActiveMonth = m_ptr_view3_monthView_next;
    }

    else if(bool_new_previous_month_data)
    {
       m_ptr_view3_monthView_prev ->setDataSource( m_vector_vector_view_3_previous_month_usage_values);
        m_ptr_view3_monthView_prev->slot_createCalendar(QDate(m_uint_view_3_selected_year,
                                                         m_uint_view_3_selected_month,
                                                         1),   CurrentSource, false);

        QRect geo =  m_ptr_view3_monthView->geometry();

        QPropertyAnimation* animation = new QPropertyAnimation(m_ptr_view3_monthView,"geometry",this);
                    animation->setDuration(duration);
                    animation->setStartValue(QRect(VIEW_3_MONTH_X,geo.y(),geo.width(),geo.height()));
                    animation->setEndValue(QRect(VIEW_3_NEXT_MONTH_X,geo.y(),geo.width(),geo.height()));
                    animation->start();

                    geo =  m_ptr_view3_monthView_prev->geometry();
                     animation = new QPropertyAnimation(m_ptr_view3_monthView_prev,"geometry",this);
                    animation->setDuration(duration);
                    animation->setStartValue(QRect(-VIEW_3_NEXT_MONTH_X,geo.y(),geo.width(),geo.height()));
                    animation->setEndValue(QRect(VIEW_3_MONTH_X,geo.y(),geo.width(),geo.height()));
                    connect(animation, SIGNAL(finished()), m_ptr_view3_monthView_prev, SLOT(slot_fillData()));
                    animation->start();


                    geo =  m_ptr_view3_monthView_next->geometry();
                    m_ptr_view3_monthView_next->move(-1100, geo.y());

                     animation = new QPropertyAnimation(m_ptr_view3_monthView_next,"geometry",this);
                    animation->setDuration(duration);
                    animation->setStartValue(QRect(-1100,geo.y(),geo.width(),geo.height()));
                    animation->setEndValue(QRect(-VIEW_3_PREV_MONTH_X,geo.y(),geo.width(),geo.height()));
                   // connect(animation, SIGNAL(finished()), m_ptr_view3_monthView_prev, SLOT(slot_fillData()));
                    animation->start();


                    m_ptr_view3_monthView->setObjectName(QString::fromUtf8("m_ptr_view3_monthView_next"));
                    m_ptr_view3_monthView_prev->setObjectName(QString::fromUtf8("m_ptr_view3_monthView"));
                    m_ptr_view3_monthView_next->setObjectName(QString::fromUtf8("m_ptr_view3_monthView_prev"));
                     CurrentActiveMonth =  m_ptr_view3_monthView_prev;

    }
    update_view_3_interactive_segmented_bar_with_data();

    m_ptr_view_3_total_value_label->setText(QString::number(CurrentActiveMonth->getAllWeeksData()));

    }

void MyMainWindow::on_view_3_previous_month_push_button_clicked()
    {
    if (m_uint_view_3_selected_month == 1)
        {
        m_uint_view_3_selected_month = 12;
        m_uint_view_3_selected_year--;
        }

    else
        {
        m_uint_view_3_selected_month--;
        }

    update_view_3_month(true,
                        false,
                        false);

    m_ptr_view_3_next_month_push_button->setEnabled(true);
    m_ptr_view_3_next_month_push_button->setObjectName(QString::fromUtf8("m_ptr_view_3_next_month_push_button"));
   // setAppStyle();
    setWidgetStyle(*m_ptr_view_3_next_month_push_button);
    }

void MyMainWindow::on_view_3_next_month_push_button_clicked()
    {
    if (m_uint_view_3_selected_month == 12)
        {
        m_uint_view_3_selected_month = 1;
        m_uint_view_3_selected_year++;
        }

    else
        {
        m_uint_view_3_selected_month++;
        }

    update_view_3_month(false,
                        false,
                        true);

    // If the new selected date is the current date, we need to also disable the next day push button

    if ((m_uint_view_3_selected_month == QDate::currentDate().month()) &&
        (m_uint_view_3_selected_year == QDate::currentDate().year()))
        {
        m_ptr_view_3_next_month_push_button->setEnabled(false);
        m_ptr_view_3_next_month_push_button->setObjectName(QString::fromUtf8("m_ptr_view_3_next_month_push_button__disabled"));
       // setAppStyle();
        setWidgetStyle(*m_ptr_view_3_next_month_push_button);
        }
    }

void MyMainWindow::on_set_view_3_month(const unsigned int uint_view_3_selected_month,
                                       const unsigned int uint_view_3_selected_year)
    {
    m_uint_view_3_selected_month = uint_view_3_selected_month;
    m_uint_view_3_selected_year = uint_view_3_selected_year;

    update_view_3_month(true,
                        true,
                        true);

    // If the new selected date is the current date, we need to also disable the next day push button

    if ((m_uint_view_3_selected_month == QDate::currentDate().month()) &&
        (m_uint_view_3_selected_year == QDate::currentDate().year()))
        {
        m_ptr_view_3_next_month_push_button->setEnabled(false);
        m_ptr_view_3_next_month_push_button->setObjectName(QString::fromUtf8("m_ptr_view_3_next_month_push_button__disabled"));
      //  setAppStyle();
        setWidgetStyle(*m_ptr_view_3_next_month_push_button);
        }

    // Otherwise, we enable the next month button

    else
        {
        m_ptr_view_3_next_month_push_button->setEnabled(true);
        m_ptr_view_3_next_month_push_button->setObjectName(QString::fromUtf8("m_ptr_view_3_next_month_push_button"));
       // setAppStyle();
        setWidgetStyle(*m_ptr_view_3_next_month_push_button);
        }
    }



////////////
// View 4 //
////////////

void MyMainWindow::update_view_4_year()
    {
    // Get the end part of the year span in string form

    const QString qstr_selected_year_end_span_string = QDate(m_uint_view_4_selected_year,
                                                             m_uint_view_4_selected_month,
                                                             1).toString("MMMM, yyyy");

    // Calculate the start of the year span

    const unsigned int uint_start_span_month = ((m_uint_view_4_selected_month == 12) ? 1
                                                                                     : (m_uint_view_4_selected_month + 1));

    const unsigned int uint_start_span_year = ((m_uint_view_4_selected_month == 12) ? m_uint_view_4_selected_year
                                                                                    : (m_uint_view_4_selected_year - 1));

    // Get the start part of the year span in string form

    const QString qstr_selected_year_start_span_string = QDate(uint_start_span_year,
                                                               uint_start_span_month,
                                                               1).toString("MMMM, yyyy");

    char str_selected_year_string[128];

    sprintf(str_selected_year_string,
            VIEW_4_YEAR_DISPLAY_TEMPLATE,
            qstr_selected_year_start_span_string.toStdString().c_str(),
            qstr_selected_year_end_span_string.toStdString().c_str());

    m_ptr_view_4_year_label->setText(str_selected_year_string);

    get_view_4_usage_data();

    m_ptr_view_4_sliding_bar_chart_container->set_source_usage_totals(m_vector_vector_view_4_selected_year_usage_values);

    update_view_4_interactive_segmented_bar_with_data();

//    qDebug() << "Total year usage is " << get_total_time_period_usage_usage(m_vector_vector_view_4_selected_year_usage_values) << "\n";

    m_ptr_view_4_total_value_label->setText(QString::number(get_total_time_period_usage_usage(m_vector_vector_view_4_selected_year_usage_values)));
    }

void MyMainWindow::on_view_4_previous_year_push_button_clicked()
    {
    m_uint_view_4_selected_year--;

    update_view_4_year();

    m_ptr_view_4_next_year_push_button->setEnabled(true);
    m_ptr_view_4_next_year_push_button->setObjectName(QString::fromUtf8("m_ptr_view_4_next_year_push_button"));
    //setAppStyle();
    setWidgetStyle(*m_ptr_view_4_next_year_push_button);
    }

void MyMainWindow::on_view_4_next_year_push_button_clicked()
    {
    m_uint_view_4_selected_year++;

    update_view_4_year();

    if (m_uint_view_4_selected_year == QDate::currentDate().year())
        {
        m_ptr_view_4_next_year_push_button->setEnabled(false);
        m_ptr_view_4_next_year_push_button->setObjectName(QString::fromUtf8("m_ptr_view_4_next_year_push_button__disabled"));
        //setAppStyle();
        setWidgetStyle(*m_ptr_view_4_next_year_push_button);
        }
    }

void MyMainWindow::setAppStyle()
    {
//    QFile file(":/styles.qss");
//    file.open(QFile::ReadOnly);
//    setStyleSheet(file.readAll());
         setStyleSheet(m_qstring_array_stylesheet);
    }

void MyMainWindow::repopulate_month_usage_data(std::vector<VectorOfUsageDataForOtherAndSpecificSources> &vector_vector_view_month_usage_values)
    {
    // Clear out the vector of usage data vector

    vector_vector_view_month_usage_values.clear();

    // Create 30 vectors of data in the array, one vector per day in a max 31 day month.

    vector_vector_view_month_usage_values.resize(42);

    // Looping over each of the 30 days, grab all the usage data for the currently selected month for each day

    for (std::vector<VectorOfUsageDataForOtherAndSpecificSources>::iterator iterator_vector_daily_usage_data = vector_vector_view_month_usage_values.begin();
         iterator_vector_daily_usage_data != vector_vector_view_month_usage_values.end();
         iterator_vector_daily_usage_data++)
        {
        // Get usage data for the selected month, year, and current date (ordinal value starting at 0 upto 31) for all the sources and put it into the vector representing
        // data for the current day.

        MyDataSource::get_daily_month_usage_data(iterator_vector_daily_usage_data - vector_vector_view_month_usage_values.begin(),
                                                 m_uint_view_3_selected_month,
                                                 m_uint_view_3_selected_year,
                                                 *iterator_vector_daily_usage_data);
        }
    }

void MyMainWindow::get_view_3_usage_data(const bool bool_new_previous_month_data,
                                         const bool bool_new_selected_month_data,
                                         const bool bool_new_next_month_data)
    {
    if (bool_new_previous_month_data &&
        bool_new_selected_month_data &&
        bool_new_next_month_data)
        {
        //qDebug() << "Repopulating all three month data vectors\n";

        repopulate_month_usage_data(m_vector_vector_view_3_previous_month_usage_values);
        repopulate_month_usage_data(m_vector_vector_view_3_selected_month_usage_values);
        repopulate_month_usage_data(m_vector_vector_view_3_next_month_usage_values);
        }

    else
        {
        if ((!bool_new_previous_month_data) &&
            (!bool_new_selected_month_data))
            {
            //qDebug() << "Repopulating next month data vector\n";

            m_vector_vector_view_3_previous_month_usage_values = m_vector_vector_view_3_selected_month_usage_values;
            m_vector_vector_view_3_selected_month_usage_values = m_vector_vector_view_3_next_month_usage_values;
            repopulate_month_usage_data(m_vector_vector_view_3_next_month_usage_values);
            }

        else if ((!bool_new_next_month_data) &&
                 (!bool_new_selected_month_data))
            {
            //qDebug() << "Repopulating previous month data vector\n";

            m_vector_vector_view_3_next_month_usage_values = m_vector_vector_view_3_selected_month_usage_values;
            m_vector_vector_view_3_selected_month_usage_values = m_vector_vector_view_3_previous_month_usage_values;
            repopulate_month_usage_data(m_vector_vector_view_3_previous_month_usage_values);
            }

        else
            {
            //qDebug() << "Wierd... should not be here... line " << __LINE__ << " of file " __FILE__ << "\n";
            }
        }
    }

void MyMainWindow::update_view_3_interactive_segmented_bar_with_data()
    {
    std::vector<unsigned int> vector_cumulative_usages_per_source;

    get_cumulative_time_period_usages(vector_cumulative_usages_per_source,
                                      CurrentActiveMonth->m_vector_vector_view_selected_day_usage_values);

    m_ptr_view_3_interactive_segmented_bar->set_usage_per_source(vector_cumulative_usages_per_source);
    }

void MyMainWindow::get_view_4_usage_data()
    {
    // Clear out the vector of usage data vector

    m_vector_vector_view_4_selected_year_usage_values.clear();

    // Create 12 vectors of data in the array, one vector per month

    m_vector_vector_view_4_selected_year_usage_values.resize(12);

    // Looping over each of the 12 months, grab all the usage data for the currently selected year for each month

    for (std::vector<VectorOfUsageDataForOtherAndSpecificSources>::iterator iterator_vector_monthly_usage_data = m_vector_vector_view_4_selected_year_usage_values.begin();
         iterator_vector_monthly_usage_data != m_vector_vector_view_4_selected_year_usage_values.end();
         iterator_vector_monthly_usage_data++)
        {
        // Get usage data for the selected month and year for all the sources and put it into the vector representing
        // data for the current month.

        MyDataSource::get_monthly_year_usage_data(iterator_vector_monthly_usage_data - m_vector_vector_view_4_selected_year_usage_values.begin(),
                                                  m_uint_view_4_selected_month,
                                                  m_uint_view_4_selected_year,
                                                  *iterator_vector_monthly_usage_data);
        }
    }

void MyMainWindow::update_view_4_interactive_segmented_bar_with_data()
    {
    std::vector<unsigned int> vector_cumulative_usages_per_source;

    get_cumulative_time_period_usages(vector_cumulative_usages_per_source,
                                      m_vector_vector_view_4_selected_year_usage_values);

    m_ptr_view_4_interactive_segmented_bar->set_usage_per_source(vector_cumulative_usages_per_source);
    }


void MyMainWindow::slot_view3_dateSelected(QDate dt)
{
//    qDebug() << " Call to Day click";
    if(dt.operator <=(QDate::currentDate()))
    {
//        qDebug()  << "inside day click";
       m_ptr_tab_widget->setCurrentIndex(1);
       on_set_view_2_date(dt);
    }
}

void MyMainWindow::setWidgetStyle(QWidget &target_widget)
    {
        target_widget.setStyleSheet(m_qstring_array_stylesheet);
    }
