#include "ui_BarChartSingleBar.h"

class SlidingBarChart;

class BarChartSingleBar : public QWidget,
                          private Ui::BarChartSingleBar
    {
    Q_OBJECT

    public:

        BarChartSingleBar(const QString &qstr_time_text,
                          QWidget *parent = 0);

    public slots:

    signals:
           void signal_mousePressed(QMouseEvent*);
           void signal_mouseDown(QMouseEvent*);
       protected:
           void mousePressEvent(QMouseEvent *);
           void mouseMoveEvent(QMouseEvent *);


    private slots:

    private:

        friend class SlidingBarChart;
    };
