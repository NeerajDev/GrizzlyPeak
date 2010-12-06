/********************************************************************************
** Form generated from reading UI file 'HPcarouselcontrol.ui'
**
** Created: Fri Dec 3 15:18:39 2010
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HPCAROUSELCONTROL_H
#define UI_HPCAROUSELCONTROL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CarouselControlClass
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CarouselControlClass)
    {
        if (CarouselControlClass->objectName().isEmpty())
            CarouselControlClass->setObjectName(QString::fromUtf8("CarouselControlClass"));
        CarouselControlClass->resize(600, 400);
        centralWidget = new QWidget(CarouselControlClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        CarouselControlClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CarouselControlClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        CarouselControlClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CarouselControlClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        CarouselControlClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CarouselControlClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        CarouselControlClass->setStatusBar(statusBar);

        retranslateUi(CarouselControlClass);

        QMetaObject::connectSlotsByName(CarouselControlClass);
    } // setupUi

    void retranslateUi(QMainWindow *CarouselControlClass)
    {
        CarouselControlClass->setWindowTitle(QApplication::translate("CarouselControlClass", "CarouselControl", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CarouselControlClass: public Ui_CarouselControlClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HPCAROUSELCONTROL_H
