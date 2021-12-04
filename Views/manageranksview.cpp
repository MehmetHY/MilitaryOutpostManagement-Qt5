#include "manageranksview.h"
#include "ui_manageranksview.h"
#include "../mainwindow.h"
#include "dashboard.h"

ManageRanksView::ManageRanksView(MainWindow *parent) :
    QWidget(parent),
    mainWindow(parent),
    ui(new Ui::ManageRanksView)
{
    ui->setupUi(this);
    connect(ui->createButton, &QPushButton::pressed, this, &ManageRanksView::handleCreateButtonPressed);
    connect(ui->updateButton, &QPushButton::pressed, this, &ManageRanksView::handleUpdateButtonPressed);
    connect(ui->deleteButton, &QPushButton::pressed, this, &ManageRanksView::handleDeleteButtonPressed);
    connect(ui->backButton, &QPushButton::pressed, this, &ManageRanksView::handleBackButtonPressed);
}

ManageRanksView::~ManageRanksView()
{
    delete ui;
}

void ManageRanksView::handleCreateButtonPressed() const
{

}

void ManageRanksView::handleUpdateButtonPressed() const
{

}

void ManageRanksView::handleDeleteButtonPressed() const
{

}

void ManageRanksView::handleBackButtonPressed() const
{
    mainWindow->changeRootWidget(new DashBoard(mainWindow));
}
