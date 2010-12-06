#include "CarouselItem.h"


#include "CommonUtility.h"
#include "CarouselItemData.h"

#define SIGNAL_DURATION  3 //duration to modify the item state -  single/double/press-hold
#define POSX_ITEMTEXT 30 //item;s text position x
#define POSY_ITEMTEXT 100//item;s text position y
#define INTERVAL_SIGNALS 50 //Additional interval to default doubleClickInterval() used to track different click situations by the user
#define WIDTH_ITEMTEXT 70
#define DRAG_OFFSET  4 //Value to decide drag start in opposite direction from orientation while scrolling
#define INTERVAL_TRACETIMER 175 // Duration for trace timer


//Constructor initializes the class variables
CarouselItem::CarouselItem(QPixmap* pic, CarouselItemData data, QString strStyle, QWidget *parent)
        : QLabel(parent)
{
    this->setMinSize(QSize(100,100));
    this->pixmap = pic;
    this->data = data;
    this->setPixmap(*pixmap);
    this->setScaleFactor(1);
        if(data.bool_isDraggable)
        {
                setAcceptDrops(true);
        }
    objCommon = &CommonUtility::getInstance();

    //New style
        if(strStyle == "")
        {
                this->setStyleSheet("background-color:qlineargradient(spread:pad, x1:0.5, y1:0.65, x2:0.5, y2:0, stop:0 rgba(0, 0, 0,175), stop:1 rgba(0, 0, 0,75)); border-radius: 5px; border: 1px solid #585954;");
        }
        else
        {
                this->setStyleSheet(strStyle);
        }


    timer_traceSignal = new QTimer(this);
    timer_traceSignal->setInterval(QApplication::doubleClickInterval() +INTERVAL_SIGNALS); //50 added to increase the duration from default doubleClickInterval
    connect(timer_traceSignal,SIGNAL(timeout()), this, SLOT(slot_raiseSignal()));

    bool_isMousePressed = false;
    bool_isPressHoldSignalSent = false;
    bool_isProcessingOn = false;

        bool_isDragEnabled = true;
}



//Slot to raise a signal whenever a Carousel item is selected
//It send a signal along with the information regarding state of the mouse which can be:
//1. Single click
//2. Double click
//3. Press and Hold
//4. Hold-release
void CarouselItem::slot_raiseSignal()
{
    int_duration ++;
    CarouselItemData d = this->getCarouselItemData();

        QFile file("log.txt");
        if(!bool_isProcessingOn)
    {
                bool_isProcessingOn = true;
                if(bool_isMousePressed)
                {
                        timer_traceSignal->stop();
                         timer_traceSignal->setInterval(0);
                        bool_isMousePressed = false;

                        if(int_duration <= SIGNAL_DURATION) //single click after counter
                        {
                                if(point_curMousePos==point_startPos) //Single click
                                  {
                                          if(file.open(QIODevice::Append | QIODevice::Text))
                                                {
                                                         QTextStream out(&file);
                                                         out << "\nSignal raised on item single click " << QDateTime::currentDateTime().toString();

                                                }
                                          emit(signal_carouselItemSelected(d, SingleClick));
                                  }
                        }
                        else  if(int_duration > SIGNAL_DURATION)
                        {
                                 if(file.open(QIODevice::Append | QIODevice::Text))
                                        {
                                                 QTextStream out(&file);
                                                 out << "\nSignal raised on item hold and Release " << QDateTime::currentDateTime().toString();

                                        }
                                 emit(signal_carouselItemSelected(d, HoldRelease)); //hold-release
                        }

    }
    else
    {

        if(int_duration > SIGNAL_DURATION)
        {
            if(!bool_isPressHoldSignalSent)
            {
                                 if(file.open(QIODevice::Append | QIODevice::Text))
                                {
                                         QTextStream out(&file);
                                         out << "\nSignal raised on item press-Hold  " << QDateTime::currentDateTime().toString();

                                }
                 emit(signal_carouselItemSelected(d, PressHold)); //Press-hold
                bool_isPressHoldSignalSent = true;
            }
        }
    }
}

bool_isProcessingOn = false;
file.close();
}

