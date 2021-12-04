#include "managesoldiersview.h"
#include "ui_managesoldiersview.h"
#include "../mainwindow.h"

ManageSoldiersView::ManageSoldiersView(MainWindow *parent)
    :   QWidget(parent),  mainWindow(parent), ui(new Ui::ManageSoldiersView)
{
    ui->setupUi(this);
    connect(ui->createButton, &QPushButton::pressed, this, &ManageSoldiersView::handleCreateButtonPressed);
    connect(ui->updateButton, &QPushButton::pressed, this, &ManageSoldiersView::handleUpdateButtonPressed);
    connect(ui->deleteButton, &QPushButton::pressed, this, &ManageSoldiersView::handleDeleteButtonPressed);
    connect(ui->backButton, &QPushButton::pressed, this, &ManageSoldiersView::handleBackButtonPressed);
}

ManageSoldiersView::~ManageSoldiersView()
{
    delete ui;
}

void ManageSoldiersView::handleCreateButtonPressed() const
{

}

void ManageSoldiersView::handleUpdateButtonPressed() const
{

}

void ManageSoldiersView::handleDeleteButtonPressed() const
{

}

void ManageSoldiersView::handleBackButtonPressed() const
{

}
