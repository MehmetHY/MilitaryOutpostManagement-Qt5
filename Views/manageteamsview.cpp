#include "manageteamsview.h"
#include "ui_manageteamsview.h"
#include "../mainwindow.h"
#include "dashboard.h"
#include "createteamview.h"
#include "deleteteamview.h"
#include "updateteamview.h"

ManageTeamsView::ManageTeamsView(MainWindow *parent)
    :   QWidget(parent),  mainWindow(parent), ui(new Ui::ManageTeamsView)
{
    ui->setupUi(this);
    connect(ui->createButton, &QPushButton::pressed, this, &ManageTeamsView::handleCreateButtonPressed);
    connect(ui->updateButton, &QPushButton::pressed, this, &ManageTeamsView::handleUpdateButtonPressed);
    connect(ui->deleteButton, &QPushButton::pressed, this, &ManageTeamsView::handleDeleteButtonPressed);
    connect(ui->backButton, &QPushButton::pressed, this, &ManageTeamsView::handleBackButtonPressed);
}

ManageTeamsView::~ManageTeamsView()
{
    delete ui;
}

void ManageTeamsView::handleCreateButtonPressed() const
{
    mainWindow->changeRootWidget(new CreateTeamView(mainWindow));
}

void ManageTeamsView::handleUpdateButtonPressed() const
{
    mainWindow->changeRootWidget(new UpdateTeamView(mainWindow));
}

void ManageTeamsView::handleDeleteButtonPressed() const
{
    mainWindow->changeRootWidget(new DeleteTeamView(mainWindow));
}

void ManageTeamsView::handleBackButtonPressed() const
{
    mainWindow->changeRootWidget(new DashBoard(mainWindow));
}
