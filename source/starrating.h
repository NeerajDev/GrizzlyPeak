/* This class provides specified style to the Month view dates through paint method.
*/
#ifndef STARRATING_H
#define STARRATING_H

#include <QMetaType>
#include <QPointF>
#include <QVector>
#include <QPainter>
#include "Constants.h"


class StarRating
{
public:
    enum EditMode { Editable, ReadOnly };

    StarRating(int date = 1, int data = 5, int data_source = 10, SourcesEnum source_Name=SOURCE_1,int max_data =10, int max_source_data=10, int opacity = 0 ,SourcesEnum PrevSourceName = SOURCE_OTHER , int prev_source_data =0  , bool flag_future_date= false  );

    void paint(QPainter *painter, const QRect &rect,
               const QPalette &palette, EditMode mode) const;

    int data_from_source;
    int date;
    int data_total;
    int data_value;
    int max_data_total;
    int max_source_data;
int prev_source_data;
    int opacity;
    int flag_future_date;
    SourcesEnum sourceName;
    bool isPrevRectDefined;
       QRect  PrevRect;
       SourcesEnum PrevSourceName;
};

Q_DECLARE_METATYPE(StarRating)


#endif
