#include "MonthView.h"
#include "ui_MonthView.h"
#include <QDebug>
#include <MyDataSource.h>
#include <Constants.h>

//Constructor
MonthView::MonthView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MonthView)
{
    ui->setupUi(this);

    setStyleSheet("background-color:green;");
opacity = 255;
       this_width = 650;
       this_height = 424;



        //Set Dates table structure
           ui->tblDates->setRowCount(6);
           ui->tblDates->setColumnCount(8);
           ui->tblDates->horizontalHeader()->setVisible(false);
           ui->tblDates->verticalHeader()->setVisible(false);
           ui->tblDates->setSelectionMode(QAbstractItemView::NoSelection);

           ui->tblDates->setStyleSheet("selection-background-color: rgba(128, 128, 128, 40);");
           connect(ui->tblDates, SIGNAL(cellClicked(int,int)), this, SLOT(slot_dateSelected(int,int)));
           ui->tblDates->verticalHeader()->setDefaultSectionSize( 20 );

           //Set Weekdays table structure
           ui->tblHeader->setRowCount(1);
           ui->tblHeader->setColumnCount(8);
           ui->tblHeader->horizontalHeader()->setVisible(false);
           ui->tblHeader->verticalHeader()->setVisible(false);


      //Connect signals
//           connect(ui->pushButton,SIGNAL(clicked()),this, SLOT(PreviousClicked()));
//           connect(ui->pushButton_2,SIGNAL(clicked()),this, SLOT(NextClicked()));

              this->locale = new QLocale(QLocale::English, QLocale::UnitedStates);


           this->setStartDate(QDate::currentDate());
          this->setEndDate(QDate::currentDate());
           SetWeekDays();

            ui->pushButton->setVisible(false);
            ui->pushButton_2->setVisible(false);
            ui->labelHeader->setVisible(false);

            //Set row height

            for(int i = 0; i <6;i++)
            {
                ui->tblDates->setRowHeight(i,54);
            }
            ui->tblDates->setItemDelegate(new  StarDelegate);
            source_name = SOURCE_OTHER;
            prev_source_name = SOURCE_OTHER;
            m_ptr_growth_animation_timer =new QTimer(this);
            m_ptr_growth_animation_timer->setInterval(VIEW_3_MONTH_ANIMATION_INTERVAL );
            connect(m_ptr_growth_animation_timer, SIGNAL(timeout()), this, SLOT(on_growth_animation_timer_update()));
 }

 MonthView::~MonthView()
 {
     delete ui;
 }

 //Slot that handles the date selection in the view.
 void MonthView::slot_dateSelected(int row, int column)
 {

        QTableWidgetItem *item = ui->tblDates->item(row,column);
        emit(DateChanged(QDate::fromString(item->whatsThis())));
 }

