#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "../mainwindow.h"

MainMenu::MainMenu(MainWindow* window, QWidget *parent) :
    QWidget(parent), ui(new Ui::MainMenu), mainWindow(window)
{
    ui->setupUi(this);
    connect(ui->quitButton, &QPushButton::pressed, this, &MainMenu::HandleQuitButtonPressed);
    connect(ui->previewButton, &QPushButton::pressed, this, &MainMenu::HandlePreviewButtonPressed);
    connect(ui->manageButton, &QPushButton::pressed, this, &MainMenu::HandleManageButtonPressed);
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::HandleQuitButtonPressed() const
{
    QApplication::quit();
}

void MainMenu::HandlePreviewButtonPressed() const
{
    mainWindow->ChangeMenu(MainWindow::Menu::PreviewMenu);
}

void MainMenu::HandleManageButtonPressed() const
{
    mainWindow->ChangeMenu(MainWindow::Menu::ManageMenu);
}
