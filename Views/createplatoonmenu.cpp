#include "createplatoonmenu.h"
#include "ui_createplatoonmenu.h"
#include <QMessageBox>
#include "../mainwindow.h"
#include "../Managers/platoonmanager.h"
#include "../Models/Platoon.h"
#include <QDebug>

CreatePlatoonMenu::CreatePlatoonMenu(MainWindow* window, QWidget *parent) :
    QWidget(parent), ui(new Ui::CreatePlatoonMenu), mainWindow(window)
{
    ui->setupUi(this);
    connect(ui->quitButton, &QPushButton::pressed, this, &CreatePlatoonMenu::HandleQuitButtonPressed);
    connect(ui->createButton, &QPushButton::pressed, this, &CreatePlatoonMenu::HandleCreateButtonPressed);
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
    QString platoonName = ui->platoonNameLineEdit->text().trimmed();
    qDebug() << platoonName;
    if (platoonName.isEmpty())
    {
        QMessageBox::warning(this, "Invalid Name", "Cannot be empty!");
        return;
    }
    mainWindow->platoonManager->CreateNewPlatoon(platoonName);
    mainWindow->ChangeMenu(MainWindow::Menu::MainMenu);
}
