#include "managedutiesview.h"
#include "ui_managedutiesview.h"
#include "../mainwindow.h"
#include "dashboard.h"
#include "createdutyview.h"
#include "deletedutyview.h"
#include "updatedutyview.h"

ManageDutiesView::ManageDutiesView(MainWindow *parent) :
    QWidget(parent),
    mainWindow(parent),
    ui(new Ui::ManageDutiesView)
{
    ui->setupUi(this);
    connect(ui->createButton, &QPushButton::pressed, this, &ManageDutiesView::handleCreateButtonPressed);
    connect(ui->updateButton, &QPushButton::pressed, this, &ManageDutiesView::handleUpdateButtonPressed);
    connect(ui->deleteButton, &QPushButton::pressed, this, &ManageDutiesView::handleDeleteButtonPressed);
    connect(ui->backButton, &QPushButton::pressed, this, &ManageDutiesView::handleBackButtonPressed);
}

ManageDutiesView::~ManageDutiesView()
{
    delete ui;
}

void ManageDutiesView::handleCreateButtonPressed() const
{
    mainWindow->changeRootWidget(new CreateDutyView(mainWindow));
}

void ManageDutiesView::handleUpdateButtonPressed() const
{
    mainWindow->changeRootWidget(new UpdateDutyView(mainWindow));
}

void ManageDutiesView::handleDeleteButtonPressed() const
{
    mainWindow->changeRootWidget(new DeleteDutyView(mainWindow));
}

void ManageDutiesView::handleBackButtonPressed() const
{
    mainWindow->changeRootWidget(new DashBoard(mainWindow));
}
