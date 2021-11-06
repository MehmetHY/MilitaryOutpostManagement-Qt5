#include "previewmenu.h"
#include "ui_previewmenu.h"
#include "../mainwindow.h"

PreviewMenu::PreviewMenu(MainWindow* window, QWidget *parent) :
    QWidget(parent), ui(new Ui::PreviewMenu),  mainWindow(window)
{
    ui->setupUi(this);
    connect(ui->backButton, &QPushButton::pressed, this, &PreviewMenu::HandleBackButtonPressed);
    connect(ui->hierarchyButton, &QPushButton::pressed, this, &PreviewMenu::HandleHierarchyButtonPressed);
    connect(ui->dutiesButton, &QPushButton::pressed, this, &PreviewMenu::HandleDutiesButtonPressed);
}

PreviewMenu::~PreviewMenu()
{
    delete ui;
}

void PreviewMenu::HandleBackButtonPressed()
{
    mainWindow->ChangeMenu(MainWindow::Menu::MainMenu);
}

void PreviewMenu::HandleHierarchyButtonPressed()
{
    mainWindow->ChangeMenu(MainWindow::Menu::PreviewHierarchyMenu);
}

void PreviewMenu::HandleDutiesButtonPressed()
{
    mainWindow->ChangeMenu(MainWindow::Menu::PreviewDutiesMenu);
}
