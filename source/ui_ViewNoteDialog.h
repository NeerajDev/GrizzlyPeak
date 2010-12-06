/********************************************************************************
** Form generated from reading UI file 'ViewNoteDialog.ui'
**
** Created: Mon Dec 6 15:40:36 2010
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWNOTEDIALOG_H
#define UI_VIEWNOTEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ViewNoteDialog
{
public:
    QLabel *lblnoteTopBar;
    QLabel *lblAddNoteBg;
    QLabel *m_ptr_notes_on_today_label;
    QPushButton *m_ptr_edit_push_button;
    QLabel *m_ptr_text_label;
    QPushButton *m_ptr_close_edit_push_button;
    QLabel *lblwindowBg;

    void setupUi(QDialog *ViewNoteDialog)
    {
        if (ViewNoteDialog->objectName().isEmpty())
            ViewNoteDialog->setObjectName(QString::fromUtf8("ViewNoteDialog"));
        ViewNoteDialog->setWindowModality(Qt::NonModal);
        ViewNoteDialog->resize(600, 1024);
        ViewNoteDialog->setMaximumSize(QSize(600, 1024));
        ViewNoteDialog->setStyleSheet(QString::fromUtf8(""));
        lblnoteTopBar = new QLabel(ViewNoteDialog);
        lblnoteTopBar->setObjectName(QString::fromUtf8("lblnoteTopBar"));
        lblnoteTopBar->setGeometry(QRect(20, 80, 560, 50));
        lblnoteTopBar->setMinimumSize(QSize(560, 50));
        lblAddNoteBg = new QLabel(ViewNoteDialog);
        lblAddNoteBg->setObjectName(QString::fromUtf8("lblAddNoteBg"));
        lblAddNoteBg->setGeometry(QRect(20, 130, 560, 775));
        lblAddNoteBg->setMaximumSize(QSize(560, 775));
        lblAddNoteBg->setStyleSheet(QString::fromUtf8(""));
        lblAddNoteBg->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        lblAddNoteBg->setIndent(0);
        m_ptr_notes_on_today_label = new QLabel(ViewNoteDialog);
        m_ptr_notes_on_today_label->setObjectName(QString::fromUtf8("m_ptr_notes_on_today_label"));
        m_ptr_notes_on_today_label->setGeometry(QRect(0, 80, 600, 50));
        m_ptr_notes_on_today_label->setMaximumSize(QSize(600, 16777215));
        m_ptr_notes_on_today_label->setAlignment(Qt::AlignCenter);
        m_ptr_edit_push_button = new QPushButton(ViewNoteDialog);
        m_ptr_edit_push_button->setObjectName(QString::fromUtf8("m_ptr_edit_push_button"));
        m_ptr_edit_push_button->setGeometry(QRect(250, 455, 102, 37));
        m_ptr_text_label = new QLabel(ViewNoteDialog);
        m_ptr_text_label->setObjectName(QString::fromUtf8("m_ptr_text_label"));
        m_ptr_text_label->setGeometry(QRect(100, 215, 415, 230));
        m_ptr_text_label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        m_ptr_text_label->setWordWrap(true);
        m_ptr_close_edit_push_button = new QPushButton(ViewNoteDialog);
        m_ptr_close_edit_push_button->setObjectName(QString::fromUtf8("m_ptr_close_edit_push_button"));
        m_ptr_close_edit_push_button->setGeometry(QRect(535, 88, 39, 34));
        lblwindowBg = new QLabel(ViewNoteDialog);
        lblwindowBg->setObjectName(QString::fromUtf8("lblwindowBg"));
        lblwindowBg->setGeometry(QRect(0, 0, 600, 1024));
        lblwindowBg->raise();
        lblnoteTopBar->raise();
        lblAddNoteBg->raise();
        m_ptr_notes_on_today_label->raise();
        m_ptr_edit_push_button->raise();
        m_ptr_text_label->raise();
        m_ptr_close_edit_push_button->raise();

        retranslateUi(ViewNoteDialog);

        QMetaObject::connectSlotsByName(ViewNoteDialog);
    } // setupUi

    void retranslateUi(QDialog *ViewNoteDialog)
    {
        ViewNoteDialog->setWindowTitle(QApplication::translate("ViewNoteDialog", "View Note", 0, QApplication::UnicodeUTF8));
        lblnoteTopBar->setText(QString());
        lblAddNoteBg->setText(QString());
        m_ptr_notes_on_today_label->setText(QApplication::translate("ViewNoteDialog", "Notes on today", 0, QApplication::UnicodeUTF8));
        m_ptr_edit_push_button->setText(QApplication::translate("ViewNoteDialog", "Edit", 0, QApplication::UnicodeUTF8));
        m_ptr_text_label->setText(QApplication::translate("ViewNoteDialog", "Note Contents", 0, QApplication::UnicodeUTF8));
        m_ptr_close_edit_push_button->setText(QString());
        lblwindowBg->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ViewNoteDialog: public Ui_ViewNoteDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWNOTEDIALOG_H
