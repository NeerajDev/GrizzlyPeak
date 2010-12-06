#include "CarouselItemList.h"


#include "CarouselItemList.h"
#include <QPainter>
#include <math.h>
#include <QtGlobal>
 #include <qDebug>
#include <algorithm>
#include "BarChartSingleBar.h"
#include "MonthView.h"


//Constructor initializes the class variables
CarouselItemList::CarouselItemList(QWidget *parent)
        : QLabel(parent)
{

        vector_Bitmap.clear();


        bool_moved = false;
        bool_isDragging = false;
        bool_handlerAssigned = false;

        bool_isCaptureMouse = false;
        bool_autoFit = true;
                bool_isdragged = false;
                bool_isdropped = false;


        //JS:
        this->setAcceptDrops(true);
        setStyleSheet("background-image: url(null);vertical-align: top;background-color:transparent;");//background-color:black");
         setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

         objCommon = &CommonUtility::getInstance();
         isArrangeEnabled = true;
}


//Destructor - releases the bitmaps held by the application.
CarouselItemList::~CarouselItemList()
{
        releaseBitmaps();
}


//Method to set the item's size in case it is set beyond the Carousel's dimensions.
//In this method, the width of item is adjusted if it goes beyond Carousel width. same for item height.
//Minimum size of an item is adjusted as per its maximum size.
void CarouselItemList::setItemsize()
{

         //Adjust item width if greater than Carousel width
    if(!(
        (objCommon->size_minItemSize.width() < objCommon->size_carouselSize.width() &&
        objCommon->size_maxItemSize.width() < objCommon->size_carouselSize.width())))

    {
                if(_orientation == Vertical)
                {
                         objCommon->size_maxItemSize.setWidth(objCommon->size_carouselSize.width()/10);
                         objCommon->size_minItemSize.setWidth(objCommon->size_carouselSize.width()/20);
                }
                else
                {
                        objCommon->size_maxItemSize.setWidth(objCommon->size_carouselSize.width());
                        objCommon->size_minItemSize.setWidth(objCommon->size_carouselSize.width());
                }
    }

    dbl_itemWidth = objCommon->size_maxItemSize.width();

    //Adjust item height if greater than Carousel height
    if(!(
        (objCommon->size_minItemSize.height() < objCommon->size_carouselSize.height() &&
        objCommon->size_maxItemSize.height() < objCommon->size_carouselSize.height())
        ))
    {
                if(_orientation == Horizontal)
                {
                        objCommon->size_maxItemSize.setHeight(objCommon->size_carouselSize.height()/10);
                        objCommon->size_minItemSize.setHeight(objCommon->size_carouselSize.height()/20);
                }
                else
                {
                        objCommon->size_maxItemSize.setHeight(objCommon->size_carouselSize.height());
                        objCommon->size_minItemSize.setHeight(objCommon->size_carouselSize.height()/2);
                }

    }
    dbl_itemHeight = objCommon->size_maxItemSize.height();

        //Adjust min Size if gretare than maxSize
    if(objCommon->size_minItemSize.width() > objCommon->size_maxItemSize.width())
    {
            objCommon->size_minItemSize.setWidth(objCommon->size_maxItemSize.width()/2);
    }
    if(objCommon->size_minItemSize.height() > objCommon->size_maxItemSize.height())
    {
            objCommon->size_minItemSize.setHeight(objCommon->size_maxItemSize.height()/2);
    }


    dbl_leftMargin = 5;
    dbl_rightMargin = 1;
    dbl_topMargin = 1;
    dbl_bottomMargin = 1;

    dbl_width = dbl_itemWidth + dbl_leftMargin + dbl_rightMargin;
    dbl_height = dbl_itemHeight + dbl_topMargin + dbl_bottomMargin;



}



//Method to initialize the items list .
void CarouselItemList::initializeList(bool _isArrangeEnabled)
{

    isArrangeEnabled = _isArrangeEnabled;
    setItemsize();

    int_timeId = -1;
    dbl_speed = 0;

    dbl_TargetOffset = 0;
    dbl_LocationOffset = 0;
    dbl_MovementThreshold = 2;
    dbl_Inertia = 0.3;

    dbl_startLeft = 0;
    dbl_startTop = 0;

    int_counter = 0;

    timer_ArrangeItems.setSingleShot(false);
    connect(&timer_ArrangeItems, SIGNAL(timeout()), this, SLOT(slot_compositionTarget_Rendering()));

        timer_ArrangeItems.start(1); //To arrange items
       qtime_start_time.start(); //For counter to track frames/sec.

}


//Mouse press event - tracks the mouse position as initial position for the drag operation.
void CarouselItemList::mousePressEvent(QMouseEvent *event)
 {

         bool_isMouseUp = false;
         int_firstItemIndex = 0;
         int_lastItemIndex = vector_Bitmap.size() - 1;

    long ActualHeight = 0;
    long ActualWidth = 0;
    getActualDimension(ActualHeight, ActualWidth);
    if ((_orientation == Horizontal && (dbl_height * int_numRows) > ActualHeight) ||
            (_orientation == Vertical && (dbl_width * int_numColumns) > ActualWidth))
            {
                    if (!bool_isDragging)
                    {
                        bool_isDragging = true;
                                                point_startPosition = point_lastPosition = QCursor::pos(); //event->globalPos();
                        bool_moved = false;
                        if (!bool_handlerAssigned)
                        {
                            bool_handlerAssigned = true;
                            if (event->button() == Qt::LeftButton)
                            {
                                                                timer_ArrangeItems.start(10);
                            }
                        }
                    }
            }
 }


