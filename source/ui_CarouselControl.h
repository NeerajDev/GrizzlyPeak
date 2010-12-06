/********************************************************************************
** Form generated from reading UI file 'CarouselControl.ui'
**
** Created: Sat Dec 4 16:17:07 2010
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAROUSELCONTROL_H
#define UI_CAROUSELCONTROL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CarouselControl
{
public:

    void setupUi(QWidget *CarouselControl)
    {
        if (CarouselControl->objectName().isEmpty())
            CarouselControl->setObjectName(QString::fromUtf8("CarouselControl"));
        CarouselControl->resize(400, 300);

        retranslateUi(CarouselControl);

        QMetaObject::connectSlotsByName(CarouselControl);
    } // setupUi

    void retranslateUi(QWidget *CarouselControl)
    {
        CarouselControl->setWindowTitle(QApplication::translate("CarouselControl", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CarouselControl: public Ui_CarouselControl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAROUSELCONTROL_H
