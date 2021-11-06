#include "managemenu.h"
#include "ui_managemenu.h"
#include "../mainwindow.h"

ManageMenu::ManageMenu(MainWindow* window, QWidget *parent) :
    QWidget(parent), ui(new Ui::ManageMenu),  mainWindow(window)
{
    ui->setupUi(this);
    connect(ui->backButton, &QPushButton::pressed, this, &ManageMenu::HandleBackButtonPressed);
}

ManageMenu::~ManageMenu()
{
    delete ui;
}

void ManageMenu::HandleBackButtonPressed()
{
    mainWindow->ChangeMenu(MainWindow::Menu::MainMenu);
}
