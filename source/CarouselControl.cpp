#include "CarouselControl.h"

#include <QFileInfo>
#include <QDir>
#include "qmessagebox.h"
#define INDICATOR_HEIGHT 100
#define INDICATOR_WIDTH 3

CarouselControl::CarouselControl(QString style, QWidget *parent, Qt::WFlags flags): QWidget(parent, flags)
{
                this->setStyleSheet(style);

                 itemsList = new CarouselItemList(this);

        setAcceptDrops(true);

        //Connect signal of item selected
        connect(itemsList, SIGNAL(signal_carouselItemClicked(CarouselItemData, SignalState)),this, SLOT(slot_itemClicked(CarouselItemData, SignalState)));
                connect(itemsList, SIGNAL(signal_itemDraggedOutside(CarouselItem *)), this, SLOT(slot_itemDraggedOutside(CarouselItem *)));

        bool_dragStarted = false;


                        objCommon = &CommonUtility::getInstance();

                        lbl_indicator = new QLabel(this);
                        lbl_indicator->setStyleSheet("background:qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0.80 rgba(255, 255, 255, 255), stop:1 rgba(255, 255, 255, 0))");
                        lbl_indicator->setVisible(false);


                        lbl_indicator->setGeometry(100,100,INDICATOR_WIDTH,INDICATOR_HEIGHT);

}


//Constructor - initializes the variables.
CarouselControl::CarouselControl(QWidget *parent, Qt::WFlags flags)
        : QWidget(parent, flags)
{

        itemsList = new CarouselItemList(this);
        setAcceptDrops(true);

        //Connect signal of item selected
        connect(itemsList, SIGNAL(signal_carouselItemClicked(CarouselItemData, SignalState)),this, SLOT(slot_itemClicked(CarouselItemData, SignalState)));
        connect(itemsList, SIGNAL(signal_itemDraggedOutside(CarouselItem *)), this, SLOT(slot_itemDraggedOutside(CarouselItem *)));

        bool_dragStarted = false;


        objCommon = &CommonUtility::getInstance();


                lbl_indicator = new QLabel(this);
                lbl_indicator->setStyleSheet("background:qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0.80 rgba(255, 255, 255, 255), stop:1 rgba(255, 255, 255, 0))");
                lbl_indicator->setVisible(false);


                lbl_indicator->setGeometry(100,100,INDICATOR_WIDTH,INDICATOR_HEIGHT);

        setStyleSheet("background-image: url(null);background-color:transparent; vertical-align: top;");
}


//Slot to call item ilst's method to set specified number of  visible items in Carousel
void CarouselControl::slot_setVisibleItems(int number)
{
        itemsList->setVisibleItems(number);
}

//Slot to scroll specified item to center - Yet to be implemented
void CarouselControl::slot_scrollItemtoCenter(QString Guid)
{

}

//Slot to set rotation axis of Carousel - yet to be implemented.
void CarouselControl::slot_setRotationAxis(RotationAxis)
{

}

//Slot to set item separation gap between items - This value is yet to be used in imlementation
void CarouselControl::slot_setItemSeparationGap(int itemGap)
{
    objCommon->int_itemSeparationGap=itemGap;
}

//Slot to set item's minimum and maximum size
void CarouselControl::slot_setItemSize(QSize MinSize, QSize MaxSize)
{
        objCommon->size_minItemSize = MinSize;
        objCommon->size_maxItemSize = MaxSize;
}

//Slot to update item's minimum and maximum size.
void  CarouselControl::slot_updateItemSize(QSize MinSize, QSize MaxSize)
{
                objCommon->size_minItemSize = MinSize;
               objCommon->size_maxItemSize = MaxSize;
                itemsList->setItemsize();
                slot_updateItemList();

}

//Slot to set scale factor for an item.
void CarouselControl::slot_setScaleFactor(double scale)
{
    //Set in commonutility
    objCommon->dbl_scaleFactor = scale;
}

//Sot to set rotation angle and radius for Carousel.
void CarouselControl::slot_setRotationParameters(int rotationAngle, double radius)
{
     objCommon->int_rotationAngle = rotationAngle;
     objCommon->dbl_radius =  radius;

}

