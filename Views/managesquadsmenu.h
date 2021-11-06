#ifndef MANAGESQUADSMENU_H
#define MANAGESQUADSMENU_H

#include <QWidget>

namespace Ui {
class ManageSquadsMenu;
}

class ManageSquadsMenu : public QWidget
{
    Q_OBJECT

public:
    explicit ManageSquadsMenu(class MainWindow* window, QWidget *parent = nullptr);
    ~ManageSquadsMenu();

private:
    Ui::ManageSquadsMenu *ui;
    MainWindow* mainWindow;

    void HandleBackButtonPressed();
};

#endif // MANAGESQUADSMENU_H
