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
        MainMenu, PreviewMenu, PreviewHierarchyMenu, PreviewDutiesMenu, ManageMenu
    };
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void ChangeMenu(Menu menu);

private:
    Ui::MainWindow *ui;
    int mainMenuId;
    int previewMenuId;
    int manageMenuId;
    int previewHierarchyMenuId;
    int previewDutiesMenuId;
};
#endif // MAINWINDOW_H
