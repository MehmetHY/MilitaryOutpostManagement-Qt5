#include "managerolesmenu.h"
#include "ui_managerolesmenu.h"
#include "../mainwindow.h"

ManageRolesMenu::ManageRolesMenu(MainWindow* window, QWidget *parent) :
    QWidget(parent), ui(new Ui::ManageRolesMenu), mainWindow(window)
{
    ui->setupUi(this);
    connect(ui->backButton, &QPushButton::pressed, this, &ManageRolesMenu::HandleBackButtonPressed);
}

ManageRolesMenu::~ManageRolesMenu()
{
    delete ui;
}

void ManageRolesMenu::HandleBackButtonPressed()
{
    mainWindow->ChangeMenu(MainWindow::Menu::ManageMenu);
}
