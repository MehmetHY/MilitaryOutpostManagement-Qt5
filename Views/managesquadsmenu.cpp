#include "managesquadsmenu.h"
#include "ui_managesquadsmenu.h"
#include "../mainwindow.h"

ManageSquadsMenu::ManageSquadsMenu(MainWindow* window, QWidget *parent) :
    QWidget(parent), ui(new Ui::ManageSquadsMenu), mainWindow(window)
{
    ui->setupUi(this);
    connect(ui->backButton, &QPushButton::pressed, this, &ManageSquadsMenu::HandleBackButtonPressed);
}

ManageSquadsMenu::~ManageSquadsMenu()
{
    delete ui;
}

void ManageSquadsMenu::HandleBackButtonPressed()
{
    mainWindow->ChangeMenu(MainWindow::Menu::ManageMenu);
}
