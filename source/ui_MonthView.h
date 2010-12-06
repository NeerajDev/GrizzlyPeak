/********************************************************************************
** Form generated from reading UI file 'MonthView.ui'
**
** Created: Mon Dec 6 17:06:12 2010
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONTHVIEW_H
#define UI_MONTHVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MonthView
{
public:
    QFrame *MainFrame;
    QPushButton *pushButton_2;
    QLabel *labelHeader;
    QTableWidget *tblHeader;
    QPushButton *pushButton;
    QTableWidget *tblDates;

    void setupUi(QWidget *MonthView)
    {
        if (MonthView->objectName().isEmpty())
            MonthView->setObjectName(QString::fromUtf8("MonthView"));
        MonthView->resize(929, 731);
        MonthView->setStyleSheet(QString::fromUtf8(""));
        MainFrame = new QFrame(MonthView);
        MainFrame->setObjectName(QString::fromUtf8("MainFrame"));
        MainFrame->setGeometry(QRect(0, 0, 525, 375));
        MainFrame->setStyleSheet(QString::fromUtf8(""));
        MainFrame->setFrameShape(QFrame::StyledPanel);
        MainFrame->setFrameShadow(QFrame::Raised);
        pushButton_2 = new QPushButton(MainFrame);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(390, 18, 0, 0));
        pushButton_2->setStyleSheet(QString::fromUtf8(""));
        labelHeader = new QLabel(MainFrame);
        labelHeader->setObjectName(QString::fromUtf8("labelHeader"));
        labelHeader->setGeometry(QRect(52, 18, 0, 0));
        labelHeader->setStyleSheet(QString::fromUtf8(""));
        labelHeader->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        tblHeader = new QTableWidget(MainFrame);
        tblHeader->setObjectName(QString::fromUtf8("tblHeader"));
        tblHeader->setGeometry(QRect(0, 0, 525, 22));
        tblHeader->setStyleSheet(QString::fromUtf8(""));
        tblHeader->setFrameShape(QFrame::NoFrame);
        tblHeader->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tblHeader->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tblHeader->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblHeader->setSelectionMode(QAbstractItemView::NoSelection);
        tblHeader->setGridStyle(Qt::NoPen);
        tblHeader->setCornerButtonEnabled(false);
        tblHeader->horizontalHeader()->setVisible(false);
        tblHeader->horizontalHeader()->setMinimumSectionSize(10);
        pushButton = new QPushButton(MainFrame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 18, 0, 0));
        pushButton->setAutoFillBackground(false);
        pushButton->setStyleSheet(QString::fromUtf8(""));
        pushButton->setAutoDefault(true);
        pushButton->setDefault(false);
        pushButton->setFlat(false);
        tblDates = new QTableWidget(MainFrame);
        tblDates->setObjectName(QString::fromUtf8("tblDates"));
        tblDates->setGeometry(QRect(0, 23, 525, 350));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tblDates->sizePolicy().hasHeightForWidth());
        tblDates->setSizePolicy(sizePolicy);
        tblDates->setStyleSheet(QString::fromUtf8(""));
        tblDates->setFrameShape(QFrame::StyledPanel);
        tblDates->setFrameShadow(QFrame::Raised);
        tblDates->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tblDates->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tblDates->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblDates->setSelectionMode(QAbstractItemView::SingleSelection);
        tblDates->setShowGrid(false);
        tblDates->setCornerButtonEnabled(false);

        retranslateUi(MonthView);

        QMetaObject::connectSlotsByName(MonthView);
    } // setupUi

    void retranslateUi(QWidget *MonthView)
    {
        MonthView->setWindowTitle(QApplication::translate("MonthView", "Form", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QString());
        labelHeader->setText(QApplication::translate("MonthView", "February, 2010", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MonthView: public Ui_MonthView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONTHVIEW_H
