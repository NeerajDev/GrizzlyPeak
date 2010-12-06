#ifndef MONTHVIEW_H
#define MONTHVIEW_H

#include <QMouseEvent>
#include <QWidget>
#include <QDateTime>
#include <QLocale>
#include "starrating.h"
#include "stardelegate.h"
#include "Constants.h"
#include <QTimer>
#include "MyDataSource.h"

namespace Ui {
    class MonthView;
}

class MonthView : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QDate StartDate READ getStartDate WRITE setStartDate);
    Q_PROPERTY(QDate EndDate READ getEndDate WRITE setEndDate);
    Q_PROPERTY(QDate SelectedDate READ getSelectedDate WRITE setSelectedDate);
    Q_PROPERTY(bool IsStartDate READ getIsStartDate WRITE setIsStartDate);
    Q_PROPERTY(bool EnableDateSelection READ getDateSelectionEnabled WRITE setDateSelectionEnabled);

public:
            explicit MonthView(QWidget *parent = 0);
            ~MonthView();

            void setStartDate(const QDate StartDate);
            void setDataSource(const std::vector<VectorOfUsageDataForOtherAndSpecificSources> &vector_vector_view_selected_day_usage_values_par);

            QDate getStartDate() const;

            void setEndDate(const QDate EndDate);
            QDate getEndDate() const;

            void setSelectedDate(const QDate SelectedDate);
            QDate getSelectedDate() const;

            void setIsStartDate(const bool IsStartDate);
            bool getIsStartDate() const;

            void setDateSelectionEnabled(const bool EnableDateSelection);
            bool getDateSelectionEnabled() const;

            void Open();
            qreal getAllWeeksData();
            std::vector<VectorOfUsageDataForOtherAndSpecificSources> m_vector_vector_view_selected_day_usage_values;
            void UpdateSourceData(SourcesEnum);

private:
            Ui::MonthView *ui;
            QDate SelectedDate;
            QTimer *m_ptr_growth_animation_timer;

            int MaxUnit;
            bool ResetAnimation ;
            void CreateCalendar(bool toFillData=true);
            void SetWeekDays();
            void SetDatesInCalendar(QDate StartDate, QDate EndDate, bool toFillData=true);
            QDate StartDate;
            QDate EndDate;
            QLocale *locale;
            int rowStartDate;
            int colStartDate;
            int rowEndDate;
            int colEndDate;
            bool IsStartDate;
            bool EnableDateSelection;

            qreal this_width;
            qreal this_height;

             qreal all_week_data;
             SourcesEnum source_name;
             SourcesEnum prev_source_name;
             SourcesEnum currentSource ;
             int prev_source_data;
             int opacity;

private slots:

            void SelectDates(int, int);
            void slot_dateSelected(int, int);
           void on_growth_animation_timer_update();

signals:
            void DateChanged(QDate Date);
            void signal_mousePressed(QMouseEvent*);
            void signal_mouseDown(QMouseEvent*);
            void data_updated(int );

protected:
        void mouseMoveEvent(QMouseEvent *);
        void mousePressEvent(QMouseEvent *);


public slots:
            void slot_updateSize(qreal width, qreal height);
            void slot_updateFontSize(int  size, int itemSpacing);
            void slot_createCalendar(QDate dt, SourcesEnum source = SOURCE_OTHER, bool toFillData=true);
           void slot_fillData();

};

#endif // MONTHVIEW_H