//Mouse release event - calls the mouse released method.
 void CarouselItemList::mouseReleaseEvent(QMouseEvent *event)
 {
        mouseReleased(event);
 }


//Method to handle mouse release event.
 //Stops the drag operation in case it is on.
 //Initiates a throw of the list as left by the user to scroll through the items.
 void CarouselItemList::mouseReleased(QMouseEvent *event)
 {
  //  //qDebug()<<"mouse up";
         bool_isMouseUp = true;
     if (bool_isDragging)
 {
     bool_isDragging = false;
             captureMouse(false);
     switch (_orientation)
     {
             case Horizontal:
                                 if (point_lastPosition.y() != QCursor::pos().y())
                                                         {
                                                                                                         long ActualHeight = getActualHeight();
                                                                                                         dbl_TargetOffset = dbl_height * floor((dbl_LocationOffset - (point_lastPosition.y() - QCursor::pos().y()) * 10) / dbl_height + 0.5);

                                                                                                            if(!isInfiniteLoopOn)
                                                                      {
                                                                                                                                                                 if (dbl_TargetOffset > 0)
                                                                                                                                                                 {
                                                                                                                                                                         //Don't throw beyond end of list
                                                                                                                                                                         dbl_TargetOffset = 0;
                                                                                                                                                                 }
                                                                                                                                                                 else if (dbl_TargetOffset < ActualHeight - (int_numRows * dbl_height))
                                                                                                                                                                 {
                                                                                                                                                                         //Don't throw beyond end of list
                                                                                                                                                                         dbl_TargetOffset = ActualHeight - (int_numRows * dbl_height);
                                                                                                                                                                 }
                                                                                                                                                                 else if (dbl_TargetOffset == 0)
                                                                                                                                                                 {
                                                                                                                                                                         //Flick
                                                                                                                                                                         dbl_TargetOffset = -dbl_height;
                                                                                                                                                                 }
                                                                                                                }
                                                         }
                                                         else
                                                         {
                                                                 dbl_TargetOffset = dbl_LocationOffset;
                                                         }

             break;
             case Vertical:

                     if (point_lastPosition.x() != QCursor::pos().x())
                                        {
                                     long ActualWidth = getActualWidth();
                                                                         int currentX= QCursor::pos().x();
                                                                         int displacement = point_lastPosition.x() -currentX;
                                                                         dbl_TargetOffset = dbl_width * floor((dbl_LocationOffset - (displacement) * 5) / dbl_width + 0.5);


                                                  if(!isInfiniteLoopOn)
                                                                      {
                                                                                   if (dbl_TargetOffset > 0)
                                                                                     {
                                                                                         //Don't throw beyond end of list
                                                                                         dbl_TargetOffset = 0;
                                                                                     }
                                                                                     else if (dbl_TargetOffset < ActualWidth - (int_numColumns * dbl_width))
                                                                                     {
                                                                                         //Don't throw beyond end of list
                                                                                         dbl_TargetOffset = ActualWidth - (int_numColumns * dbl_width);
                                                                                     }
                                                                                                                                                                    else if (dbl_TargetOffset == 0)
                                                                                                                                                                         {
                                                                                                                                                                                 //Flick
                                                                                                                                                                                 dbl_TargetOffset = -dbl_width;
                                                                                                                                                                         }

                                                                  }

                                 }

                   else
                                 {
                         dbl_TargetOffset = dbl_LocationOffset;     vector <QWidget*>::iterator Iter;

                       for ( Iter = vector_Bitmap.begin() ; Iter != vector_Bitmap.end() ; Iter++ )
                       {

                        QWidget* item = *Iter;


           //         if (item->rect().x()  + item->rect().width() > 30)
                      {
                            //qDebug()<<"----------------------------Value: "<< QString::number(item->geometry().x() + item->geometry().width());
                        if (item->geometry().x() + item->geometry().width() > item->geometry().width()/2  )
                        {
                            dbl_TargetOffset  =  0 ;
                          //  dbl_speed= 2;
                            //qDebug() << "Neeraj Need to 45454 refresh";

                        }
                        else
                        {
                            dbl_TargetOffset  =  item->geometry().x() + item->geometry().width();
                               //qDebug() << "Neeraj Need to reftertertresh";
                            // dbl_speed = 2;
                        }
                        dbl_speed = 5;

                      }

                   break;

                   }

          }
 timer_ArrangeItems.start(1); //To arrange items
             break;
     }

 }
 }


 //Method to set Rotation axis  - not in use right now
 void CarouselItemList:: setRotationAxis(const  RotationAxis axis)
 {
        rotationAxis_axis = axis;
 }

 //Method to fetch the rotation axis of Carousel - not in use right now.
 RotationAxis  CarouselItemList::getRotationAxis() const
 {
        return rotationAxis_axis;
 }


 //Method to get actual height of the control.
 long CarouselItemList::getActualHeight()
{
        return height();
}

 //Method to get actual width of the control
