#ifndef CAROUSELITEM_H
#define CAROUSELITEM_H

#include<QtGui>
#include <QWidget>
#include <QString>
#include <QMouseEvent>
#include<QDragEnterEvent>
#include <QFile>
#include "CommonUtility.h"
#include "CarouselItemData.h"

class CarouselItem: public QLabel
{

    Q_OBJECT

    Q_PROPERTY(QPixmap* pixmap READ getItemPixmap WRITE  setItemPixmap);
       Q_PROPERTY(CarouselItemData data READ getCarouselItemData WRITE  setCarouselItemData);
          Q_PROPERTY(QSize itemSize READ getItemSize  WRITE  setItemSize);
          Q_PROPERTY(QPoint position READ getPosition  WRITE  setPosition);
    Q_PROPERTY(double scaleFactor READ getScaleFactor WRITE setScaleFactor);
     Q_PROPERTY(QSize minSize READ getMinSize  WRITE  setMinSize);
      Q_PROPERTY(QSize maxSize READ getMaxSize  WRITE  setMaxSize);
           Q_PROPERTY(int int_listIndex READ getIndex  WRITE  setIndex);

public:
    CarouselItem(QPixmap*, CarouselItemData,  QString strStyle = "", QWidget *parent = 0);

   CarouselItemData data;
    //bool bool_isDragged; //flag to indicate if item is moving on carousel or not

    void setItemPixmap(QPixmap*);
    QPixmap* getItemPixmap();

    void setCarouselItemData(CarouselItemData);
    CarouselItemData getCarouselItemData();

    void setItemSize(QSize);
    QSize getItemSize();

    void setMinSize(QSize);
    QSize getMinSize();

    void setMaxSize(QSize);
    QSize getMaxSize();

    void setPosition(QPoint);
    QPoint getPosition();

          void setIndex(int);
    int getIndex();

    void setScaleFactor(double);
    double getScaleFactor();
    void setItemState(QString style, QString state);

//Following may not be required as already handled in QlistIcon
signals:
         //void signal_mousePressed(QMouseEvent*); - to generate class diagram in VS2008
    void signal_carouselItemSelected(CarouselItemData, SignalState);
    void signal_mousePressed(QMouseEvent*);
    void signal_mouseDown(QMouseEvent*);
        void signal_draggedInInvalideArea(CarouselItem *);

protected:
    void mousePressEvent(QMouseEvent *ev);
    void mouseMoveEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
    void  paintEvent(QPaintEvent *);
    void mouseDoubleClickEvent(QMouseEvent *ev);

private:

    void performDrag();

    CommonUtility *objCommon;
    QSize size_minSize;
    QSize size_maxSize;
    QPixmap* pixmap;

     QSize size_itemSize;
      QPoint point_position;
          double dbl_scaleFactor;

          QPoint point_startPos;
          QPoint point_curMousePos;
          bool isDragging;
          QTimer *timer_traceSignal;
          QDateTime time_mouseClick;
          bool bool_isMousePressed;
          bool bool_isPressHoldSignalSent;
        int int_duration;
        bool bool_isProcessingOn;
                int int_listIndex;
                bool bool_isScrolling;
                bool bool_isDragEnabled;


private slots:
          void slot_raiseSignal();
};
#endif // CAROUSELITEM_H
