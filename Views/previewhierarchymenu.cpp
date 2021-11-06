#include "previewhierarchymenu.h"
#include "ui_previewhierarchymenu.h"
#include "../mainwindow.h"

PreviewHierarchyMenu::PreviewHierarchyMenu(MainWindow* window, QWidget *parent) :
    QWidget(parent), ui(new Ui::PreviewHierarchyMenu), mainWindow(window)
{
    ui->setupUi(this);
    connect(ui->backButton, &QPushButton::pressed, this, &PreviewHierarchyMenu::HandleBackButtonPressed);
}

PreviewHierarchyMenu::~PreviewHierarchyMenu()
{
    delete ui;
}

void PreviewHierarchyMenu::HandleBackButtonPressed()
{
    mainWindow->ChangeMenu(MainWindow::Menu::PreviewMenu);
}
