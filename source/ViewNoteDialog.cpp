#include "ViewNoteDialog.h"
#include "Constants.h"

ViewNoteDialog::ViewNoteDialog(QWidget *parent)
               :QDialog(parent)
    {
    setupUi(this);
    this->setAttribute(Qt::WA_TranslucentBackground, true);
    setWindowFlags(Qt::Window |
                   Qt::FramelessWindowHint);

    connect(m_ptr_edit_push_button,
            SIGNAL(clicked(bool)),
            this,
            SLOT(on_edit_push_button_clicked()));

    connect(m_ptr_edit_push_button,
            SIGNAL(clicked(bool)),
            parent,
            SLOT(on_edit_view_2_note_push_button_clicked()));

    connect(m_ptr_close_edit_push_button,
            SIGNAL(clicked(bool)),
            this,
            SLOT(on_close_button_clicked()));
    }

void ViewNoteDialog::showEvent(QShowEvent *event)
    {
    QDialog::showEvent(event);

    move(parentWidget()->geometry().x(),
         parentWidget()->geometry().y());
    }

void ViewNoteDialog::closeEvent(QCloseEvent *e)
    {
    QDialog::closeEvent(e);
    }

void ViewNoteDialog::on_edit_push_button_clicked()
    {
    }

void ViewNoteDialog::set_text(const QString &qstr_new_text)
    {
    m_ptr_text_label->setText(qstr_new_text);
    }

void ViewNoteDialog::on_close_button_clicked()
    {
    hide();
    }
