#include "manageteamsmenu.h"
#include "ui_manageteamsmenu.h"
#include "../mainwindow.h"

ManageTeamsMenu::ManageTeamsMenu(MainWindow* window, QWidget *parent) :
    QWidget(parent), ui(new Ui::ManageTeamsMenu), mainWindow(window)
{
    ui->setupUi(this);
    connect(ui->backButton, &QPushButton::pressed, this, &ManageTeamsMenu::HandleBackButtonPressed);
}

ManageTeamsMenu::~ManageTeamsMenu()
{
    delete ui;
}

void ManageTeamsMenu::HandleBackButtonPressed()
{
    mainWindow->ChangeMenu(MainWindow::Menu::ManageMenu);
}
