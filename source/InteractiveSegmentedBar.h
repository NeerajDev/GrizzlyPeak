#include "Constants.h"
#include "ui_InteractiveSegmentedBar.h"

class InteractiveSegmentedBar : public QWidget,
                                private Ui::InteractiveSegmentedBar
    {
    Q_OBJECT

    public:

        InteractiveSegmentedBar(const QString &qst_source_1_name,
                                const QString &qst_source_2_name,
                                const QString &qst_source_3_name,
                                const QString &qst_source_4_name,
                                QWidget *parent = 0);

    public slots:

        void set_source(const SourcesEnum enum_new_source);

        void set_usage_per_source(const std::vector<unsigned int> &vector_usage_per_source);

        void set_source_1_usage(const unsigned int uint_source_1_usage)
            {
            m_uint_source_1_usage = uint_source_1_usage;
            }

        void set_source_2_usage(const unsigned int uint_source_2_usage)
            {
            m_uint_source_2_usage = uint_source_2_usage;
            }

        void set_source_3_usage(const unsigned int uint_source_3_usage)
            {
            m_uint_source_3_usage = uint_source_3_usage;
            }

        void set_source_4_usage(const unsigned int uint_source_4_usage)
            {
            m_uint_source_4_usage = uint_source_4_usage;
            }

        void set_other_usage(const unsigned int uint_other_usage)
            {
            m_uint_other_usage = uint_other_usage;
            }

    signals:

        void signal_new_source_selected(const SourcesEnum enum_source_identifier);

    protected:

    private slots:

        void on_slider_released();
        void on_slider_value_changed(int int_new_value);
        void on_source_1_selected();
        void on_source_2_selected();
        void on_source_3_selected();
        void on_source_4_selected();
        void on_other_selected();

        void on_snap_slider();

        void reselect_selected_source();

    private:

        std::vector<unsigned int> m_vector_usage_per_source;

        const QString m_qst_source_1_name;
        const QString m_qst_source_2_name;
        const QString m_qst_source_3_name;
        const QString m_qst_source_4_name;

        unsigned int m_uint_source_1_usage;
        unsigned int m_uint_source_2_usage;
        unsigned int m_uint_source_3_usage;
        unsigned int m_uint_source_4_usage;
        unsigned int m_uint_other_usage;

        unsigned int m_uint_total_usage;
    };
