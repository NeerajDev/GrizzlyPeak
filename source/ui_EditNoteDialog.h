/********************************************************************************
** Form generated from reading UI file 'EditNoteDialog.ui'
**
** Created: Mon Dec 6 15:40:36 2010
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITNOTEDIALOG_H
#define UI_EDITNOTEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditNoteDialog
{
public:
    QLabel *lblAddNoteBg;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *m_ptr_instructions_label;
    QPlainTextEdit *m_ptr_note_text_edit_box;
    QPushButton *m_ptr_done_push_button;
    QLabel *lblnoteTopBar;
    QPushButton *m_ptr_cancel_push_button;
    QLabel *lblnoteSeperator;
    QLabel *m_ptr_keyboard_background_gradient;
    QLabel *lblwindowBg;

    void setupUi(QDialog *EditNoteDialog)
    {
        if (EditNoteDialog->objectName().isEmpty())
            EditNoteDialog->setObjectName(QString::fromUtf8("EditNoteDialog"));
        EditNoteDialog->setWindowModality(Qt::NonModal);
        EditNoteDialog->resize(600, 1024);
        EditNoteDialog->setMinimumSize(QSize(600, 1024));
        EditNoteDialog->setMaximumSize(QSize(600, 1024));
        EditNoteDialog->setWindowOpacity(1);
        EditNoteDialog->setStyleSheet(QString::fromUtf8(""));
        lblAddNoteBg = new QLabel(EditNoteDialog);
        lblAddNoteBg->setObjectName(QString::fromUtf8("lblAddNoteBg"));
        lblAddNoteBg->setGeometry(QRect(20, 130, 560, 775));
        lblAddNoteBg->setMaximumSize(QSize(560, 775));
        lblAddNoteBg->setStyleSheet(QString::fromUtf8(""));
        lblAddNoteBg->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        lblAddNoteBg->setIndent(0);
        layoutWidget = new QWidget(EditNoteDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(80, 140, 461, 301));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        m_ptr_instructions_label = new QLabel(layoutWidget);
        m_ptr_instructions_label->setObjectName(QString::fromUtf8("m_ptr_instructions_label"));
        m_ptr_instructions_label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(m_ptr_instructions_label);

        m_ptr_note_text_edit_box = new QPlainTextEdit(layoutWidget);
        m_ptr_note_text_edit_box->setObjectName(QString::fromUtf8("m_ptr_note_text_edit_box"));
        m_ptr_note_text_edit_box->setMinimumSize(QSize(440, 220));
        m_ptr_note_text_edit_box->setMaximumSize(QSize(440, 225));
        m_ptr_note_text_edit_box->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(m_ptr_note_text_edit_box);

        m_ptr_done_push_button = new QPushButton(EditNoteDialog);
        m_ptr_done_push_button->setObjectName(QString::fromUtf8("m_ptr_done_push_button"));
        m_ptr_done_push_button->setGeometry(QRect(250, 515, 104, 42));
        lblnoteTopBar = new QLabel(EditNoteDialog);
        lblnoteTopBar->setObjectName(QString::fromUtf8("lblnoteTopBar"));
        lblnoteTopBar->setGeometry(QRect(20, 80, 560, 50));
        lblnoteTopBar->setMinimumSize(QSize(560, 50));
        m_ptr_cancel_push_button = new QPushButton(EditNoteDialog);
        m_ptr_cancel_push_button->setObjectName(QString::fromUtf8("m_ptr_cancel_push_button"));
        m_ptr_cancel_push_button->setGeometry(QRect(490, 88, 80, 34));
        m_ptr_cancel_push_button->setMinimumSize(QSize(80, 34));
        lblnoteSeperator = new QLabel(EditNoteDialog);
        lblnoteSeperator->setObjectName(QString::fromUtf8("lblnoteSeperator"));
        lblnoteSeperator->setGeometry(QRect(30, 500, 540, 1));
        lblnoteSeperator->setMinimumSize(QSize(540, 1));
        lblnoteSeperator->setMaximumSize(QSize(540, 1));
        m_ptr_keyboard_background_gradient = new QLabel(EditNoteDialog);
        m_ptr_keyboard_background_gradient->setObjectName(QString::fromUtf8("m_ptr_keyboard_background_gradient"));
        m_ptr_keyboard_background_gradient->setGeometry(QRect(20, 600, 560, 350));
        m_ptr_keyboard_background_gradient->setStyleSheet(QString::fromUtf8(""));
        lblwindowBg = new QLabel(EditNoteDialog);
        lblwindowBg->setObjectName(QString::fromUtf8("lblwindowBg"));
        lblwindowBg->setGeometry(QRect(0, 0, 600, 1024));
        lblwindowBg->raise();
        lblAddNoteBg->raise();
        layoutWidget->raise();
        m_ptr_done_push_button->raise();
        lblnoteTopBar->raise();
        m_ptr_cancel_push_button->raise();
        lblnoteSeperator->raise();
        m_ptr_keyboard_background_gradient->raise();

        retranslateUi(EditNoteDialog);

        QMetaObject::connectSlotsByName(EditNoteDialog);
    } // setupUi

    void retranslateUi(QDialog *EditNoteDialog)
    {
        EditNoteDialog->setWindowTitle(QApplication::translate("EditNoteDialog", "Add / Edit Note", 0, QApplication::UnicodeUTF8));
        lblAddNoteBg->setText(QString());
        m_ptr_instructions_label->setText(QApplication::translate("EditNoteDialog", "Add some notes:", 0, QApplication::UnicodeUTF8));
        m_ptr_note_text_edit_box->setPlainText(QApplication::translate("EditNoteDialog", "Enter text\342\200\246", 0, QApplication::UnicodeUTF8));
        m_ptr_done_push_button->setText(QApplication::translate("EditNoteDialog", "Done", 0, QApplication::UnicodeUTF8));
        lblnoteTopBar->setText(QString());
        m_ptr_cancel_push_button->setText(QApplication::translate("EditNoteDialog", "Cancel", 0, QApplication::UnicodeUTF8));
        lblnoteSeperator->setText(QString());
        m_ptr_keyboard_background_gradient->setText(QString());
        lblwindowBg->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class EditNoteDialog: public Ui_EditNoteDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITNOTEDIALOG_H