//Slot to update font size, in case required to be reset
 void  MonthView::slot_updateFontSize(int  size, int itemSpacing)
 {
         //Dates table
         QFont font_dates = ui->tblDates->font();
         font_dates.setPointSize(size);
         ui->tblDates->setFont(font_dates);
         ui->tblDates->verticalHeader()->setDefaultSectionSize(itemSpacing );
         ui->tblDates->horizontalHeader()->setDefaultSectionSize(itemSpacing );

         //Header table
         QFont font_header = ui->tblHeader->font();
         font_header.setPointSize(size);
         ui->tblHeader->setFont(font_header);
         ui->tblHeader->verticalHeader()->setDefaultSectionSize(itemSpacing );
         ui->tblHeader->horizontalHeader()->setDefaultSectionSize(itemSpacing );


         //Header Label
         QFont font_labelheader = ui->labelHeader->font();
         font_labelheader.setPointSize(size+1);
         ui->labelHeader->setFont(font_labelheader);

 }

 //method to set data source
 void MonthView::setDataSource(const std::vector<VectorOfUsageDataForOtherAndSpecificSources> &vector_vector_view_selected_day_usage_values_par)
 {

     m_vector_vector_view_selected_day_usage_values = vector_vector_view_selected_day_usage_values_par;


     MaxUnit =0;
     for (int i=0;i <42; i++)
         {
           if (m_vector_vector_view_selected_day_usage_values[i][0] + m_vector_vector_view_selected_day_usage_values[i][1] + m_vector_vector_view_selected_day_usage_values[i][2] + m_vector_vector_view_selected_day_usage_values[i][3] + m_vector_vector_view_selected_day_usage_values[i][4]    > MaxUnit)
               {
               MaxUnit =m_vector_vector_view_selected_day_usage_values[i][0] + m_vector_vector_view_selected_day_usage_values[i][1] + m_vector_vector_view_selected_day_usage_values[i][2] + m_vector_vector_view_selected_day_usage_values[i][3] + m_vector_vector_view_selected_day_usage_values[i][4]  ;
           }
      }



 }

 //Slot to create calendar
 void MonthView::slot_createCalendar(QDate dt, SourcesEnum sourceName, bool toFillData)
 {

     source_name = sourceName;
     currentSource = sourceName;
     prev_source_name = SOURCE_OTHER;
     StartDate = dt;
     CreateCalendar(toFillData);
 }

 //Slot to update control size with specified parameters.
 void MonthView:: slot_updateSize(qreal width, qreal height)
         {
                         resize(width, height);

                         this_width = width;
                         this_height = height;


                         ui->tblDates->setGeometry(width/16,height/6,width/1.92,height/2.9);

                         ui->tblHeader->setGeometry(width/16,height/10,width/1.92,height/14.5);
                         ui->MainFrame->setGeometry(width/3.4,height/2.7,width/1.5,height/1.79);


                         ui->pushButton_2->setGeometry(width/2.07,0,width/6.75, height/8.5);

                         ui->pushButton->setGeometry(width/27,0,width/6.75, height/8.5);

                         int x_header =   (ui->pushButton_2->geometry().x())/2.5;
                         ui->labelHeader->setGeometry(x_header,ui->pushButton_2->geometry().height()/5 ,width/4, height/11.9);
                         ui->labelHeader->setAlignment(Qt::AlignRight | Qt::AlignTop);
         }

 //Method to select dates, if date selection is enabled.
 void MonthView::SelectDates(int row, int column)
         {
                 if(!EnableDateSelection)
                 {
                         return;
                 }

                 QDate currentDate(QDate :: fromString(ui->tblDates->item(row,column)->whatsThis()));
                 //For Start day control
                 if(IsStartDate)
                 {
                         int currentCol = column;
                         if(currentDate <= EndDate)
                         {
                                 int colEnd = 7;
                                 for(int r = row; r <= rowEndDate; r++)
                                 {
                                         if(r == rowEndDate)
                                         {
                                                 colEnd = colEndDate;
                                         }
                                         if(r > row)
                                         {
                                                 currentCol = 1;
                                         }

                                         if(r == row)
                                         {
                                                 currentCol = column;
                                         }

                                         for(int c = currentCol; c <= colEnd; c++)
                                         {
                                                 if(!ui->tblDates->item(r,c)->isSelected())
                                                 {
                                                         ui->tblDates->setItemSelected(ui->tblDates->item(r,c),true);
                                                 }
                                         }

                                 }
                         }
                         else
                         {
                                 ui->tblDates->selectedItems().clear();
                                 this->setEndDate(currentDate);
                                 rowEndDate  = row;
                                 colEndDate = column;
                                 ui->tblDates->setItemSelected(ui->tblDates ->item(row,column),true);
                         }

                         this->setStartDate(currentDate);
                         rowStartDate = row;
                         colStartDate = column;

                 }
                 else
                 {
                         //Return if end date is invalid
                         if(this->EndDate.isValid())
                         {
                                 int currentCol = colStartDate;
                                 if(currentDate >= StartDate)
                                 {
                                         int colEnd = 7;
                                         for(int r = rowStartDate; r <= row; r++)
                                         {
                                                 if(r == row)
                                                 {
                                                         colEnd = column ;
                                                 }
                                                 if(r > rowStartDate)
                                                 {
                                                         currentCol = 1;
                                                 }

                                                 if(r == rowStartDate)
                                                 {
                                                         currentCol = colStartDate ;
                                                 }

                                                 for(int c = currentCol; c <= colEnd; c++)
                                                 {
                                                         if(!ui->tblDates->item(r,c)->isSelected())
                                                         {
                                                                 ui->tblDates->setItemSelected(ui->tblDates->item(r,c),true);
                                                         }
                                                 }

                                         }
                                 }
                                 else
                                 {
                                         ui->tblDates->selectedItems().clear();

                                         this->StartDate = currentDate;
                                         rowStartDate  = rowEndDate = row;
                                         colStartDate = colEndDate = column;
                                         ui->tblDates->setItemSelected(ui->tblDates ->item(row,column),true);
                                 }
                                         this->setEndDate(currentDate);
                                         rowEndDate = row;
                                         colEndDate = column;
                         }
                 }
         }

 //Method to set week days
 void MonthView::SetWeekDays()
         {

                 //Headers
                 int weekDay = 1;

                 for(int i = 0 ;i < 7;i++)
                 {
                         //Set column width
                         ui->tblHeader->setColumnWidth(i,60);
                         ui->tblDates->setColumnWidth(i,60);

                         QTableWidgetItem *item = new QTableWidgetItem();

                         QString name = QDate::shortDayName(weekDay++);
                         item->setText(name);
                          item->setTextAlignment(Qt::AlignTop | Qt::AlignHCenter);
                          if( i >4)
                          {
                                item->setBackgroundColor(QColor::fromRgb(201,72,135));
                                item->setForeground(QBrush(QColor::fromRgb(136,36,89)));
                          }

                         ui->tblHeader->setItem(0,i,item);
                 }

                 //Add the column for weekly totals
                 ui->tblHeader->setColumnWidth(7,120);
                 ui->tblDates->setColumnWidth(7,120);
                 QTableWidgetItem *item = new QTableWidgetItem();
                  item->setText("Weekly Totals");
                  item->setTextAlignment(Qt::AlignTop | Qt::AlignHCenter);
                 ui->tblHeader->setItem(0,7,item);

         }

 //Updates month view as the selected source is changed from interactive bar.
