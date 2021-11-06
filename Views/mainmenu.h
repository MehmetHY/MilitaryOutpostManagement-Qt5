#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>

namespace Ui {
class MainMenu;
}

class MainMenu : public QWidget
{
    Q_OBJECT

public:
    explicit MainMenu(class MainWindow* window, QWidget *parent = nullptr);
    ~MainMenu();

private:
    Ui::MainMenu *ui;
    MainWindow* mainWindow;
    void HandleQuitButtonPressed() const;
    void HandlePreviewButtonPressed() const;
    void HandleManageButtonPressed() const;
};

#endif // MAINMENU_H
