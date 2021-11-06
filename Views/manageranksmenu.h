#ifndef MANAGERANKSMENU_H
#define MANAGERANKSMENU_H

#include <QWidget>

namespace Ui {
class ManageRanksMenu;
}

class ManageRanksMenu : public QWidget
{
    Q_OBJECT

public:
    explicit ManageRanksMenu(class MainWindow* window, QWidget *parent = nullptr);
    ~ManageRanksMenu();

private:
    Ui::ManageRanksMenu *ui;
    MainWindow* mainWindow;

    void HandleBackButtonPressed();
};

#endif // MANAGERANKSMENU_H