void  MonthView::UpdateSourceData(SourcesEnum source)
{
    m_ptr_growth_animation_timer->stop();
   // bool foundToday = false;
//opacity= 255;
//    for(int row = 0; row < 6; row++)
//    {
//            for(int col = 0; col < 7; col++)
//               {
////                    int data = (50 * ( m_vector_vector_view_selected_day_usage_values[(row * 7) + col ][0] + m_vector_vector_view_selected_day_usage_values[(row * 7) + col ][1] + m_vector_vector_view_selected_day_usage_values[(row * 7) + col ][2] + m_vector_vector_view_selected_day_usage_values[(row * 7) + col ][3] + m_vector_vector_view_selected_day_usage_values[(row * 7) + col ][4]))  /MaxUnit     ;
////                    int sourceData ;
////                    sourceData  = (50 * ( m_vector_vector_view_selected_day_usage_values[(row * 7) + col ][source]))/MaxUnit  ;//    qrand() % (((data/2) + 1) - 2) + 2;  // data % 2;

//                    QTableWidgetItem *item = ui->tblDates->item(row,col);
//                    if(QDate::fromString(item->whatsThis()).operator >(QDate::currentDate())) //Return if reached the future date.
//                    {
//                        foundToday = true;
//                        break;
//                    }
//                    QVariant v =  item->data(0);
//                    StarRating r = v.value<StarRating>();
//                }

//            if(foundToday)
//                break;
//        }


    currentSource = source;
    m_ptr_growth_animation_timer->start();
}