long CarouselItemList::getActualWidth()
{
        return width();
}

//Method to get actual width and height of the control.
void CarouselItemList::getActualDimension(long& actualHeight,
                                                            long& actualWidth)
{
        actualHeight = height();
        actualWidth = width();
}

//Method to calculate the rows/columns required to hold the items.
//It calculates rows for the horizontal orientation and columns for vertical.
void CarouselItemList::calculateRowCol()
{
        if (bool_autoFit)
        {
                switch (_orientation)
                {
                case Horizontal:
                                int_numColumns = (int)(getActualWidth() / dbl_width);
                                int_numRows = (int)ceil((double)vector_Bitmap.size() / (double)int_numColumns);
                                dbl_startLeft = (getActualWidth() - int_numColumns * dbl_width)/2;
                                dbl_startTop = 0;
                                break;
                case Vertical:
                                int_numRows = (int)(getActualHeight() / dbl_height);
                                int_numColumns = (int)ceil((double)vector_Bitmap.size() / (double)int_numRows);
                                dbl_startTop = (getActualHeight() - int_numRows * dbl_height)/2;
                                dbl_startLeft = 0;
                                break;
                }
        }
        else
        {
                switch (_orientation)
                {
                case Horizontal:
                                int_numRows = (int)ceil((double)vector_Bitmap.size() / (double)int_numColumns);
                                dbl_startLeft = (getActualWidth() - int_numColumns * dbl_width)/2;
                                dbl_startTop = 0;
                                break;
                case Vertical:
                                int_numColumns = (int)ceil((double)vector_Bitmap.size() / (double)int_numRows);
                                dbl_startTop = (getActualHeight() - int_numRows * dbl_height)/2;
                                dbl_startLeft = 0;
                                break;
                }
        }
}



//Method to remove an item from the Carousel.
void CarouselItemList::removeItem(QString Guid)
{
    //Search item with id
//    foreach(QWidget* item, vector_Bitmap)
//    {
//            if(item->getCarouselItemData().string_Id == Guid)
//            {
//                int index = getItemIndex(item);
//                vector_Bitmap.erase(vector_Bitmap.begin() + index);
//                delete item;
//                break;
//            }
//    }

    arrangeItems(true, true);
}

//Method to move an item to another location - can be implemented when required.
void CarouselItemList::moveItem(QWidget* , QPoint targetPoint)
{

}

//Method to set Item state
void CarouselItemList::setItemState(QString guid,  QString stateStyle , bool , QString state)
{
                QWidget* item = getItemByID(guid);
                if(item != NULL)
                {
//			 item->setItemState(stateStyle,state);
                }
}

//Mthod to get an item as per its ID value.
QWidget* CarouselItemList ::getItemByID(QString guid)
{
                 vector <QWidget*>::iterator Iter;
//			for ( Iter = vector_Bitmap.begin() ; Iter != vector_Bitmap.end() ; Iter++ )
//			{
//				HPCarouselItem* item = *Iter;
//				 if(guid == item->getCarouselItemData().string_Id)
//				 {
//					 return item;
//				 }
//			}
                        return NULL;
}

//Slot to catch the list item clicked signal
void CarouselItemList::slot_itemClicked(CarouselItemData data, SignalState state)
{
    //Raise signal from here that item clicked
        QFile file("log.txt");
     if(file.open(QIODevice::Append | QIODevice::Text))
        {
                 QTextStream out(&file);
                 out << "\nSignal passed to Carousel main control " << QDateTime::currentDateTime().toString();

        }
         file.close();
        emit(signal_carouselItemClicked(data, state));

}

//Slot to handle the item that is dragged outside the Carousel area.
void CarouselItemList::slot_ItemDraggedOutside(QWidget *item)
{
                // Can be handled if required
                //emit signal_itemDraggedOutside(item);
}

//Method to rearrange an item as it is dragged and dropped inside the carousel.
void CarouselItemList::rearrangeItem(QWidget *item, QPoint , int newIndex,  bool itemDropped)
{

   //Get existing Index

//    int index = getItemIndex(item);

//	vector <HPCarouselItem*>::iterator Iter;


//   //Remove from existing position
//    if(!itemDropped)
//    {
//		Iter = 	vector_Bitmap.begin() + index;
//		if(Iter != vector_Bitmap.end())
//		{
//			item->raise();
//			bool_isdragged  = true;
//			vector_Bitmap.erase(Iter);
//			arrangeItems(true, true);
//		}
//    }


//    //Insert at new Index when dropped
//   if(itemDropped)
//   {
//	   Iter = vector_Bitmap.begin() + newIndex;
//	   bool_isdropped  = true;
//       vector_Bitmap.insert(Iter, item);
//	   arrangeItems(true, true);
//   }

}

//Slot to set the targetOffset equal to LocationOffset when mouse down on an item.
void CarouselItemList::slot_itemMouseDown(QMouseEvent *)
{
  // //qDebug()<<"entered event 2";
        dbl_TargetOffset = dbl_LocationOffset;
}

