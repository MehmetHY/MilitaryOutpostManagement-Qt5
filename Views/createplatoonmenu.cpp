#include "createplatoonmenu.h"
#include "ui_createplatoonmenu.h"

CreatePlatoonMenu::CreatePlatoonMenu(MainWindow* window, QWidget *parent) :
    QWidget(parent), ui(new Ui::CreatePlatoonMenu), mainWindow(window)
{
    ui->setupUi(this);
    connect(ui->quitButton, &QPushButton::pressed, this, &CreatePlatoonMenu::HandleQuitButtonPressed);
}

CreatePlatoonMenu::~CreatePlatoonMenu()
{
    delete ui;
}

void CreatePlatoonMenu::HandleQuitButtonPressed()
{
    QApplication::quit();
}

void CreatePlatoonMenu::HandleCreateButtonPressed()
{

}