//Method to set the item's style sheet as passed by the main application to indicate its current mouse state
//like if it is single-click or double-click etc.
void CarouselItem::setItemState(QString style, QString state)
{
    this->setStyleSheet(style);
    this->data.string_itemState = state;
}


//Event to trigger drag-drop operation
void CarouselItem::mouseMoveEvent(QMouseEvent *event)
{
    if ( (event->buttons() & Qt::LeftButton))
    {
          timer_traceSignal->stop();
           timer_traceSignal->setInterval(0);
             point_curMousePos = event->pos();

            int diffX = event->pos().x() - point_startPos.x();
            int diffY = event->pos().y() - point_startPos.y();

            if(objCommon->orientation == Vertical)
            {

                                if(data.bool_isDraggable)
                                {
                                          if (!bool_isScrolling && (qAbs(diffY) < DRAG_OFFSET && diffX != 0))
                                         {
                                                        isDragging = true;
                                                         performDrag();

                                         }
                                         else
                                         {
                                                  if(!isDragging)
                                                  {
                                                          bool_isScrolling = true;
                                                        emit(signal_mousePressed(event));
                                                  }
                                         }
                                }
                                else
                                {
                                                        bool_isScrolling = true;
                                                        emit(signal_mousePressed(event));
                                }

            }
            else
            {

                                if(data.bool_isDraggable)
                                {
                                         if(!bool_isScrolling &&(qAbs(diffX) < DRAG_OFFSET && diffY != 0))
                                         {
                                                         isDragging = true;
                                                         performDrag();

                                         }
                                         else
                                         {
                                                  if(!isDragging)
                                                  {
                                                            bool_isScrolling = true;
                                                                emit(signal_mousePressed(event));
                                                  }
                                         }
                }
                                else
                                {
                                                        bool_isScrolling = true;
                                                        emit(signal_mousePressed(event));
                                }

            }


       }
    point_startPos = event->pos();
}


//Method to actually start dragging as the mouse is pressed and held over an item.
//This method sets current item's pointer as mime data of the dragged object.
//It also raises a signal as an item is attempted to drag in invalid area.
void CarouselItem::performDrag()
{

    if (this)
     {
                          this->setScaleFactor(1);
            QMimeData *mimeData = new QMimeData;
            mimeData->setText(QString::number((int)this));

                        QDrag *drag = new QDrag(this);//this);
            drag->setMimeData(mimeData);
            if(!drag->exec(Qt::CopyAction | Qt::MoveAction))
                        {
                                emit(signal_draggedInInvalideArea(this));
                        }
        }

}


// Paint event of the class - It draws image associated to the Carousel item and scales it
// according to the item size.
void CarouselItem::paintEvent(QPaintEvent *)
{

    QPainter p(this);

        if((pixmap->width() >  this->geometry().width() ) ||  (pixmap->height() >  this->geometry().height() ))
        {
                        qreal aspect_ratio = (qreal)pixmap->width()/(qreal)pixmap->height();

                        qreal newWidth = pixmap->width();
                        qreal newHeight = pixmap->height();

                        if(pixmap->width() > pixmap->height())
                        {
                                newWidth =  this->geometry().width();
                                newHeight = newWidth/aspect_ratio;

                                if(newHeight > this->geometry().height())
                                {
                                        newHeight = this->geometry().height();
                                        newWidth = newHeight * aspect_ratio;
                                }
                        }
                        else if(pixmap->width() < pixmap->height())
                        {
                                newHeight = this->geometry().height();
                                newWidth = newHeight * aspect_ratio;

                                if(newWidth > this->geometry().width())
                                {
                                        newWidth = this->geometry().width();
                                        newHeight = newWidth/aspect_ratio;
                                }
                        }
                        else
                        {

                                if(this->geometry().height() > this->geometry().width())
                                {
                                        newHeight = this->geometry().width() ;
                                        newWidth = newHeight * aspect_ratio ;
                                }
                                else
                                {
                                        newHeight = this->geometry().height() ;
                                        newWidth = newHeight  * aspect_ratio;
                                }
                        }

                        QPixmap pic = pixmap->scaled(newWidth, newHeight);

                        qreal x = this->geometry().width() /2 - pic.width()/2;
                        qreal y = this->geometry().height()/2 - pic.height()/2;

                        p.drawPixmap(x,y, pic);
        }
        else
        {
                        qreal x = this->geometry().width()/2 - pixmap->width()/2;
                        qreal y = this->geometry().height()/2 - pixmap->height()/2;

                        p.drawPixmap(x,y, *pixmap);
        }


}