//Slot to reset the item to its original position when attempted to drag outside the carousel.
void CarouselControl::slot_itemDraggedOutside(CarouselItem *item)
{
         CarouselItem *obj = item;

     int x =  obj->pos().x() ;//+  e->pos().x() - point_dragStartPosition.x();
     int y =  obj->pos().y() ;// +  e->pos().y() - point_dragStartPosition.y();

      QPoint pt(x,y);

      obj->setGeometry(x,y,obj->getItemSize().width() * obj->getScaleFactor(), obj->getItemSize().height() * obj->getScaleFactor());

       //Rearrange list icons
                bool_dragStarted = false;
           lbl_indicator->setVisible(false);
       itemsList->rearrangeItem(obj,pt, int_objIndexOnDrop, true);
}

//Slot to set Carousel's size
void CarouselControl::slot_setCarouselSize(QSize MinSize, QSize MaxSize)
{
        size_minSize = MinSize;
        size_maxSize = MaxSize;
}

//Slot to set opacity effect - yet to be used.
void CarouselControl::slot_setOpacityEffectOn(bool effect)
{
    objCommon->bool_isOpacityEffectOn = effect;

}

//Slot to handle the effects of an item being clicked by the user.
void CarouselControl::slot_itemClicked(CarouselItemData data, SignalState state)
{
        //Logging has been added to track the proper notification passed on item being clicked.
    QFile file("log.txt");
     if(file.open(QIODevice::Append | QIODevice::Text))
        {
                 QTextStream out(&file);
                 out << "\nSignal passed from control to parent/main window " << QDateTime::currentDateTime().toString();

        }
         file.close();
         //Raise signal from here that item is clicked
    emit(signal_carouselItemClicked(data, state));

}

//Slot to set an item's state by specifying style for it in "statestyle" variable.
void CarouselControl::slot_setItemState(QString id,  QString stateStyle, bool isAnimationOn, QString state)
{

     itemsList->setItemState(id,stateStyle,isAnimationOn,state);

}

//Slot to update Carousel's geometry
void CarouselControl::slot_updateCarouselGeometry(QSize minSize, QSize maxSize, Orientation dir)
{
        slot_setCarouselSize(minSize, maxSize);
        slot_setOrientation(dir);
}

//Slot to call for removing an item from the list.
void CarouselControl::slot_removeItem(QString id)
{
        itemsList->removeItem(id);
}

//Slot to reset - yet to be implemented
void CarouselControl::slot_reset()
{

}

//Slot to call for adding an item to the list.
void CarouselControl::slot_addItem(QWidget *widget, QString strStyle)
{

    //widget->setParent(itemsList);
        itemsList->appendItem(widget, strStyle);


    //Update HPCarouselItemList from here
}


CarouselControl::~CarouselControl()
{

}


//Slot to set touch size - future use
void CarouselControl:: slot_setTouchSize(QSize sz)
  {
        objCommon->size_touchSize = sz;
  }

//Slot to set infinte loop setting
void CarouselControl::setCarouselInfiniteLoop(bool isInfiniteLoopOn)
{
    objCommon->bool_isInfiniteLoopOn = isInfiniteLoopOn;
    itemsList->isInfiniteLoopOn = isInfiniteLoopOn;
}

//Slot to set carousel position
void CarouselControl::slot_setPosition(int x, int y)
{
    int_left = x;
    int_top = y;
}

//Slot to update item's list arrangement
void CarouselControl::slot_updateItemList()
{
        itemsList->arrangeItems(false,true);
}

//Method to call for initialization of item's list.
void CarouselControl::initializeItemList(bool isArrangeEnabled)
{

                itemsList->initializeList(isArrangeEnabled);

}


//Slot to set orientation of the Carousel.
void CarouselControl::slot_setOrientation(Orientation dir)
{

    objCommon->orientation = dir;


    if(dir == Horizontal)
    {
        objCommon->size_carouselSize = QSize(size_maxSize.width(),size_minSize.height());
         this->setGeometry(int_left, int_top, size_maxSize.width(),size_minSize.height());
                  itemsList->setGeometry(0,0,this->width(),this->height());
         itemsList->setOrientation(Vertical);
         itemsList->setRow(1);

    }
    else
    {
         objCommon->size_carouselSize = QSize(size_minSize.width(),size_maxSize.height());
        this->setGeometry(int_left,int_top, size_minSize.width(),size_maxSize.height());
                 itemsList->setGeometry(0,0,this->width(),this->height());
        itemsList->setOrientation(Horizontal);
        itemsList->setCol(1);

    }

        itemsList->arrangeItems(false, true);
}



