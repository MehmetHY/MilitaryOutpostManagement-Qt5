#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Data/platoonmanager.h"
#include "Views/createplatoonmenu.h"
#include "Views/mainmenu.h"
#include "Views/previewmenu.h"
#include "Views/managemenu.h"
#include "Views/previewhierarchymenu.h"
#include "Views/previewdutiesmenu.h"
#include "Views/manageplatoonmenu.h"
#include "Views/managesquadsmenu.h"
#include "Views/manageteamsmenu.h"
#include "Views/managesoldiersmenu.h"
#include "Views/manageranksmenu.h"
#include "Views/managerolesmenu.h"
#include "Views/managedutiesmenu.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
}

MainWindow::~MainWindow()
{
    delete ui;
    InitializeMenus();
    ChangeMenu(Menu::MainMenu);
}

void MainWindow::ChangeMenu(Menu menu)
{
    int id;
    switch (menu)
    {
    case MainWindow::Menu::CreatePlatoonMenu:
        id = createPlatoonMenuId;
        break;
    case MainWindow::Menu::ManagePlatoonMenu:
        id = managePlatoonMenuId;
        break;
    case MainWindow::Menu::ManageSquadsMenu:
        id = manageSquadsMenuId;
        break;
    case MainWindow::Menu::ManageTeamsMenu:
        id = manageTeamsMenuId;
        break;
    case MainWindow::Menu::ManageSoldiersMenu:
        id = manageSoldiersMenuId;
        break;
    case MainWindow::Menu::ManageRanksMenu:
        id = manageRanksMenuId;
        break;
    case MainWindow::Menu::ManageRolesMenu:
        id = manageRolesMenuId;
        break;
    case MainWindow::Menu::ManageDutiesMenu:
        id = manageDutiesMenuId;
        break;
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

void MainWindow::InitializeMenus()
{
    CreatePlatoonMenu* createPlatoonMenu = new CreatePlatoonMenu(this);
    createPlatoonMenuId = ui->stackedWidget->addWidget(createPlatoonMenu);

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

    ManagePlatoonMenu* managePlatoonMenu = new ManagePlatoonMenu(this);
    managePlatoonMenuId = ui->stackedWidget->addWidget(managePlatoonMenu);

    ManageSquadsMenu* manageSquadsMenu = new ManageSquadsMenu(this);
    manageSquadsMenuId = ui->stackedWidget->addWidget(manageSquadsMenu);

    ManageTeamsMenu* manageTeamsMenu = new ManageTeamsMenu(this);
    manageTeamsMenuId = ui->stackedWidget->addWidget(manageTeamsMenu);

    ManageSoldiersMenu* manageSoldiersMenu = new ManageSoldiersMenu(this);
    manageSoldiersMenuId = ui->stackedWidget->addWidget(manageSoldiersMenu);

    ManageRanksMenu* manageRanksMenu = new ManageRanksMenu(this);
    manageRanksMenuId = ui->stackedWidget->addWidget(manageRanksMenu);

    ManageRolesMenu* manageRolesMenu = new ManageRolesMenu(this);
    manageRolesMenuId = ui->stackedWidget->addWidget(manageRolesMenu);

    ManageDutiesMenu* manageDutiesMenu = new ManageDutiesMenu(this);
    manageDutiesMenuId = ui->stackedWidget->addWidget(manageDutiesMenu);

}
