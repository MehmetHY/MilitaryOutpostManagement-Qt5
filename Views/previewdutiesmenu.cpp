#include "previewdutiesmenu.h"
#include "ui_previewdutiesmenu.h"
#include "../mainwindow.h"

PreviewDutiesMenu::PreviewDutiesMenu(MainWindow* window, QWidget *parent) :
    QWidget(parent), ui(new Ui::PreviewDutiesMenu), mainWindow(window)
{
    ui->setupUi(this);
    connect(ui->backButton, &QPushButton::pressed, this, &PreviewDutiesMenu::HandleBackButtonPressed);
}

PreviewDutiesMenu::~PreviewDutiesMenu()
{
    delete ui;
}

void PreviewDutiesMenu::HandleBackButtonPressed()
{
    mainWindow->ChangeMenu(MainWindow::Menu::PreviewMenu);
}
