#include "mainwindow.h"

#include <QApplication>
#include "Managers/staticmanager.h"
#include "Managers/platoonmanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w();
    w.show();
    return a.exec();

}
