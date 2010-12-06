#ifndef COMMONUTILITY_H
#define COMMONUTILITY_H


#include <QString>
#include <QUuid>
#include <QSize>
#include <QColor>

enum Orientation
{
        Horizontal,
        Vertical
        //Grid //For testing
};


class CommonUtility
{
private:

        CommonUtility();
        CommonUtility(CommonUtility const& copy);
     //HPCommonUtility& operator=(HPCommonUtility const& copy);

public:

        static CommonUtility& getInstance()
        {
                static CommonUtility instance;
                return instance;
        }

        //The UID is unique only on windows platform
         QString getGUID();

         bool bool_isOpacityEffectOn;
         QSize size_touchSize;
         QSize size_minItemSize;
         QSize size_maxItemSize;
         QSize size_carouselSize;
         int int_itemSeparationGap;
         double dbl_scaleFactor;
         double dbl_radius;
         int int_rotationAngle;//When this is 0, then no arc effect

        Orientation orientation;
         QColor color_itemColor;
         bool bool_isInfiniteLoopOn;
};


#endif // COMMONUTILITY_H
