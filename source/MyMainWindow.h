#include <QTimer>
#include <QDate>
#include "ui_MyMainWindow.h"
#include "UsageGradientCircle.h"
#include "EditNoteDialog.h"
#include "ViewNoteDialog.h"
#include "MonthView.h"
#include "MyDataSource.h"
#include "InteractiveSegmentedBar.h"
#include "SlidingBarChart.h"

#include "CarouselControl.h"

typedef enum
    {
    CLOUDY,
    PARTLY_CLOUDY,
    RAIN,
    SUNNY,

    NUMBER_OF_WEATHER_CONDITIONS
    }
WeatherConditionEnum;

class MyMainWindow : public QWidget,
                     private Ui::MyMainWindow
    {
    Q_OBJECT

    public:

        MyMainWindow(const QString &qstr_source_1_name,
                     const QString &qstr_source_2_name,
                     const QString &qstr_source_3_name,
                     const QString &qstr_source_4_name,
                     const QString &qstr_chrome_option,
                     const unsigned int uint_initial_tab,
                     QWidget *parent = 0);

    public slots:

        void on_view_1_source_circle_animation_done(const unsigned int uint_source_number);

        void on_done_view_2_note_push_button_clicked();
        void on_edit_view_2_note_push_button_clicked();
        void on_set_view_2_date(const QDate &qdate_new_date);

        void on_set_view_3_month(const unsigned int uint_view_3_selected_month,
                                 const unsigned int uint_view_3_selected_year);
//        void on_source_changed(QString sourceName);

        void on_new_source_selected(const SourcesEnum enum_source_identifier);

    protected:

        static int get_view_1_random_delta_value();

        // Returns true if the note was found and false otherwise

        bool get_note_for_view_2_date_from_disk(QString &qstr_note_contents) const;

        QString get_note_filename_from_view_2_selected_date() const;

        void show_edit_note_dialog();
        void show_view_note_dialog();
        void paintEvent(QPaintEvent *);
        SourcesEnum CurrentSource;

        void get_view_2_usage_data();
//        unsigned int get_total_day_usage() const;
        void update_view_2_interactive_segmented_bar_with_data();

        void get_view_3_usage_data(const bool bool_new_previous_month_data,
                                   const bool bool_new_selected_month_data,
                                   const bool bool_new_next_month_data);
//        unsigned int get_total_month_usage() const;
        void update_view_3_interactive_segmented_bar_with_data();

        void get_view_4_usage_data();
//        unsigned int get_total_year_usage() const;
        void update_view_4_interactive_segmented_bar_with_data();

        unsigned int get_total_time_period_usage_usage(const std::vector<VectorOfUsageDataForOtherAndSpecificSources> &vector_vector_selected_time_pediod_usage_values) const;

        void get_cumulative_time_period_usages(std::vector<unsigned int> &vector_cumulative_usages_per_source,
                                               const std::vector<VectorOfUsageDataForOtherAndSpecificSources> &vector_vector_selected_time_period_usage_values) const;

    private slots:

        void on_tab_changed(const int index);
        void on_view_1_heartbeat();
        void on_clock_heartbeat();
        void on_home_button_clicked();

        void on_view_2_previous_day_push_button_clicked();
        void on_view_2_next_day_push_button_clicked();
        void on_view_2_note_push_button_clicked();
        void update_view_2_note_data();
        void update_view_2_date();
        void update_view_3_month(const bool bool_new_previous_month_data,
                                 const bool bool_new_selected_month_data,
                                 const bool bool_new_next_month_data);
        void on_view_3_previous_month_push_button_clicked();
        void on_view_3_next_month_push_button_clicked();

        void update_view_4_year();
        void on_view_4_previous_year_push_button_clicked();
        void on_view_4_next_year_push_button_clicked();

        void randomize_and_update_view_2_weather_temperature();
        void slot_view3_dateSelected(QDate);
        void repopulate_month_usage_data(std::vector<VectorOfUsageDataForOtherAndSpecificSources> &vector_vector_view_month_usage_values);
        void month_data_updated(int);
    private:

       CarouselControl *carousel_view3;
        bool m_bool_note_exists_for_selected_date;

        EditNoteDialog *m_ptr_edit_note_dialog;
        ViewNoteDialog *m_ptr_view_note_dialog;

        QTimer *m_ptr_view_1_heartbeat_timer;
        QTimer *m_ptr_clock_timer;

        InteractiveSegmentedBar *m_ptr_view_2_interactive_segmented_bar;
        QDate m_qdate_view_2_selected_date;

        unsigned int m_uint_view_3_selected_month;
        unsigned int m_uint_view_3_selected_year;

        InteractiveSegmentedBar *m_ptr_view_3_interactive_segmented_bar;

        unsigned int m_uint_view_4_selected_month;
        unsigned int m_uint_view_4_selected_year;

        InteractiveSegmentedBar *m_ptr_view_4_interactive_segmented_bar;

        WeatherConditionEnum m_enum_view_2_weather_condition;

        int m_int_view_2_high_temperature;
        int m_int_view_2_low_temperature;

        UsageGradientCircle *m_ptr_usage_1_circle;
        UsageGradientCircle *m_ptr_usage_2_circle;
        UsageGradientCircle *m_ptr_usage_3_circle;
        UsageGradientCircle *m_ptr_usage_4_circle;

        MonthView *m_ptr_view3_monthView;
        MonthView *m_ptr_view3_monthView_next;
        MonthView *m_ptr_view3_monthView_prev;
        MonthView *CurrentActiveMonth;


        SlidingBarChart *m_ptr_view_2_sliding_bar_chart_container;
        SlidingBarChart *m_ptr_view_4_sliding_bar_chart_container;

        std::vector<VectorOfUsageDataForOtherAndSpecificSources> m_vector_vector_view_2_selected_day_usage_values;

        std::vector<VectorOfUsageDataForOtherAndSpecificSources> m_vector_vector_view_3_previous_month_usage_values;
        std::vector<VectorOfUsageDataForOtherAndSpecificSources> m_vector_vector_view_3_selected_month_usage_values;
        std::vector<VectorOfUsageDataForOtherAndSpecificSources> m_vector_vector_view_3_next_month_usage_values;

        std::vector<VectorOfUsageDataForOtherAndSpecificSources> m_vector_vector_view_4_selected_year_usage_values;

        SourcesEnum m_enum_selected_source_identifier;

        void setAppStyle();
        void setWidgetStyle(QWidget &target_widget);

          QString m_qstring_array_stylesheet;
    };
