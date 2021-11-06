#ifndef CREATEPLATOONMENU_H
#define CREATEPLATOONMENU_H

#include <QWidget>

namespace Ui {
class CreatePlatoonMenu;
}

class CreatePlatoonMenu : public QWidget
{
    Q_OBJECT

public:
    explicit CreatePlatoonMenu(class MainWindow* window, QWidget *parent = nullptr);
    ~CreatePlatoonMenu();

private:
    Ui::CreatePlatoonMenu *ui;
    MainWindow* mainWindow;

    void HandleQuitButtonPressed();
    void HandleCreateButtonPressed();
};

#endif // CREATEPLATOONMENU_H
