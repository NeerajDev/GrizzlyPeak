#include <time.h>
#include <QMessageBox>
#include "MyMainWindow.h"
#include "QPlastiqueStyle"

int main(int argc,
         char *argv[])
    {
		    QApplication::setStyle(new QPlastiqueStyle);
    QApplication app(argc,
                     argv);
	

    if (argc != 7)
        {
        QMessageBox::critical(NULL, "Missing command line parameters", "Please provide the following parameters (all strings in double quotes)\nwhere a source is indicated as missing if it has an empty string:\n\n<source 1 name> <source 2 name> <source 3 name> <source 4 name> <chrome option> <Initial Tab [1-4]>");

        return 0;
        }

    else
        {
			qsrand(time(NULL));

			MyMainWindow *main_application_window = new MyMainWindow(argv[1],
																	 argv[2],
																	 argv[3],
                                                                                                                                         argv[4],
                                                                                                                                         argv[5],
                                                                                                                                         atoi(argv[6]));


			main_application_window->show();
			 return app.exec();
        }
    }
