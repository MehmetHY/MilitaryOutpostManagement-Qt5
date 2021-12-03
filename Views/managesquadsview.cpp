#include "managesquadsview.h"
#include "ui_managesquadsview.h"
#include "../mainwindow.h"
#include "createsquadview.h"
#include "dashboard.h"
#include "deletesquadview.h"
#include "updatesquadview.h"

ManageSquadsView::ManageSquadsView(MainWindow *parent)
    : QWidget(parent),  mainWindow(parent), ui(new Ui::ManageSquadsView)
{
    ui->setupUi(this);
    connect(ui->createButton, &QPushButton::pressed, this, &ManageSquadsView::handleCreateButtonPressed);
    connect(ui->updateButton, &QPushButton::pressed, this, &ManageSquadsView::handleUpdateButtonPressed);
    connect(ui->deleteButton, &QPushButton::pressed, this, &ManageSquadsView::handleDeleteButtonPressed);
    connect(ui->backButton, &QPushButton::pressed, this, &ManageSquadsView::handleBackButtonPressed);
}

ManageSquadsView::~ManageSquadsView()
{
    delete ui;
}

void ManageSquadsView::handleCreateButtonPressed() const
{
    mainWindow->changeRootWidget(new CreateSquadView(mainWindow));
}

void ManageSquadsView::handleUpdateButtonPressed() const
{
    mainWindow->changeRootWidget(new UpdateSquadView(mainWindow));
}

void ManageSquadsView::handleDeleteButtonPressed() const
{
    mainWindow->changeRootWidget(new DeleteSquadView(mainWindow));
}

void ManageSquadsView::handleBackButtonPressed() const
{
    mainWindow->changeRootWidget(new DashBoard(mainWindow));
}
