#include "previewmenu.h"
#include "ui_previewmenu.h"
#include "../mainwindow.h"

PreviewMenu::PreviewMenu(MainWindow* window, QWidget *parent) :
    QWidget(parent), ui(new Ui::PreviewMenu),  mainWindow(window)
{
    ui->setupUi(this);
    connect(ui->backButton, &QPushButton::pressed, this, &PreviewMenu::HandleBackButtonPressed);
}

PreviewMenu::~PreviewMenu()
{
    delete ui;
}

void PreviewMenu::HandleBackButtonPressed()
{
    mainWindow->ChangeMenu(MainWindow::Menu::MainMenu);
}
