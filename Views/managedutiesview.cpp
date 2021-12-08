#include "managedutiesview.h"
#include "ui_managedutiesview.h"
#include "../mainwindow.h"
#include "dashboard.h"

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

}

void ManageDutiesView::handleUpdateButtonPressed() const
{

}

void ManageDutiesView::handleDeleteButtonPressed() const
{

}

void ManageDutiesView::handleBackButtonPressed() const
{
    mainWindow->changeRootWidget(new DashBoard(mainWindow));
}