//Mouse Down event -  sets timer to trace the mouse state and tracks the initial mouse position before drag.
void CarouselItem::mousePressEvent(QMouseEvent *e)
{
  emit (signal_mouseDown(e));

        isDragging = false;
     bool_isPressHoldSignalSent = false;
      bool_isMousePressed = false;
          bool_isScrolling = false;

          if (e->button() == Qt::LeftButton)
                {
                        point_startPos = e->pos();
                         point_curMousePos = e->pos();
                 }

    time_mouseClick = QDateTime::currentDateTime();
    timer_traceSignal->setInterval(INTERVAL_TRACETIMER);
    int_duration = 0;
    timer_traceSignal->start();

}

//Mouse -release event - resets the variable for next mouse-down event.
void CarouselItem::mouseReleaseEvent(QMouseEvent *)
{

        bool_isScrolling = false;
    bool_isMousePressed = true;
        isDragging = false;
}


//Mouse double click event - sends a signal that mouse is double clicked
void CarouselItem::mouseDoubleClickEvent(QMouseEvent *)
{
    bool_isMousePressed = true;
    timer_traceSignal->stop();
    timer_traceSignal->setInterval(0);

    //raise signal
      CarouselItemData d = this->getCarouselItemData();
      emit (signal_carouselItemSelected(d,DoubleClick));

          QFile file("log.txt");
                 if(file.open(QIODevice::Append | QIODevice::Text))
                {
                         QTextStream out(&file);
                         out << "\nSignal raised on item double click  " << QDateTime::currentDateTime().toString();

                }
         file.close();

}

//Properties

void CarouselItem::setItemPixmap(QPixmap *pic)
{
    pixmap = pic;
}

QPixmap* CarouselItem::getItemPixmap()
{
    return pixmap;
}

void CarouselItem::setCarouselItemData(CarouselItemData d)
{
    data = d;
}

CarouselItemData CarouselItem::getCarouselItemData()
{
    return data;
}
void CarouselItem::setItemSize(QSize s)
{
    size_itemSize = s;
}

QSize CarouselItem::getItemSize()
{
    return size_itemSize;
}

void CarouselItem::setPosition(QPoint s)
{
   point_position = s;
}

QPoint CarouselItem::getPosition()
{
    return point_position;
}

void CarouselItem::setScaleFactor(double s)
{
   dbl_scaleFactor = s;
}

double CarouselItem::getScaleFactor()
{
    return dbl_scaleFactor;
}

void CarouselItem::setMinSize(QSize s)
{
    size_minSize = s;
}

QSize CarouselItem::getMinSize()
{
    return size_minSize;
}

void CarouselItem::setMaxSize(QSize s)
{
    size_maxSize = s;
}

QSize CarouselItem::getMaxSize()
{
    return size_maxSize;
}
void CarouselItem::setIndex(int  i)
{
    int_listIndex = i;
}

int CarouselItem::getIndex()
{
    return int_listIndex;
}