//Slot to handle the mouse pressed state of an item in Carousel
//This initializes the varialble for drag operation, in case it is started.
void CarouselItemList::slot_itemMousePressed(QMouseEvent *event)
{
  // //qDebug()<<"entered event 1";
     if ( (event->buttons() & Qt::LeftButton))
    {

        bool_isMouseUp = false;
         int_firstItemIndex = 0;
         int_lastItemIndex = vector_Bitmap.size() - 1;

        long ActualHeight = 0;
        long ActualWidth = 0;
        getActualDimension(ActualHeight, ActualWidth);
        if ((_orientation == Horizontal && (dbl_height * int_numRows) > ActualHeight) ||
                (_orientation == Vertical && (dbl_width * int_numColumns) > ActualWidth))
        {
                    if (!bool_isDragging)
                    {
                        bool_isDragging = true;
                                                point_startPosition = point_lastPosition = QCursor::pos(); //event->globalPos();
                        bool_moved = false;
                        if (!bool_handlerAssigned)
                        {
                            bool_handlerAssigned = true;
                                       //  if (event->button() == Qt::LeftButton)
                                            {
                                              timer_ArrangeItems.start(10);
                                            }
                        }
                    }
        }
    }
}






//Method to append an item to existing list of items.
//Once added to the vector of items, item's  signals are connected to suitable slots.
void CarouselItemList::appendItem(QWidget *data, QString strStyle)
{
//    QPixmap* pBitmap = new QPixmap(data.string_IconPath);

//    HPCarouselItem *item = new HPCarouselItem(pBitmap, data, strStyle, this);
//    item->setItemSize(QSize(dbl_itemWidth,dbl_itemHeight));
//	item->setIndex(vector_Bitmap.size());

    QFile file(":/styles.qss");
    file.open(QFile::ReadOnly);
    data-> setStyleSheet(file.readAll());

     vector_Bitmap.push_back(data);

  //   //qDebug()<< ( static_cast<MonthView*>(data))->objectName();

    if(( static_cast<MonthView*>(data))->objectName().toLower() == "barchartsinglebar")
     {
       //   //qDebug()<<"BarChartSingleBar view type found";
        connect ((BarChartSingleBar *)data, SIGNAL(signal_mousePressed(QMouseEvent*)), this,   SLOT(slot_itemMousePressed(QMouseEvent*)));
         connect((BarChartSingleBar *)data,SIGNAL(signal_mouseDown(QMouseEvent*)),this,SLOT(slot_itemMouseDown(QMouseEvent*)));
     }
     if(( static_cast<MonthView*>(data))->objectName().toLower() == "monthview")
     {
      //   //qDebug()<<"MOnth view type found";
        connect ((MonthView *)data, SIGNAL(signal_mousePressed(QMouseEvent*)), this,   SLOT(slot_itemMousePressed(QMouseEvent*)));
         connect((MonthView *)data,SIGNAL(signal_mouseDown(QMouseEvent*)),this,SLOT(slot_itemMouseDown(QMouseEvent*)));
     }


    arrangeItems(false, true);
}



//Slot to show/hide the visual indicator with the drag operation.
void CarouselItemList::slot_showIndicator()
{
        if(bool_isdragged)
        {
                bool_isdragged = false; //make it false , required only in animation case
        }
        else if(bool_isdropped)
        {
                bool_isdropped = false; //make it false , required only in animation case
        }

}

