#ifndef CAROUSELCONTROL_H
#define CAROUSELCONTROL_H

#include <QtGui/QWidget>
#include <QGridLayout>
#include <QHBoxLayout>
#include "CarouselItemList.h"
#include <QPainter>
#include "CarouselItemData.h"
#include    "CommonUtility.h"
#include "CarouselItem.h"

namespace Ui {
    class CarouselControl;
}

class CarouselControl : public QWidget
{
    Q_OBJECT

public:
    CarouselControl(QString style, QWidget *parent = 0, Qt::WFlags flags = 0);

      CarouselControl(QWidget *parent = 0, Qt::WFlags flags = 0);
      ~CarouselControl();

      void initializeItemList(bool isArrangeEnabled=true);
         void setCarouselInfiniteLoop(bool);

signals:
      void signal_carouselItemClicked(CarouselItemData data, SignalState);

protected:

      void dragEnterEvent(QDragEnterEvent *);
      void dragMoveEvent(QDragMoveEvent *);
      void dropEvent(QDropEvent *);


private:


      bool bool_dragStarted;
      int int_objIndexOnDrop;

public slots:


      void slot_itemClicked(CarouselItemData, SignalState);

      void slot_addItem(QWidget *, QString strStyle = "");

    void slot_removeItem(QString id);

    void slot_setItemState(QString id, QString stateStyle , bool showAnimationEffect, QString state);



    void slot_setOrientation(Orientation);


    void slot_setCarouselSize(QSize MinSize, QSize MaxSize);
    void slot_setItemSize(QSize MinSize, QSize MaxSize);
         void slot_updateItemSize(QSize MinSize, QSize MaxSize);
      void slot_setTouchSize(QSize);


    void slot_scrollItemtoCenter(QString Guid);


    void slot_setOpacityEffectOn(bool);

      void slot_setPosition(int, int);
    void slot_setItemSeparationGap(int);
    void slot_setScaleFactor(double);
    void slot_setRotationParameters(int RotationAngle, double radius);
     void slot_setRotationAxis(RotationAxis);

      void slot_reset();


              void slot_updateItemList();
              void slot_setVisibleItems(int);

              void slot_updateCarouselGeometry(QSize minSize, QSize maxSize, Orientation orientation);


private slots:
              void slot_itemDraggedOutside(CarouselItem *);

private:

      CarouselItemList* itemsList;

       QLabel *lbl_indicator ;
      QPoint point_dragStartPosition;
      CommonUtility *objCommon;
      QSize size_minSize;
      QSize size_maxSize;
      int int_left;
      int int_top;
      int int_dragIndex;
};

#endif // CAROUSELCONTROL_H