//Drag-move event - Moves the selected Carousel item around the Carousel as dragged by the user.
void CarouselControl:: dragMoveEvent(QDragMoveEvent *e)
{
                        e->accept();
                        const QMimeData *data = e->mimeData();

                        QWidget *wdgt = (QWidget*)(data->text().toInt());

                   CarouselItem   *obj = static_cast<CarouselItem*> (wdgt);

                   //Drag object
                        int x =  obj->pos().x() +  e->pos().x() - point_dragStartPosition.x();
                        int y =  obj->pos().y() +  e->pos().y() - point_dragStartPosition.y();

                        obj->setGeometry(x,y, obj->geometry() .width() * obj->getScaleFactor(), obj->geometry().height()*obj->getScaleFactor() );


                          int index = itemsList->getIndexByPos(QPoint(x,y));


                          if(index < 0)
                          {
                                  index = 0;
                          }

                          QWidget* item = itemsList->getItemAt(index);

                         int posX = item->pos().x() +(item->width() /2);
                        int posY = item->pos().y() + (item->height()/2);


                        double width = INDICATOR_WIDTH;
                        double height = INDICATOR_HEIGHT ;//* item->getScaleFactor();


                         if(objCommon->orientation == Vertical) //Make the indicator horizontal
                         {
                                 int temp;
                                 temp = width;
                                 width = height;
                                 height = temp;
                         }


                         //qDebug()<<"Drag move - Index: " <<index;

                        if(objCommon->orientation == Vertical)
                        {
                                                 if(e->pos().x() < posX)
                                                 {
                                                           int_objIndexOnDrop = index;
                                                 }
                                                 else
                                                 {
                                                                int_objIndexOnDrop = index+1;
                                                 }

                                                 QWidget *thisItem = itemsList->getItemAt(int_objIndexOnDrop);

                                                 lbl_indicator->setVisible(true);

                                                 lbl_indicator->setGeometry(itemsList->geometry().x()  + thisItem->geometry().x(),itemsList->geometry().y()  + thisItem->geometry().y(), thisItem->width(),height);
                         }
                        else
                        {
                                        if(e->pos().y() < posY)
                                        {
                                                  int_objIndexOnDrop = index;
                                        }
                                        else
                                        {
                                                   int_objIndexOnDrop = index+1;
                                         }

                                                QWidget *thisItem = itemsList->getItemAt(int_objIndexOnDrop);

                                                lbl_indicator->setVisible(true);

                                                lbl_indicator->setGeometry(itemsList->geometry().x()  + thisItem->geometry().x(), itemsList->geometry().y()+ thisItem->geometry().y(), width,thisItem->height());
                        }

                          point_dragStartPosition = e->pos();

}


//Drop event - Retrieves the object from the mime data of drop event and moves it to the dropped location.
void CarouselControl::dropEvent(QDropEvent *e)
{
    const QMimeData *data = e->mimeData();
    QWidget *wdgt = (QWidget*)(data->text().toInt());
     QWidget *obj = static_cast<QWidget*> (wdgt);

     int x =  obj->pos().x() +  e->pos().x() - point_dragStartPosition.x();
     int y =  obj->pos().y() +  e->pos().y() - point_dragStartPosition.y();

      QPoint pt(x,y);

      obj->setGeometry(x,y,obj->size().width() , obj->size().height());

       //Rearrange list icons
                bool_dragStarted = false;
           lbl_indicator->setVisible(false);
       itemsList->rearrangeItem(obj,pt, int_objIndexOnDrop, true);
}


//Drag enter event - starts drag operation, selected object is moved from its position and list is rearranged to fill in the gap.
void CarouselControl :: dragEnterEvent(QDragEnterEvent *e)
{


    //accept the event here
    point_dragStartPosition = e->pos();
         e->accept();

    if(!bool_dragStarted)
    {
        bool_dragStarted = true;

        const QMimeData *data = e->mimeData();

        QWidget *wdgt = (QWidget*)(data->text().toInt());


        QWidget   *obj = static_cast<QWidget*> (wdgt);
                obj->lower();

        itemsList->rearrangeItem(obj,e->pos(), int_objIndexOnDrop, false); //Any index can be passed as not required in this case.

   }
}

