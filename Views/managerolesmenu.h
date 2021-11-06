#ifndef MANAGEROLESMENU_H
#define MANAGEROLESMENU_H

#include <QWidget>

namespace Ui {
class ManageRolesMenu;
}

class ManageRolesMenu : public QWidget
{
    Q_OBJECT

public:
    explicit ManageRolesMenu(class MainWindow* window, QWidget *parent = nullptr);
    ~ManageRolesMenu();

private:
    Ui::ManageRolesMenu *ui;
    MainWindow* mainWindow;

    void HandleBackButtonPressed();
};

#endif // MANAGEROLESMENU_H