//Method to arrange items present in Vector to a Carousel form in UI.
//It takes the parameters to check if animation required while adding a new item or not. Animation is required only while moving an item after drag and drop of an item.
//Second parameter hecks if an item is added or not.
void CarouselItemList::arrangeItems(bool isAnimationOn, bool isItemAdded)
{

//    //qDebug()<<"Arranging....";
    if(!isArrangeEnabled)
        {
            return;// disabled for now
        }

   QPropertyAnimation *animation ;
   int duration = 100;

   QPoint pt;
        getCurrentPoint(pt);

   calculateRowCol();

        int row = 0;
        int col = 0;

        vector <QWidget*>::iterator Iter;

        double scale = 1;
        double scaleDiff=   1 - objCommon->dbl_scaleFactor;

        int childCount =  vector_Bitmap.size();

        switch(_orientation)
        {
        case Horizontal:
                {

                    int h = objCommon->size_carouselSize.height();

                    double halfHeight = h/2;

                    double minScale =  (qreal) objCommon->size_minItemSize.height()/objCommon->size_maxItemSize.height();

                     int itemShifted = 0;

                        for ( Iter = vector_Bitmap.begin() ; Iter != vector_Bitmap.end() ; Iter++ )
                        {

                                    QWidget* item = *Iter;

                                                                                 int x = (int)col*(dbl_width +dbl_leftMargin+dbl_startLeft) ;

                                                                                 int  y = (int)row*dbl_height+dbl_topMargin+dbl_LocationOffset+dbl_startTop;

                                                                          double dist = qAbs(halfHeight - y);
                                                         double pow = qPow( scaleDiff, dist/dbl_itemHeight );

                                                         if(objCommon->dbl_scaleFactor != 0)
                                                         {
                                                                if((halfHeight > y && halfHeight<y+dbl_itemHeight )  )
                                                                   {
                                                                                scale =1 ;
                                                                   }
                                                                else
                                                                {
                                                                        if(dbl_itemHeight *  pow >= objCommon->size_minItemSize.height())
                                                                        {
                                                                           scale =  pow;
                                                                        }
                                                                        else
                                                                        {
                                                                                scale = minScale;
                                                                        }
                                                                }
                                                         }

                                                        x = x + ((dbl_itemWidth - (dbl_itemWidth*scale))/2);

                                                        if(dbl_speed != 0 || isItemAdded)
                                                        {
                                                                //   item->setScaleFactor(scale);
                                                                        if(!isAnimationOn)
                                                                        {
                                                                                 item->setGeometry(x,y, dbl_itemWidth* scale, dbl_itemHeight * scale);
                                                                                 item->show();
                                                                                 update();
                                                                        }
                                                                        else
                                                                        {
                                                                                         animation = new QPropertyAnimation(item,"geometry",this);
                                              animation->setDuration(duration);
                                              animation->setStartValue(QRect(item->pos().x(),item->pos().y(),dbl_itemWidth *scale, dbl_itemHeight*scale ));
                                              animation->setEndValue(QRect(x,y,dbl_itemWidth *scale, dbl_itemHeight*scale ));
                                              connect(animation, SIGNAL(finished()), this, SLOT(slot_showIndicator()));
                                              animation->start();

                                                                        }
                                                        }
                               col++;
                                if (col == int_numColumns)
                                {
                                        row++;
                                        col = 0;
                                }
                        }

                        if(isInfiniteLoopOn)
                        {
 if (dbl_LocationOffset != dbl_TargetOffset)
 {
                                if(vector_Bitmap.size() > 1)
                                                {
                                                                if(dbl_speed != 0)
                                        {

                                                                                        if(dbl_speed > 0)
                                                                                        {
                                                                                                if(getItemAt(childCount - 1)->geometry().y() < objCommon->size_carouselSize.height())
                                                                                                {
                                                                                                        itemShifted = 1;
                                                                                                }
                                                                                        }
                                                                                        else
                                                                                        {
                                                                                                if(getItemAt(0)->geometry().y() > 0)
                                                                                                {
                                                                                                        itemShifted = 2;
                                                                                                }
                                                                                        }
                                                if(itemShifted == 1)
                                                {
                                                                                QWidget *item = vector_Bitmap.at(0);
                                                                                vector_Bitmap.erase(vector_Bitmap.begin());
                                                                                vector_Bitmap.push_back(item);

                                                                                        dbl_LocationOffset = dbl_LocationOffset + dbl_height;

                                                                                        if(bool_isMouseUp)
                                                                                {
                                                                                        if (dbl_TargetOffset + dbl_height < dbl_LocationOffset)
                                                                                        {
                                                                                                dbl_TargetOffset = dbl_TargetOffset + dbl_height;
                                                                                        } else
                                                                                        {
                                                                                                dbl_TargetOffset  = dbl_LocationOffset;
                                                                                        }

                                                                                }						}
                                                else if(itemShifted == 2)
                                                {
                                                              QWidget *item = vector_Bitmap.at(vector_Bitmap.size() -1 );
                                                                  vector_Bitmap.erase(vector_Bitmap.begin() + vector_Bitmap.size() - 1);
                                                                         vector_Bitmap.insert(vector_Bitmap.begin(), item);


                                                                                dbl_LocationOffset = dbl_LocationOffset - dbl_height;
                                                                        ////qDebug()<< " Shifting to left "  << 	dbl_LocationOffset  ;
                                                                                if(bool_isMouseUp)
                                                                                {
                                                                                        if (dbl_TargetOffset - dbl_height > dbl_LocationOffset)
                                                                                        {
                                                                                                dbl_TargetOffset = dbl_TargetOffset - dbl_height;
                                                                                        } else
                                                                                        {
                                                                                                dbl_TargetOffset  = dbl_LocationOffset;
                                                                                        }

                                                                                }


                                                }
                                                }
                                }
                                }
                        }

                }
                break;

        case Vertical:
                {
                      ////qDebug()<< " Shifting to left "  << 	dbl_LocationOffset  ;
                    int w = objCommon->size_carouselSize.width();
                    double halfWidth = w/2;

                    double scale = 1;
                    double minScale =  (qreal) objCommon->size_minItemSize.width()/objCommon->size_maxItemSize.width();

                                                int itemShifted = 0;
                                              //   //qDebug()<<"Entered loop 1....";
                        for ( Iter = vector_Bitmap.begin() ; Iter != vector_Bitmap.end() ; Iter++ )
                        {
                             ////qDebug()<<"Entered loop....";
                                    QWidget* item = *Iter;

                                  int x = (int) (col)*dbl_width +dbl_LocationOffset+dbl_leftMargin+dbl_startLeft;
                                  int y = (int) row*dbl_height+dbl_topMargin+dbl_startTop;

                                 double dist = qAbs(halfWidth - x);
                                 double pow = qPow(scaleDiff, dist/dbl_itemWidth );

                                 if(objCommon->dbl_scaleFactor != 0)
                                                         {
                                                                                        if(
                                                                                                        (halfWidth > x && halfWidth< x+dbl_itemWidth )
                                                                                           )
                                                                                                                           {
                                                                                                                                        scale =1 ;
                                                                                                                           }
                                                                                                                else
                                                                                                                {
                                                                                                                        if(dbl_itemWidth *  pow >= objCommon->size_minItemSize.width())
                                                                                                                        {
                                                                                                                           scale =  pow;
                                                                                                                        }
                                                                                                                        else
                                                                                                                        {
                                                                                                                                scale = minScale;
                                                                                                                        }
                                                                                                                }
                                                         }
                            y = y + ((dbl_itemHeight - (dbl_itemHeight*scale))/2);

 // //qDebug()<<"speed" <<dbl_speed;

                                                        if(dbl_speed != 0 || isItemAdded)
                                                        {
                                                       //     test = 2;
//								    item->setScaleFactor(scale);
 // //qDebug()<<"test"<<test;
                                                                        if(!isAnimationOn)
                                                                        {
                                                                            ////qDebug()<<"Setting geometry";
                                                                                item->setGeometry(x,y, dbl_itemWidth * scale, dbl_itemHeight * scale);
                                                                                item->show();
                                                                                update();
                                                                        }
                                                                        else
                                                                        {
                                                                                animation = new QPropertyAnimation(item,"geometry",this);
                                                                                animation->setDuration(duration);
                                                                                animation->setStartValue(QRect(item->pos().x(),item->pos().y(),dbl_itemWidth *scale, dbl_itemHeight*scale ));
                                                                                animation->setEndValue(QRect(x,y,dbl_itemWidth *scale, dbl_itemHeight*scale ));
                                                                                connect(animation, SIGNAL(finished()), this, SLOT(slot_showIndicator()));
                                                                                animation->start();

                                                                        }
                                                        }
                                row++;
                                if (row == int_numRows)
                                {
                                        col++;
                                        row = 0;
                                }

                                                }
                                                        if(isInfiniteLoopOn)
                        {
if (dbl_LocationOffset != dbl_TargetOffset)
 {

                                if(vector_Bitmap.size() > 1)
                                                {
                                                                if(dbl_speed != 0)
                                        {

                                                                                        if(dbl_speed > 0)
                                                                                        {
                                                                                                if(getItemAt(childCount - 1)->geometry().x() < objCommon->size_carouselSize.width())
                                                                                                {
                                                                                                        itemShifted = 1;
                                                                                                }
                                                                                        }
                                                                                        else
                                                                                        {
                                                                                                if(getItemAt(0)->geometry().x() > 0)
                                                                                                {
                                                                                                        itemShifted = 2;
                                                                                                }
                                                                                        }
                                                if(itemShifted == 1)
                                                {
                                                                                QWidget *item = vector_Bitmap.at(0);
                                                                                vector_Bitmap.erase(vector_Bitmap.begin());
                                                                                vector_Bitmap.push_back(item);

                                                                                        dbl_LocationOffset = dbl_LocationOffset + dbl_width;

                                                                                        if(bool_isMouseUp)
                                                                                {
                                                                                        if (dbl_TargetOffset + dbl_width < dbl_LocationOffset)
                                                                                        {
                                                                                                dbl_TargetOffset = dbl_TargetOffset + dbl_width;
                                                                                        } else
                                                                                        {
                                                                                                dbl_TargetOffset  = dbl_LocationOffset;
                                                                                        }

                                                                                }
                                                   }
                                                else if(itemShifted == 2)
                                                {
                                                              QWidget *item = vector_Bitmap.at(vector_Bitmap.size() -1 );
                                                                  vector_Bitmap.erase(vector_Bitmap.begin() + vector_Bitmap.size() - 1);
                                                                         vector_Bitmap.insert(vector_Bitmap.begin(), item);


                                                                                dbl_LocationOffset = dbl_LocationOffset - dbl_width;

                                                                                if(bool_isMouseUp)
                                                                                {
                                                                                        if (dbl_TargetOffset - dbl_width > dbl_LocationOffset)
                                                                                        {
                                                                                                dbl_TargetOffset = dbl_TargetOffset - dbl_width;
                                                                                        }
                                                                                        else
                                                                                        {
                                                                                                dbl_TargetOffset  = dbl_LocationOffset;
                                                                                        }

                                                                                }


                                                }
                                                }
                                }
                                }
else
{
 }


}

                }
                break;
        }


}

