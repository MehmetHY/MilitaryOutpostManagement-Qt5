#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Views/mainmenu.h"
#include "Views/previewmenu.h"
#include "Views/managemenu.h"
#include "Views/previewhierarchymenu.h"
#include "Views/previewdutiesmenu.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MainMenu* mainMenu = new MainMenu(this);
    mainMenuId = ui->stackedWidget->addWidget(mainMenu);

    PreviewMenu* previewMenu = new PreviewMenu(this);
    previewMenuId = ui->stackedWidget->addWidget(previewMenu);

    ManageMenu* manageMenu = new ManageMenu(this);
    manageMenuId = ui->stackedWidget->addWidget(manageMenu);

    PreviewHierarchyMenu* previewHierarchyMenu = new PreviewHierarchyMenu(this);
    previewHierarchyMenuId = ui->stackedWidget->addWidget(previewHierarchyMenu);

    PreviewDutiesMenu* previewDutiesMenu = new PreviewDutiesMenu(this);
    previewDutiesMenuId = ui->stackedWidget->addWidget(previewDutiesMenu);

    ChangeMenu(Menu::MainMenu);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ChangeMenu(Menu menu)
{
    int id;
    switch (menu)
    {
    case MainWindow::Menu::PreviewHierarchyMenu:
        id = previewHierarchyMenuId;
        break;
    case MainWindow::Menu::PreviewDutiesMenu:
        id = previewDutiesMenuId;
        break;
    case MainWindow::Menu::MainMenu:
        id = mainMenuId;
        break;
    case MainWindow::Menu::PreviewMenu:
        id = previewMenuId;
        break;
    case MainWindow::Menu::ManageMenu:
        id = manageMenuId;
        break;
    }
    ui->stackedWidget->setCurrentIndex(id);
}
