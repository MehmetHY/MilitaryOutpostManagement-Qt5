#ifndef MANAGEPLATOONMENU_H
#define MANAGEPLATOONMENU_H

#include <QWidget>

namespace Ui {
class ManagePlatoonMenu;
}

class ManagePlatoonMenu : public QWidget
{
    Q_OBJECT

public:
    explicit ManagePlatoonMenu(class MainWindow* window, QWidget *parent = nullptr);
    ~ManagePlatoonMenu();

private:
    Ui::ManagePlatoonMenu *ui;
    MainWindow* mainWindow;

    void HandleBackButtonPressed();
};

#endif // MANAGEPLATOONMENU_H
