/*!
 *  \author    Babak Tootoonchi
 *  \version   1.0
 *  \date      Sept. 2014
 */

#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    return a.exec();
}
