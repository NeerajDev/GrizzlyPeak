#include "ui_ViewNoteDialog.h"

class ViewNoteDialog : public QDialog,
                       private Ui_ViewNoteDialog
    {
    Q_OBJECT

    public:

        ViewNoteDialog(QWidget *parent = 0);

        void set_text(const QString &qstr_new_text);

    protected:

        void showEvent(QShowEvent *event);
        void closeEvent(QCloseEvent *e);

    private slots:

        void on_edit_push_button_clicked();
        void on_close_button_clicked();

    private:
    };
