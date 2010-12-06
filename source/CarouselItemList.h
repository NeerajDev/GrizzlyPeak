#ifndef CAROUSELITEMLIST_H
#define CAROUSELITEMLIST_H

#include <QWidget>
#include <QLabel>
#include <vector>
#include <QMouseEvent>
#include "CarouselItem.h"
#include "CarouselItemData.h"
#include<QDragEnterEvent>
#include<QDragMoveEvent>
#include<QDropEvent>
#include "CommonUtility.h"
#include <QFile>

using namespace std;

enum RotationAxis
{
    Top,
    Middle,
    Bottom
};

class CarouselItemList : public  QLabel
{
    Q_OBJECT

Q_PROPERTY(RotationAxis rotationAxis_axis READ getRotationAxis WRITE setRotationAxis);

public:
    CarouselItemList(QWidget *parent = 0);
    ~CarouselItemList();

        bool isInfiniteLoopOn;

        void removeItem(QString);
        void moveItem(QWidget*, QPoint targetPoint);
        //void AppendItem(CarouselItemData*);
        void setItemState(QString id,  QString stateStyle , bool showAnimationEffect, QString state);

        //void setVisualIndicator(bool);
        void arrangeItems(bool isAnimationOn, bool isItemAdded);
        void appendItem(QString lpszFileName, CarouselItemData* data);
        void appendItem(QWidget *data,  QString strStyle);
        void setRow(int row);
        void setCol(int col);
        void setAutoFit(bool bAutoFit);
        void setOrientation(Orientation orientation);
        int getItemCount();
        int getIndexOfCentralItem();
        int getItemIndex(QWidget*);
        int getIndexByPos(QPoint pt);

        void rearrangeItem(QWidget*, QPoint, int, bool);
//        void animateArrangement();
        QWidget* getItemAt(int index);
        void setRotationAxis(const  RotationAxis);
         RotationAxis getRotationAxis() const;
        void setDragEnabled(bool);//For testing , will be deleted in final version

                void setVisibleItems(int);
        void initializeList(bool isArrangeEnabled=true);
                void setItemsize();

signals:
                  //void signal_mousePressed(QMouseEvent*); - to generate class diagram in VS2008
        void signal_carouselItemClicked(CarouselItemData data, SignalState);
                void signal_itemDraggedOutside(QWidget *item);

private slots:
         void slot_itemClicked(CarouselItemData, SignalState);
        void slot_itemMousePressed(QMouseEvent*);
        void slot_itemMouseDown(QMouseEvent*);
           void slot_compositionTarget_Rendering();
           void slot_showIndicator();
                   void slot_ItemDraggedOutside(QWidget*);

protected:
        void mousePressEvent(QMouseEvent *event);
         void mouseReleaseEvent(QMouseEvent *event);



private:
                bool isArrangeEnabled;
                bool bool_isMouseUp;
                bool bool_isdragged;
                bool bool_isdropped;
            int test;
         CommonUtility *objCommon;
         int int_counter;
         void show_frame_rate(const QTime &qtime_start, const unsigned int &uint_total_frames_drawn);
         QTimer timer_ArrangeItems;
         QTime qtime_start_time;

                 int int_firstItemIndex;
                 int int_lastItemIndex;

           RotationAxis rotationAxis_axis;


        void releaseBitmaps();

        long getActualHeight();
        long getActualWidth();
        void getActualDimension(long& actualHeight, long& actualWidth);
        void calculateRowCol();

        void getCurrentPoint(QPoint& pt);
        void compositionTarget_Rendering();
        void captureMouse(bool bCapture);
        void reset();
        double getXPos(qreal n)  ;

        //Methods written to use the same code twice
        void mouseReleased(QMouseEvent *);
                QWidget* getItemByID(QString guid);


private:
        int int_timeId;
       //vector<HPCarouselItem*> vector_Bitmap;
       vector<QWidget*> vector_Bitmap;


       double  dbl_prevOffset;

    double dbl_width;
    double dbl_height;
    int int_numColumns;
    int int_numRows;
    QPoint point_startPosition;
    QPoint point_lastPosition;
    double dbl_speed;
    bool bool_moved;
    bool bool_isDragging;
    bool bool_handlerAssigned;
        double dbl_TargetOffset;
        double dbl_LocationOffset;
        double dbl_MovementThreshold;
        double dbl_Inertia;

        bool bool_isCaptureMouse;
        Orientation _orientation;
        double dbl_itemWidth;
        double dbl_itemHeight;
        double dbl_leftMargin;
        double dbl_rightMargin;
        double dbl_topMargin;
        double dbl_bottomMargin;

        double dbl_startLeft;
        double dbl_startTop;
        bool bool_autoFit;

        void setScaling();
        int int_centralIndex;

        bool isDragEnabled;
                bool bool_isProcessing;
};

#endif // CAROUSELITEMLIST_H
