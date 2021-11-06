#include "manageranksmenu.h"
#include "ui_manageranksmenu.h"
#include "../mainwindow.h"

ManageRanksMenu::ManageRanksMenu(MainWindow* window, QWidget *parent) :
    QWidget(parent), ui(new Ui::ManageRanksMenu), mainWindow(window)
{
    ui->setupUi(this);
    connect(ui->backButton, &QPushButton::pressed, this, &ManageRanksMenu::HandleBackButtonPressed);
}

ManageRanksMenu::~ManageRanksMenu()
{
    delete ui;
}

void ManageRanksMenu::HandleBackButtonPressed()
{
    mainWindow->ChangeMenu(MainWindow::Menu::ManageMenu);
}
