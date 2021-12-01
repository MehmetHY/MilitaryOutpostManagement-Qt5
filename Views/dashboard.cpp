#include "dashboard.h"
#include "ui_dashboard.h"
#include "../mainwindow.h"
#include "dutyview.h"
#include "managesquadsview.h"

DashBoard::DashBoard(MainWindow *parent) : QWidget(parent), ui(new Ui::DashBoard), mainWindow(parent)
{
    ui->setupUi(this);
    connect(ui->viewDutiesButton, &QPushButton::pressed, this, &DashBoard::handleViewDutiesButtonPressed);
    connect(ui->manageDutiesButton, &QPushButton::pressed, this, &DashBoard::handleManageDutiesButtonPressed);
    connect(ui->manageSoldiersButton, &QPushButton::pressed, this, &DashBoard::handleManageSoldiersButtonPressed);
    connect(ui->manageTeamsButton, &QPushButton::pressed, this, &DashBoard::handleManageTeamsButtonPressed);
    connect(ui->manageSquadsButton, &QPushButton::pressed, this, &DashBoard::handleManageSquadsButtonPressed);
}

DashBoard::~DashBoard()
{
    delete ui;
}

void DashBoard::handleViewDutiesButtonPressed()
{
    mainWindow->changeRootWidget(new DutyView(mainWindow));
}

void DashBoard::handleManageDutiesButtonPressed()
{

}

void DashBoard::handleManageSoldiersButtonPressed()
{

}

void DashBoard::handleManageTeamsButtonPressed()
{

}

void DashBoard::handleManageSquadsButtonPressed()
{
    mainWindow->changeRootWidget(new ManageSquadsView(mainWindow));
}
