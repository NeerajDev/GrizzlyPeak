#ifndef CAROUSELITEMDATA_H
#define CAROUSELITEMDATA_H
#include <QString>
#include<QColor>

enum ItemState
{
    Active,
    Inactive,
    OnPress
};

enum SignalState
{
    SingleClick,
    DoubleClick,
    PressHold,
    HoldRelease

};

struct CarouselItemData
{
        QString string_Id;
        QString string_DisplayName;
        QString string_IconPath;
       QObject *object_data;
        QString string_itemState;
                bool bool_isDraggable;
};

#endif // CAROUSELITEMDATA_H
