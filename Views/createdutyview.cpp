#include "createdutyview.h"
#include "ui_createdutyview.h"
#include "../mainwindow.h"
#include "managedutiesview.h"

CreateDutyView::CreateDutyView(MainWindow *parent) :
    QWidget(parent),
    mainWindow(parent),
    ui(new Ui::CreateDutyView)
{
    ui->setupUi(this);
    connect(ui->backButton, &QPushButton::pressed, this, &CreateDutyView::handleBackButtonPressed);
    connect(ui->createButton, &QPushButton::pressed, this, &CreateDutyView::handleCreateButtonPressed);
}

CreateDutyView::~CreateDutyView()
{
    delete ui;
}

void CreateDutyView::handleCreateButtonPressed() const
{

}

void CreateDutyView::handleBackButtonPressed() const
{
    mainWindow->changeRootWidget(new ManageDutiesView(mainWindow));
}
