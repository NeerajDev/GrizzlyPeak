#ifndef USAGEGRADIENTCIRCLE_H
#define USAGEGRADIENTCIRCLE_H

#include <QWidget>
#include <QTimer>
#include <vector>
#include <utility>
#include "Constants.h"

typedef std::vector<double> VectorOfRGBAValues;
typedef std::pair<double, VectorOfRGBAValues> GradientStopRGBAVectorValuesPair;

class UsageGradientCircle : public QWidget
    {
    Q_OBJECT

    public:

        UsageGradientCircle(const unsigned int uint_source_number,
                            const QString &qstr_name,
                            const std::vector<GradientStopRGBAVectorValuesPair> &vector_gradient_stops,
                            QWidget *ptr_parent = NULL);

        void set_usage(const unsigned int uint_new_usage);

        unsigned int get_current_usage() const
            {
            return m_uint_current_usage;
            }

        void apply_usage_delta(const int int_delta);

    public slots:

        void on_animation_timer_update();

    signals:

        void source_circle_animation_done(const unsigned int uint_source_number);

    protected:

        void paintEvent(QPaintEvent *ptr_event);

    private:

        void animate_size_change(const unsigned int uint_new_size);
        void resize_and_recenter(const unsigned int uint_new_size);

        QTimer *m_ptr_animation_timer;

        int m_int_total_change_in_circle_size;
        unsigned int m_uint_animation_start_size;
        unsigned int m_uint_total_frames;
        unsigned int m_uint_current_frame_count;

        unsigned int m_uint_current_usage;

        const QString m_qstr_name;

        const unsigned int m_uint_source_number;

        QRadialGradient m_radial_gradient;
    };

#endif // USAGEGRADIENTCIRCLE_H
