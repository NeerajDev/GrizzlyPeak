#include <QFile>
#include "EditNoteDialog.h"
#include "Constants.h"

EditNoteDialog::EditNoteDialog(QWidget *parent)
               :QDialog(parent)
    {
    setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->setWindowFlags(Qt::Window |
                         Qt::FramelessWindowHint);

    m_ptr_virtual_keyboard = new WidgetKeyboard(this);
    m_ptr_virtual_keyboard->setGeometry(22,600,548,325);

    m_ptr_keyboard_background_gradient->setObjectName(QString::fromUtf8("WidgetKeyboard"));
    setAppStyle();
    this->setAttribute(Qt::WA_TranslucentBackground, true);


    connect(m_ptr_cancel_push_button,
            SIGNAL(clicked(bool)),
            this,
            SLOT(on_cancel_push_button_clicked()));

    connect(m_ptr_done_push_button,
            SIGNAL(clicked(bool)),
            this,
            SLOT(on_done_push_button_clicked()));

    connect(m_ptr_done_push_button,
            SIGNAL(clicked(bool)),
            parent,
            SLOT(on_done_view_2_note_push_button_clicked()));
    }


void EditNoteDialog::showEvent(QShowEvent *event)
    {
    QDialog::showEvent(event);

    move(parentWidget()->geometry().x(),
         parentWidget()->geometry().y());

    m_ptr_virtual_keyboard->show();

    m_ptr_note_text_edit_box->setFocus();
    }

void EditNoteDialog::closeEvent(QCloseEvent *e)
    {
    m_ptr_note_text_edit_box->setPlainText(m_qstr_cancellation_undo_text);

    QDialog::closeEvent(e);

    m_ptr_virtual_keyboard->hide();
    }

void EditNoteDialog::on_cancel_push_button_clicked()
    {
    m_ptr_note_text_edit_box->setPlainText(m_qstr_cancellation_undo_text);

    m_ptr_virtual_keyboard->hide();

    hide();
    }

void EditNoteDialog::on_done_push_button_clicked()
    {
    m_qstr_cancellation_undo_text = get_text();

    m_ptr_virtual_keyboard->hide();

    hide();
    }

void EditNoteDialog::set_text(const QString &qstr_new_text)
    {
    m_ptr_note_text_edit_box->setPlainText(qstr_new_text);

    m_qstr_cancellation_undo_text = qstr_new_text;
    }

QString EditNoteDialog::get_text() const
    {
    return m_ptr_note_text_edit_box->toPlainText();
    }

void EditNoteDialog::setAppStyle()
    {
    QFile file(":/styles.qss");
    file.open(QFile::ReadOnly);
    setStyleSheet(file.readAll());
    }