//Method to set visible number of items in Carousel.
//This method sets the number of items as per the current orientation  - horizontal/vertical.
//And then arranges the items in the vector.
void CarouselItemList::setVisibleItems(int number)
{
        qreal carousel_width =   objCommon->size_carouselSize.width();
        qreal carousel_height = objCommon->size_carouselSize.height();

        if(objCommon->orientation == Horizontal)
        {
                                qreal item_width = carousel_width / number;

                                objCommon->size_maxItemSize.setWidth((int)item_width);

                                //Adjust min Size if gretare than maxSize
                                if(objCommon->size_minItemSize.width() > objCommon->size_maxItemSize.width())
                                {
                                                objCommon->size_minItemSize.setWidth(objCommon->size_maxItemSize.width()/2);
                                }

                                dbl_itemWidth = objCommon->size_maxItemSize.width();
                                dbl_width = dbl_itemWidth + dbl_leftMargin + dbl_rightMargin;

        }
        else
        {
                                qreal item_height = carousel_height / number;

                                objCommon->size_maxItemSize.setHeight((int)item_height);

                                //Adjust min Size if gretare than maxSize
                                if(objCommon->size_minItemSize.height() > objCommon->size_maxItemSize.height())
                                {
                                                objCommon->size_minItemSize.setHeight(objCommon->size_maxItemSize.height()/2);
                                }

                                dbl_itemHeight = objCommon->size_maxItemSize.height();
                                dbl_height = dbl_itemHeight + dbl_topMargin + dbl_bottomMargin;

        }

                                arrangeItems(false,true);
}

