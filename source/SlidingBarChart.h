#include <vector>
#include <QTimer>
#include "Constants.h"
#include "ui_SlidingBarChart.h"
#include "BarChartSingleBar.h"
#include "MyDataSource.h"
#include "CarouselControl.h"

class SlidingBarChart : public QWidget,
                        private Ui::SlidingBarChart
    {
    Q_OBJECT

    public:

        SlidingBarChart(const std::vector<QString> &vector_x_axis_labels,
                        const unsigned int uint_number_of_bars,
                        QWidget *parent = 0);

    public slots:

        void set_selected_source(const SourcesEnum enum_selected_source = SOURCE_NONE);
        void set_source_usage_totals(const std::vector<VectorOfUsageDataForOtherAndSpecificSources> &vector_vector_source_usages);

    signals:

        void total_bars_growth_animation_done();
        void source_bars_growth_animation_done();
        void source_bars_fadeout_done();

    protected:

        void recalculate_source_usage_totals_per_bar_and_maximum();
        void set_new_y_axis_percentile_data_labels();
        void setAppStyle();
        void animate_total_bar_growth();
        void animate_source_bar_growth();
        void animate_source_bar_fadeout();

        void set_non_source_sizes();
        void set_source_sizes();

    private slots:

        void on_total_bar_growth_animation_timer_update();
        void on_source_bar_growth_animation_timer_update();
        void on_source_bar_fadeout_animation_timer_update();

    private:

        QTimer *m_ptr_total_bar_growth_animation_timer;
        QTimer *m_ptr_source_bar_growth_animation_timer;
        QTimer *m_ptr_source_bar_fadeout_animation_timer;

        std::vector<BarChartSingleBar *> m_vector_data_bar_widgets;
        const unsigned int m_uint_number_of_bars;
        SourcesEnum m_enum_selected_source;

        std::vector<unsigned int> m_vector_total_data_bar_animated_destination_sizes;
        unsigned int m_uint_total_bar_growth_animation_start_size;
        unsigned int m_uint_total_bar_growth_total_frames;
        unsigned int m_uint_total_bar_growth_current_frame_count;

        std::vector<unsigned int> m_vector_source_data_bar_animated_destination_sizes;
        unsigned int m_uint_source_bar_growth_animation_start_size;
        unsigned int m_uint_source_bar_growth_total_frames;
        unsigned int m_uint_source_bar_growth_current_frame_count;

        unsigned int m_uint_source_bar_fadeout_total_frames;
        unsigned int m_uint_source_bar_fadeout_current_frame_count;

        static void set_object_opacity(QWidget &qwidget_target,
                                        const double double_new_opacity);

        // There should be as many vectors below as there are bars

        std::vector<VectorOfUsageDataForOtherAndSpecificSources> m_vector_vector_source_usages;

        VectorOfUsageDataForOtherAndSpecificSources m_vector_source_usage_totals;

        unsigned int m_uint_maximum_source_usage_total;
    };
