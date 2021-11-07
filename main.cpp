#include "mainwindow.h"

#include <QApplication>
#include "Managers/DataManager.h"
#include "Managers/platoonmanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DataManager dataManager;
    dataManager.CreateConnection();
    PlatoonManager platoonManager(&dataManager);
    MainWindow w(&platoonManager);
    w.show();
    return a.exec();
}
