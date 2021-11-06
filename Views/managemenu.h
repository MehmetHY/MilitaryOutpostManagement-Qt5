#ifndef MANAGEMENU_H
#define MANAGEMENU_H

#include <QWidget>

namespace Ui {
class ManageMenu;
}

class ManageMenu : public QWidget
{
    Q_OBJECT

public:
    explicit ManageMenu(class MainWindow* window, QWidget *parent = nullptr);
    ~ManageMenu();

private:
    Ui::ManageMenu *ui;
    MainWindow* mainWindow;

    void HandleBackButtonPressed();
    void HandlePlatoonButtonPressed();
    void HandleSquadsButtonPressed();
    void HandleTeamsButtonPressed();
    void HandleSoldiersButtonPressed();
    void HandleRanksButtonPressed();
    void HandleRolesButtonPressed();
    void HandleDutiesButtonPressed();
};

#endif // MANAGEMENU_H
