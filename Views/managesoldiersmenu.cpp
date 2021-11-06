#include "managesoldiersmenu.h"
#include "ui_managesoldiersmenu.h"
#include "../mainwindow.h"

ManageSoldiersMenu::ManageSoldiersMenu(MainWindow* window, QWidget *parent) :
    QWidget(parent), ui(new Ui::ManageSoldiersMenu), mainWindow(window)
{
    ui->setupUi(this);
    connect(ui->backButton, &QPushButton::pressed, this, &ManageSoldiersMenu::HandleBackButtonPressed);
}

ManageSoldiersMenu::~ManageSoldiersMenu()
{
    delete ui;
}

void ManageSoldiersMenu::HandleBackButtonPressed()
{
    mainWindow->ChangeMenu(MainWindow::Menu::ManageMenu);
}
