#include "mainwindow.h"

#include <QApplication>
#include "Managers/staticmanager.h"
#include "Managers/platoonmanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StaticManager::InitializeStaticManagers();
    PlatoonManager platoonManager;
    MainWindow w(&platoonManager);
    w.show();
    int exitValue = a.exec();
    StaticManager::EndStaticManagers();
    return exitValue;
}
