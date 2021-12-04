#include "createsoldierview.h"
#include "ui_createsoldierview.h"
#include "../mainwindow.h"
#include "managesoldiersview.h"

CreateSoldierView::CreateSoldierView(MainWindow *parent)
    :   QWidget(parent), mainWindow(parent), ui(new Ui::CreateSoldierView)
{
    ui->setupUi(this);
    connect(ui->backButton, &QPushButton::pressed, this, &CreateSoldierView::handleBackButtonPressed);
    connect(ui->createButton, &QPushButton::pressed, this, &CreateSoldierView::handleCreateButtonPressed);
}

CreateSoldierView::~CreateSoldierView()
{
    delete ui;
}

void CreateSoldierView::handleCreateButtonPressed() const
{

}

void CreateSoldierView::handleBackButtonPressed() const
{
    mainWindow->changeRootWidget(new ManageSoldiersView(mainWindow));
}
