#include "BarChartSingleBar.h"
#include "Constants.h"

BarChartSingleBar::BarChartSingleBar(const QString &qstr_time_text,
                                     QWidget *parent)
                  :QWidget(parent)
    {
    setupUi(this);

    m_time_label->setText(qstr_time_text);
    }
void BarChartSingleBar::mouseMoveEvent(QMouseEvent *e)
{

    emit(signal_mousePressed(e));
}

void BarChartSingleBar::mousePressEvent(QMouseEvent *e)
{

     emit (signal_mouseDown(e));
}
