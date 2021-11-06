#include "managemenu.h"
#include "ui_managemenu.h"
#include "../mainwindow.h"

ManageMenu::ManageMenu(MainWindow* window, QWidget *parent) :
    QWidget(parent), ui(new Ui::ManageMenu), mainWindow(window)
{
    ui->setupUi(this);
    connect(ui->backButton, &QPushButton::pressed, this, &ManageMenu::HandleBackButtonPressed);
    connect(ui->platoonButton, &QPushButton::pressed, this, &ManageMenu::HandlePlatoonButtonPressed);
    connect(ui->squadsButton, &QPushButton::pressed, this, &ManageMenu::HandleSquadsButtonPressed);
    connect(ui->teamsButton, &QPushButton::pressed, this, &ManageMenu::HandleTeamsButtonPressed);
    connect(ui->soldiersButton, &QPushButton::pressed, this, &ManageMenu::HandleSoldiersButtonPressed);
    connect(ui->ranksButton, &QPushButton::pressed, this, &ManageMenu::HandleRanksButtonPressed);
    connect(ui->rolesButton, &QPushButton::pressed, this, &ManageMenu::HandleRolesButtonPressed);
    connect(ui->dutiesButton, &QPushButton::pressed, this, &ManageMenu::HandleDutiesButtonPressed);
}

ManageMenu::~ManageMenu()
{
    delete ui;
}

void ManageMenu::HandleBackButtonPressed()
{
    mainWindow->ChangeMenu(MainWindow::Menu::MainMenu);
}

void ManageMenu::HandlePlatoonButtonPressed()
{
    mainWindow->ChangeMenu(MainWindow::Menu::ManagePlatoonMenu);
}

void ManageMenu::HandleSquadsButtonPressed()
{
    mainWindow->ChangeMenu(MainWindow::Menu::ManageSquadsMenu);
}

void ManageMenu::HandleTeamsButtonPressed()
{
    mainWindow->ChangeMenu(MainWindow::Menu::ManageTeamsMenu);
}

void ManageMenu::HandleSoldiersButtonPressed()
{
    mainWindow->ChangeMenu(MainWindow::Menu::ManageSoldiersMenu);
}

void ManageMenu::HandleRanksButtonPressed()
{
    mainWindow->ChangeMenu(MainWindow::Menu::ManageRanksMenu);
}

void ManageMenu::HandleRolesButtonPressed()
{
    mainWindow->ChangeMenu(MainWindow::Menu::ManageRolesMenu);
}

void ManageMenu::HandleDutiesButtonPressed()
{
    mainWindow->ChangeMenu(MainWindow::Menu::ManageDutiesMenu);
}
