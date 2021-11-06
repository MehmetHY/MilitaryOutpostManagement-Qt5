#ifndef MANAGEDUTIESMENU_H
#define MANAGEDUTIESMENU_H

#include <QWidget>

namespace Ui {
class ManageDutiesMenu;
}

class ManageDutiesMenu : public QWidget
{
    Q_OBJECT

public:
    explicit ManageDutiesMenu(class MainWindow* window, QWidget *parent = nullptr);
    ~ManageDutiesMenu();

private:
    Ui::ManageDutiesMenu *ui;
    MainWindow* mainWindow;

    void HandleBackButtonPressed();
};

#endif // MANAGEDUTIESMENU_H
