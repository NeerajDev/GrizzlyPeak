#include "ui_EditNoteDialog.h"
#include "WidgetKeyboard.h"

class EditNoteDialog : public QDialog,
                       private Ui_EditNoteDialog
    {
    Q_OBJECT

    public:

        EditNoteDialog(QWidget *parent = 0);

        void set_text(const QString &qstr_new_text);
        QString get_text() const;

    protected:

        void showEvent(QShowEvent *event);
        void closeEvent(QCloseEvent *e);

    private slots:

        void on_cancel_push_button_clicked();
        void on_done_push_button_clicked();
        void setAppStyle();

    private:

        QString m_qstr_cancellation_undo_text;

        WidgetKeyboard *m_ptr_virtual_keyboard;
    };