//  void MonthView::PreviousClicked()
//         {
//                 StartDate = StartDate.addMonths(-1);
//                 CreateCalendar();
//         }

//         void MonthView::NextClicked()
//         {
//                 StartDate = StartDate.addMonths(1);
//                 CreateCalendar();
//         }

//         void MonthView::Done()
//         {

//                 if(ui->tblDates->currentIndex().isValid())
//                 {
//                            int col  = ui->tblDates->currentIndex().column();
//                            int row = ui->tblDates->currentIndex().row();

//                            emit(DateChanged(QDate::fromString(ui->tblDates->item(row,col)->whatsThis())));

//                 }
//                 this->close();
//         }



//Method to set dates in Calendar
         void MonthView::SetDatesInCalendar(QDate dtStartDate, QDate dtEndDate, bool toFillData)
         {
                m_ptr_growth_animation_timer->stop();

                 int dayStartDate = dtStartDate.day();
                 int StartMonthDays = dtStartDate.daysInMonth();//Total days in selected month


                 int dayCurrMonth = 1;
                 int dayNextMonth = 1;
                   all_week_data = 0;
                 qreal week_total = 0;
                 int data = 0;
                 int sourceData = 0;

                 for(int row = 0; row < 6; row++)
                 {
                          week_total = 0; //add_Weekly_total = true;


                         for(int col = 0; col < 7; col++)
                            {

                              if ( m_vector_vector_view_selected_day_usage_values.size() != 42)
                             {
                                  data = 0 ; sourceData =0;
                              } else
                              {
                              data = (qreal)((qreal)(50 * ( m_vector_vector_view_selected_day_usage_values[(row * 7) + col ][0] + m_vector_vector_view_selected_day_usage_values[(row * 7) + col ][1] + m_vector_vector_view_selected_day_usage_values[(row * 7) + col ][2] + m_vector_vector_view_selected_day_usage_values[(row * 7) + col ][3] + m_vector_vector_view_selected_day_usage_values[(row * 7) + col ][4]  ) ))/MaxUnit     ; //    qrand() % ((ui->tblDates->rowHeight(0) + 1) - 5) + 5;
                              sourceData  = (qreal)((qreal)(50 * ( m_vector_vector_view_selected_day_usage_values[(row * 7) + col ][source_name] )))/MaxUnit;//    qrand() % (((data/2) + 1) - 2) + 2;  // data % 2;
                          }
                                //Previous Month
                                 if(dayStartDate <= StartMonthDays)
                                 {
                                          QTableWidgetItem *item = new QTableWidgetItem();

                                          int day = dayStartDate++;
                                          item->setData(0,
                                                         qVariantFromValue(StarRating(day,0,0, source_name,data,sourceData)));

                                          if(dtStartDate.day() > 1)//When 3 months are displayed in Calendar, only then prev month date is grayed out
                                          {

                                              item->setData(0,
                                                             qVariantFromValue(StarRating(0,0,0, source_name,data,sourceData)));
                                              data = 0;// Make it zero as not to be added with total
                                          }

                                          item->setTextAlignment(Qt::AlignTop | Qt::AlignRight);

                                          QDate dt(dtStartDate.year(),dtStartDate.month(), locale->toInt(QString::number(day)));
                                          QString str(dt.toString());
                                          item->setWhatsThis(str);

                                          if(dt.operator >(QDate::currentDate()))
                                           {

                                               data= 0;
                                              if(dt.month() == QDate::currentDate().month() && dt.month() == StartDate.month()) //compare to current as well as calendar's month
                                               {
                                                 item->setData(0,
                                                              qVariantFromValue(StarRating(-day,data,0, source_name,data,0)));
                                               }
                                               else
                                               {
                                                   item->setData(0,
                                                                qVariantFromValue(StarRating(0,data,0, source_name,data,0)));
                                               }
                                           }
                                          ui->tblDates->setItem(row,col,item);


                                 }
                                 else
                                 {
                                         QDate date = dtStartDate.addMonths(1);
                                         int CurrentMonthDays = date.daysInMonth();
                                         //Current month
                                         if(dayCurrMonth <= CurrentMonthDays)
                                         {
                                                  QTableWidgetItem *item = new QTableWidgetItem();
                                                  int day = dayCurrMonth++;
                                                   item->setData(0,
                                                                  qVariantFromValue(StarRating(day,0,0, source_name,data,sourceData)));


                                                  if(dtStartDate.day() == 1)//When 2 months are displayed in Calendar, only then current month date is grayed out
                                                  {

                                                      item->setData(0,
                                                                     qVariantFromValue(StarRating(0,0,0, source_name,data,sourceData)));
                                                      data = 0;// Make it zero as not to be added with total

                                                  }

                                                  item->setTextAlignment(Qt::AlignTop | Qt::AlignHCenter);
                                                  QDate dt(date.year(),date.month(), locale->toInt(QString::number(day)));
                                                  QString str(dt.toString());
                                                  item->setWhatsThis(str);

                                                  if(dt.operator >(QDate::currentDate()))
                                                   {

                                                       data= 0;
                                                      if(dt.month() == QDate::currentDate().month() && dt.month() == StartDate.month()) //compare to current as well as calendar's month
                                                       {
                                                         item->setData(0,
                                                                      qVariantFromValue(StarRating(-day,data,0, source_name,data,0)));
                                                       }
                                                       else
                                                       {
                                                           item->setData(0,
                                                                        qVariantFromValue(StarRating(0,data,0, source_name,data,0)));
                                                       }
                                                   }

                                                 ui->tblDates->setItem(row,col,item);


                                         }
                                         //Next month
                                         else
                                         {
                                                 if(dayNextMonth <= dtEndDate.day())
                                                 {
                                                         QTableWidgetItem *item = new QTableWidgetItem();
                                                         item->setForeground(QBrush(Qt::gray,Qt::SolidPattern));//Always grayed out

                                                         item->setData(0,
                                                                        qVariantFromValue(StarRating(0,0,0, source_name,data,sourceData)));

                                                         data = 0;// Make it zero as not to be added with total

                                                         item->setTextAlignment(Qt::AlignTop | Qt::AlignHCenter);
                                                         int day = dayNextMonth++;
                                                         QDate dt(dtEndDate.year(),dtEndDate.month(), locale->toInt(QString::number(day)));
                                                          QString str(dt.toString());
                                                          item->setWhatsThis(str);

                                                          if(dt.operator >(QDate::currentDate()))
                                                       {

                                                           data= 0;
                                                          if(dt.month() == QDate::currentDate().month() && dt.month() == StartDate.month()) //compare to current as well as calendar's month
                                                           {
                                                             item->setData(0,
                                                                          qVariantFromValue(StarRating(-day,data,0, source_name,data,0)));
                                                           }
                                                           else
                                                           {
                                                               item->setData(0,
                                                                            qVariantFromValue(StarRating(0,data,0, source_name,data,0)));
                                                           }
                                                       }
                                                          ui->tblDates->setItem(row,col,item);


                                                 }

                                         }

                                 }
                                 //For weekDays total
                                 if(data > 0)
                                 {
                                     week_total += (m_vector_vector_view_selected_day_usage_values[(row * 7) + col ][source_name]) ;
                                 }
  //                               week_total +=  m_vector_vector_view_selected_day_usage_values[(row * 7) + col ][0] + m_vector_vector_view_selected_day_usage_values[(row * 7) + col ][1] + m_vector_vector_view_selected_day_usage_values[(row * 7) + col ][2] + m_vector_vector_view_selected_day_usage_values[(row * 7) + col ][3] + m_vector_vector_view_selected_day_usage_values[(row * 7) + col ][4]  ;//data;
                         }


                         all_week_data += week_total;
                         QTableWidgetItem *item = new QTableWidgetItem();
                         item->setData(0,
                                        qVariantFromValue(StarRating(100,week_total,0, source_name,data,sourceData)));
                         item->setTextAlignment(Qt::AlignTop | Qt::AlignHCenter);
                          ui->tblDates->setItem(row,7,item);

                 }
                 if(toFillData)
                   {
                      m_ptr_growth_animation_timer->start();
                   }
         }


         //Slot to fill datat in month view
         void MonthView:: slot_fillData()
         {
            ResetAnimation= true;
            prev_source_name = SOURCE_OTHER;
            opacity=20;
            m_ptr_growth_animation_timer->start();
         }

         //Method to create calendar with an option to or not to fill data in it.
        void MonthView::CreateCalendar(bool toFillData)
         {

                 //Get weekday of 1st of selected Date
                 int day1 = QDate(StartDate.year(),StartDate.month(),1).dayOfWeek();   //SelectedDate.dayOfWeek();

                 QDate dtStart,dtEnd;

                 if(day1 == 1)//If month starts on day 1 of the week.
                 {
                         dtStart.setDate(StartDate.year(),StartDate.month(),1);

                         QDate nextMonth = StartDate.addMonths(1);

                         int endMonthDays = (42) - (StartDate.daysInMonth());

                         dtEnd.setDate(nextMonth.year(),nextMonth.month(), endMonthDays);
                 }
                 else
                 {
                         QDate prevMonth = StartDate.addMonths(-1);
                         int prevMonthDays = prevMonth.daysInMonth();

                         dtStart.setDate(prevMonth.year(),prevMonth.month(), prevMonthDays - day1 + 2 );


                         QDate nextMonth = StartDate.addMonths(1);
                         int endMonthDays = (42) - (day1 + StartDate.daysInMonth()) + 1;

                         dtEnd.setDate(nextMonth.year(),nextMonth.month(),endMonthDays);
                 }

                 ui->labelHeader->setText(QDate::shortMonthName(StartDate.month()) + ", " + QString::number(StartDate.year()));

                 SetDatesInCalendar(dtStart, dtEnd, toFillData);


         }


         void MonthView::setStartDate(QDate Date)
         {
                 StartDate = Date;

         }


         QDate MonthView::getStartDate() const
         {
                 return StartDate;
         }

         void MonthView::setEndDate(QDate Date)
         {
                 EndDate = Date;
         }


         void MonthView::setIsStartDate(bool IsStarting)
         {
                 IsStartDate = IsStarting;
         }

         bool MonthView::getIsStartDate() const
         {
                 return IsStartDate;
         }

         QDate MonthView::getEndDate() const
         {
                 return EndDate;
         }

         QDate MonthView::getSelectedDate() const
         {
                 return SelectedDate;
         }

         void MonthView::setSelectedDate(QDate Date)
         {
                 SelectedDate = Date;
         }

         void MonthView::setDateSelectionEnabled(const bool IsDateSelectionEnabled)
         {
                 EnableDateSelection = IsDateSelectionEnabled;
         }

         bool MonthView:: getDateSelectionEnabled() const
         {
                 return EnableDateSelection;
         }

         //Open month view
         void MonthView::Open()
         {
                 this->show();
         }

         //Method to get full week's data for display
         qreal MonthView:: getAllWeeksData()
         {
            return all_week_data;
         }

         //Mouse move event
         void MonthView::mouseMoveEvent(QMouseEvent *e)
         {
             emit(signal_mousePressed(e));
         }

         //Mouse press event.
         void MonthView::mousePressEvent(QMouseEvent *e)
         {
              emit (signal_mouseDown(e));
         }

         //Timer call to animate the graph bars.
         void MonthView::on_growth_animation_timer_update()
          {

             if (prev_source_name != SOURCE_OTHER )
             {
             if((opacity <= 255) && (opacity >= 20 ))
             {
                opacity -= 25;
             }else
             {
                if (opacity <= 20 )
                 {
                    opacity =20;

                }
                if (opacity >= 255)
                {
                    opacity = 255;
                }
                }
            }
             bool isAnimationinProgress = false;
            all_week_data = 0;

            int data;
             int sourceData;
             int weekly_total = 0;

             for(int row = 0; row < 6; row++)
             {
                  weekly_total = 0;
                     for(int col = 0; col < 7; col++)
                        {
                                 if ( m_vector_vector_view_selected_day_usage_values.size() != 42)
                                {
                                     break;
                                 }
                                 QTableWidgetItem *item = ui->tblDates->item(row,col);

                                 QVariant v =  item->data(0);
                                 StarRating r = v.value<StarRating>();
//                                  int data;
//                                  int sourceData;

                                  if (ResetAnimation)
                                  {
                                      data = 0;
                                      sourceData =0;
                                  }
                                 else
                                 {
                                     data =  r.data_total;
                                     sourceData = r.data_from_source;
                                }


                                 if (opacity> 20 && prev_source_name != SOURCE_OTHER )
                                 {
                                     isAnimationinProgress = true;
                                   sourceData = ((int)((qreal)(50 * ( m_vector_vector_view_selected_day_usage_values[(row * 7) + col ][prev_source_name] )))/MaxUnit );
                                   if (opacity < 50)
                                   {
                                       sourceData =0;
                                   }
                                 }
                                 else if(data <  ((int)((qreal)(50 * ( m_vector_vector_view_selected_day_usage_values[(row * 7) + col ][0] +  m_vector_vector_view_selected_day_usage_values[(row * 7) + col ][1] +  m_vector_vector_view_selected_day_usage_values[(row * 7) + col ][2] +  m_vector_vector_view_selected_day_usage_values[(row * 7) + col ][3] +  m_vector_vector_view_selected_day_usage_values[(row * 7) + col ][4]  )))/MaxUnit ) )
                                 {
                                         data++;
                                         isAnimationinProgress = true;
                                 }
                                 else if(sourceData <  ((int)((qreal)(50 * ( m_vector_vector_view_selected_day_usage_values[(row * 7) + col ][currentSource] )))/MaxUnit ))
                                 {
                                         sourceData++;

                                         isAnimationinProgress= true;
                                 }

                                  QDate dt = QDate::fromString(item->whatsThis());
                                  bool isfuturedate = false;
                                  if(dt.operator <= (QDate::currentDate()))
                                   {
                                       isfuturedate = true;
                                   }


                                   item->setData(0, qVariantFromValue(StarRating(r.date, data, sourceData, currentSource,r.max_data_total,r.max_source_data, opacity, prev_source_name, (qreal)((qreal)(50 * ( m_vector_vector_view_selected_day_usage_values[(row * 7) + col ][prev_source_name] )))/MaxUnit ,  isfuturedate)));

                                    if (opacity  <= 20)
                                    {
                                        opacity= 255;
                                        prev_source_name = SOURCE_OTHER;

                                    }
                                    if(sourceData >0 && isfuturedate)
                                    {
                                        weekly_total +=  m_vector_vector_view_selected_day_usage_values[(row * 7) + col ][currentSource] ;
                                    }
                          }

                    // if(weekly_total > 0)
                     {
                         all_week_data += weekly_total;
                         QTableWidgetItem *item_total = ui->tblDates->item(row, 7);
                         item_total->setData(0,
                                    qVariantFromValue(StarRating(100,weekly_total,0, source_name,data,sourceData)));
                      }

                 }
                     ResetAnimation= false;
                     if (isAnimationinProgress == false  )
                     {
                             prev_source_name =currentSource;
                             m_ptr_growth_animation_timer->stop();
                     }

                     emit(data_updated(all_week_data));
          }