double CarouselItemList::getXPos(qreal n)
{
    if(n > 0)
    {
        return getXPos(n-1) +( (dbl_itemWidth+20) * qPow(1 - objCommon->dbl_scaleFactor, n));
    }
    return 0;
}

//Method to set scaling and spacing of items.
void CarouselItemList::setScaling()
{
    // Set scaling and spacing of items

    double  scale = 0.05;

    vector <QWidget*>::iterator Iter;
    for ( Iter = vector_Bitmap.begin() ; Iter != vector_Bitmap.end() ; Iter++ )
    {
            //JS:
            QWidget* item = *Iter;


            //ascending
            int index =  this->getItemIndex(item);
            int itemPos = qAbs(5-index);
            //item->setScaleFactor(1 - (itemPos*scale));


        }

}


//Method to get index of listitem specified
int CarouselItemList::getItemIndex(QWidget *item)
{
    std::vector<QWidget*>::iterator it = std::find(vector_Bitmap.begin(), vector_Bitmap.end(), item);
    int index = std::distance(vector_Bitmap.begin(),it);
    return index;
}


//Index of centered item in list
int CarouselItemList::getIndexOfCentralItem()
{
    return 0;
}

//get items count
int CarouselItemList::getItemCount()
{
    return 0;
}

//Method to release bitmaps held by the application.
void CarouselItemList::releaseBitmaps()
{
     //   vector <QWidget*>::iterator Iter;
//        for ( Iter = vector_Bitmap.begin() ; Iter != vector_Bitmap.end( ) ; Iter++ )
//		{
//			//JS:
//					HPCarouselItem* item = *Iter;
//					QPixmap* pBitmap = item->getItemPixmap();
//			delete pBitmap;
//			pBitmap = NULL;


//		}
        vector_Bitmap.clear();
}

//Method to get the current cursor point.
void CarouselItemList::getCurrentPoint(QPoint& pt)
{
        pt =  QCursor::pos();
}

void  CarouselItemList::captureMouse(bool bCapture)
{
        if (bCapture)
        {
                if (!bool_isCaptureMouse)
                {
                        grabMouse();
                        bool_isCaptureMouse = true;
                }
        } else
        {
                if (bool_isCaptureMouse)
                {
                        releaseMouse();
                        bool_isCaptureMouse = false;
                }
        }
}

