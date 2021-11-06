#ifndef MANAGETEAMSMENU_H
#define MANAGETEAMSMENU_H

#include <QWidget>

namespace Ui {
class ManageTeamsMenu;
}

class ManageTeamsMenu : public QWidget
{
    Q_OBJECT

public:
    explicit ManageTeamsMenu(class MainWindow* window, QWidget *parent = nullptr);
    ~ManageTeamsMenu();

private:
    Ui::ManageTeamsMenu *ui;
    MainWindow* mainWindow;

    void HandleBackButtonPressed();
};

#endif // MANAGETEAMSMENU_H
