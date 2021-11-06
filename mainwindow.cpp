#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Views/mainmenu.h"
#include "Views/previewmenu.h"
#include "Views/managemenu.h"

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
