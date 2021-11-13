#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    enum class Menu
    {
        CreatePlatoonMenu, MainMenu, PreviewMenu, PreviewHierarchyMenu, PreviewDutiesMenu,
        ManageMenu, ManagePlatoonMenu, ManageSquadsMenu, ManageTeamsMenu,
        ManageSoldiersMenu, ManageRanksMenu, ManageRolesMenu, ManageDutiesMenu
    };
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void ChangeMenu(Menu menu);

    friend class CreatePlatoonMenu;

private:
    Ui::MainWindow *ui;
    int createPlatoonMenuId;
    int mainMenuId;
    int previewMenuId;
    int manageMenuId;
    int previewHierarchyMenuId;
    int previewDutiesMenuId;
    int managePlatoonMenuId;
    int manageSquadsMenuId;
    int manageTeamsMenuId;
    int manageSoldiersMenuId;
    int manageRanksMenuId;
    int manageRolesMenuId;
    int manageDutiesMenuId;

    int currentMenuId;

    void InitializeMenus();
};
#endif // MAINWINDOW_H
