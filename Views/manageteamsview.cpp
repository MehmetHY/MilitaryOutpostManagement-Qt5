#include "manageteamsview.h"
#include "ui_manageteamsview.h"
#include "../mainwindow.h"
#include "dashboard.h"

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

}

void ManageTeamsView::handleUpdateButtonPressed() const
{

}

void ManageTeamsView::handleDeleteButtonPressed() const
{

}

void ManageTeamsView::handleBackButtonPressed() const
{
    mainWindow->changeRootWidget(new DashBoard(mainWindow));
}