//Slot to render the items as UI elements in Carousel .
void CarouselItemList::slot_compositionTarget_Rendering()
{

////qDebug()<<"composition rendrign";
        long ActualHeight = 0;
        long ActualWidth = 0;
        getActualDimension(ActualHeight, ActualWidth);


        if (bool_isDragging)
        {
                                  QPoint currentPosition;
                getCurrentPoint(currentPosition);
        if (!bool_moved)
        {
            QPoint dif = point_startPosition -currentPosition;
            if (abs(dif.x()) > dbl_MovementThreshold || abs(dif.y()) > dbl_MovementThreshold)
            {
                bool_moved = true;
            }
        }

        switch (_orientation)
        {
                case Horizontal:
                        if (bool_moved)
                {
                                                                        dbl_speed = point_lastPosition.y() - currentPosition.y();


                                                                                if ((dbl_LocationOffset - dbl_speed > 0 && dbl_speed < 0) ||
                                                                                        (dbl_LocationOffset - dbl_speed < ActualHeight - (int_numRows * dbl_height) && dbl_speed > 0))
                                                                                {
                                                                                        dbl_LocationOffset = dbl_LocationOffset - dbl_speed * 0.1;
                                                                                }
                                                                                else
                                                                                {
                                                                                        dbl_LocationOffset -= dbl_speed;
                                                                                }

                            captureMouse(true);
                }
                break;

                case Vertical:
                if (bool_moved)
                {
                                        dbl_speed = point_lastPosition.x() - currentPosition.x();

                                                                                                        if ((dbl_LocationOffset - dbl_speed > 0 && dbl_speed < 0) ||
                                                                                                                (dbl_LocationOffset - dbl_speed < ActualWidth - (int_numColumns * dbl_width) && dbl_speed > 0))
                                                                                                        {
                                                                                                                dbl_LocationOffset = dbl_LocationOffset - dbl_speed * 0.1;
                                                                                                        }
                                                                                                        else
                                                                                                        {
                                                                                                                dbl_LocationOffset -= dbl_speed;
                                                                                                        }

                                        captureMouse(true);
                }
                break;
        }
        point_lastPosition = currentPosition;
    }
    else if (dbl_LocationOffset != dbl_TargetOffset)
    {
                if (!bool_isProcessing)
                {
                        bool_isProcessing = true ;

                        qreal diffFactor =  (dbl_LocationOffset - dbl_TargetOffset) * (dbl_Inertia * 0.5) ;

                        if(qAbs(diffFactor) > 50)
                        {
                                diffFactor = 50 * (diffFactor / qAbs(diffFactor));
                        }

                        dbl_LocationOffset -= diffFactor;//*  .08;    // *  (dbl_Inertia * 0.5);

                       if (fabs(dbl_LocationOffset - dbl_TargetOffset) < 1)
                                {
                                        dbl_LocationOffset = dbl_TargetOffset;
                                }
                }
    }
    else
    {
        switch (_orientation)
        {
                case Horizontal:
                  if (dbl_LocationOffset > 0.05)
                {
                    dbl_LocationOffset -= dbl_LocationOffset * dbl_Inertia;
                }
                else if (dbl_LocationOffset < ActualHeight - (int_numRows *dbl_height) - 0.05)
                {
                    dbl_LocationOffset -= (dbl_LocationOffset - (ActualHeight - (int_numRows *dbl_height))) * dbl_Inertia;
                }
                else
                {
                    bool_handlerAssigned = false;
                    timer_ArrangeItems.stop();
                }
                break;
                case Vertical:

                if (dbl_LocationOffset > 0.05)
                {
                    dbl_LocationOffset -= dbl_LocationOffset * dbl_Inertia;
                }
                else if (dbl_LocationOffset < ActualWidth - (int_numColumns *dbl_width) - 0.05)
                {
                    dbl_LocationOffset -= (dbl_LocationOffset - (ActualWidth - (int_numColumns * dbl_width))) * dbl_Inertia;
                }
                else
                {
                    bool_handlerAssigned = false;
                    //qDebug()  << "Stoping the timer";
                    timer_ArrangeItems.stop();
                }

                break;
        }
        dbl_TargetOffset = dbl_LocationOffset;
    }

        update();
      arrangeItems(false, false);
        show_frame_rate(qtime_start_time,
                                        int_counter++);

        dbl_prevOffset = dbl_LocationOffset;
                bool_isProcessing  = false;
}


//Method to set row for an item in Carousel.
void CarouselItemList::setRow(int row)
{
        if (_orientation == Vertical)
        {
                int_numRows = row;
                bool_autoFit = false;
                reset();
        }
        else
        {
                Q_ASSERT_X(_orientation == Vertical, "CarouselItemList::setRow()", "The Orientation must be Vertical");
        }
}

//Method to set column for an item in CArousel.
void CarouselItemList::setCol(int col)
{
        if (_orientation == Horizontal)
        {
                int_numColumns = col;
                bool_autoFit = false;
                reset();
        }
        else
        {
                Q_ASSERT_X(_orientation == Horizontal, "CarouselItemList::setCol()", "The Orientation must be Horizontal");
        }
}

//Method to autofit the elements in Carousel. - Currently not in scope and code needs modification.
void CarouselItemList::setAutoFit(bool bAutoFit)
{
        bool_autoFit = bAutoFit;
        reset();

}

//Method to set orientation
void CarouselItemList::setOrientation(Orientation orientation)
{

        _orientation = orientation;
}


//Method to reset the variables associated to the list.
void CarouselItemList::reset()
{
        if (int_timeId != -1)
        {
            //    killTimer(int_timeId);
            timer_ArrangeItems.stop();
        }
        dbl_speed = 0;
    bool_moved = false;
    bool_isDragging = false;
    bool_handlerAssigned = false;
        dbl_TargetOffset = 0;
        dbl_LocationOffset = 0;
        dbl_MovementThreshold = 2;
        dbl_Inertia = 0.1;
}

//Method to get an item's index in the list as per the position of item on screen.
int CarouselItemList::getIndexByPos(QPoint pt)
{
        int index = -1;
        switch(_orientation)
        {
        case Vertical:
                 index = (int)((pt.x() - dbl_startLeft - dbl_LocationOffset) / dbl_width) * int_numRows + (int)((pt.y() -dbl_startTop) / dbl_height);
                break;

        case Horizontal:
                 index = (int)((pt.y()-dbl_startTop - dbl_LocationOffset) / dbl_height) * int_numColumns + (int)((pt.x() + 80 - dbl_startLeft) / dbl_width);
                break;
        }
        return index;
}


//method to get an item from its index in the list.
QWidget*  CarouselItemList::getItemAt(int index)
{
    return ((CarouselItem*)vector_Bitmap.at(index));
}

//method to show frame rate in output window in order to evaluate app's performance.
void  CarouselItemList:: show_frame_rate(const QTime &qtime_start,
                     const unsigned int &uint_total_frames_drawn)
        {
//            const double double_frames_per_second = uint_total_frames_drawn * 1000.0 / qtime_start.elapsed();

//            //qDebug() << "Frame rate is: " << double_frames_per_second << " fps\n";
        }
