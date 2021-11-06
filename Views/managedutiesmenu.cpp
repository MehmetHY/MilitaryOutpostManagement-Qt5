#include "managedutiesmenu.h"
#include "ui_managedutiesmenu.h"
#include "../mainwindow.h"

ManageDutiesMenu::ManageDutiesMenu(MainWindow* window, QWidget *parent) :
    QWidget(parent), ui(new Ui::ManageDutiesMenu), mainWindow(window)
{
    ui->setupUi(this);
    connect(ui->backButton, &QPushButton::pressed, this, &ManageDutiesMenu::HandleBackButtonPressed);
}

ManageDutiesMenu::~ManageDutiesMenu()
{
    delete ui;
}

void ManageDutiesMenu::HandleBackButtonPressed()
{
    mainWindow->ChangeMenu(MainWindow::Menu::ManageMenu);
}
