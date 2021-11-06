#include "manageplatoonmenu.h"
#include "ui_manageplatoonmenu.h"
#include "../mainwindow.h"

ManagePlatoonMenu::ManagePlatoonMenu(MainWindow* window, QWidget *parent) :
    QWidget(parent), ui(new Ui::ManagePlatoonMenu), mainWindow(window)
{
    ui->setupUi(this);
    connect(ui->backButton, &QPushButton::pressed, this, &ManagePlatoonMenu::HandleBackButtonPressed);
}

ManagePlatoonMenu::~ManagePlatoonMenu()
{
    delete ui;
}

void ManagePlatoonMenu::HandleBackButtonPressed()
{
    mainWindow->ChangeMenu(MainWindow::Menu::ManageMenu);
}
