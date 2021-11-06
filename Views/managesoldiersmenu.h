#ifndef MANAGESOLDIERSMENU_H
#define MANAGESOLDIERSMENU_H

#include <QWidget>

namespace Ui {
class ManageSoldiersMenu;
}

class ManageSoldiersMenu : public QWidget
{
    Q_OBJECT

public:
    explicit ManageSoldiersMenu(class MainWindow* window, QWidget *parent = nullptr);
    ~ManageSoldiersMenu();

private:
    Ui::ManageSoldiersMenu *ui;
    MainWindow* mainWindow;

    void HandleBackButtonPressed();
};

#endif // MANAGESOLDIERSMENU_H
