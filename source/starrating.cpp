#include <QtGui>
#include <math.h>
#include "starrating.h"



StarRating::StarRating(int dt, int dt_data, int data_source,SourcesEnum source,int max_data, int max_source_value, int op, SourcesEnum PrevSourceName_value , int prev_source_data_value, bool flag_future_date_value )
{
    date = dt;
    data_total = dt_data;
    data_from_source = data_source;
   sourceName = source;
   max_data_total = max_data;
   max_source_data = max_source_value;
   opacity = op;
   PrevSourceName = PrevSourceName_value ;
   prev_source_data =  prev_source_data_value;
   flag_future_date =flag_future_date_value;
}


//MEthod to paint the dates and data
//If date > 0, valid date
//Date = 100, Invalid date and carries daa for week view
//Date = -1 , not to be painted
//Date < -1, future date in current month , need to show its absolute form in diff color
void StarRating::paint(QPainter *painter, const QRect &rect,
                       const QPalette &palette, EditMode mode) const
{
    painter->save();

    //Border color of main cell
    painter->setPen(QColor::fromRgb(193, 68, 130));

    //Outer rectangle
    painter->translate(rect.x(), rect.y());

     //small rectangle only if valid date's data- invalid date recognized by passing 100 as date (used for weekly totals)
    if(date != 100)
    {
              painter->drawRect(0,0,rect.width(),rect.height());
              painter->setPen(QPen(QColor::fromRgb(85, 0, 42)));//(92,14,56)));
              if (flag_future_date)
                  {
              if(data_total > 0)
              {

                  int y = rect.height() - data_total;


                  QLinearGradient linearGrad1(QPointF(5, 0), QPointF(rect.width() ,0 ));
                      linearGrad1.setColorAt(1, QColor(49, 0,30, 255));
                      linearGrad1.setColorAt(0, QColor(121, 23, 74, 255) );

                      QPen borderRight(QColor(85,0,42));
                      painter->setPen(borderRight);
                      painter->drawRect(2,y-1,rect.width()-4 , rect.height()- y);


                   painter->fillRect(3, y, rect.width()-5, rect.height()- y, linearGrad1);


             }
               }
              if(data_from_source > 0 && sourceName != SOURCE_OTHER)
              {
                  //Set brush as per source
             SourcesEnum  sourcetoanimate;
             int data_value ;
             if (PrevSourceName != SOURCE_OTHER)
             {
                 sourcetoanimate = PrevSourceName;
                 data_value = prev_source_data;
             }else
             {
                  sourcetoanimate = sourceName ;
                  data_value = data_from_source;
             }

                QLinearGradient linearGrad(QPointF(5, 0), QPointF(rect.width() ,0 ));
                  if(sourcetoanimate == SOURCE_2)
                          {
                               linearGrad.setColorAt(0, QColor(241, 230,51,opacity));
                               linearGrad.setColorAt(1, QColor(134, 60,0,  opacity) );
                           }
                    else  if(sourcetoanimate == SOURCE_1)
                        {
                                 linearGrad.setColorAt(0, QColor(188,149,226, opacity));
                                 linearGrad.setColorAt(1, QColor(30,3,54 ,  opacity) );
                        }
                  else  if(sourcetoanimate == SOURCE_3)
                        {
                               linearGrad.setColorAt(0, QColor(130, 170, 79, opacity));
                              linearGrad.setColorAt(1, QColor(30,3,54 ,  opacity));
                       }
                   else  if(sourcetoanimate == SOURCE_4)
                      {
                                linearGrad.setColorAt(0, QColor(0, 204, 255, opacity));
                                linearGrad.setColorAt(1, QColor(30,3,54 ,  opacity  ) );
                     }


                    if (flag_future_date)
                       {
                          painter->fillRect(1, rect.height() - data_value , rect.width()-3, data_value, linearGrad);
                       }
              }
              //date text
              if(date > 0)
              {
                  painter->setPen(QPen(Qt::white));
                  if(date > 9)
                    painter->drawText((int)(rect.width()/2), (int)rect.height()/2 ,QString::number(date));
                  else
                      painter->drawText((int)(rect.width() - rect.width()/3), (int)rect.height()/2 ,QString::number(date));
              }
              else if(date <0)
              {
                   painter->setPen(QPen(QColor::fromRgb(193, 68, 130)));
                   if(qAbs(date) > 9)
                     painter->drawText((int)(rect.width()/2), (int)rect.height()/2 ,QString::number(qAbs(date)));
                   else
                    painter->drawText((int)(rect.width() - rect.width()/3), (int)rect.height()/2 ,QString::number(qAbs(date)));
              }

    }
    else //Display data for weekly totals
    {
                painter->drawLine(0,0,rect.width(),0);
                painter->drawLine(0,rect.height(),rect.width(),rect.height());
                painter->drawLine(rect.width()-16,0,rect.width()-16,rect.height());
                painter->setPen(QPen(QColor(255, 141, 197) ));
                QFont serifont( "Whitney" );
                serifont.setBold(true ) ;
                serifont.setPixelSize(15);
                painter->setFont( serifont );
                if(data_total >0)
                {
                    painter->drawText((int)(rect.width()- rect.width()/3 - 20), (int)rect.height()/2 ,QString::number(data_total));
                }
    }

       painter->restore();
       painter->translate(0.0,0.0);

}

