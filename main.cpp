#include "mainwindow.h"
#include <QApplication>
#include "Data/datamanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DataManager::CreateConnection();
    MainWindow w;
    w.show();
    return a.exec();
}
