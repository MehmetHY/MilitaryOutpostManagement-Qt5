#include "deletedutyview.h"
#include "ui_deletedutyview.h"
#include "../mainwindow.h"
#include "../Models/duty.h"
#include "managedutiesview.h"
#include "QMessageBox"

DeleteDutyView::DeleteDutyView(MainWindow *parent) :
    QWidget(parent),
    mainWindow(parent),
    ui(new Ui::DeleteDutyView)
{
    ui->setupUi(this);
    connect(ui->backButton, &QPushButton::pressed, this, &DeleteDutyView::handleBackButtonPressed);
    connect(ui->deleteButton, &QPushButton::pressed, this, &DeleteDutyView::handleDeleteButtonPressed);
}

DeleteDutyView::~DeleteDutyView()
{
    delete ui;
}

void DeleteDutyView::handleBackButtonPressed() const
{
    mainWindow->changeRootWidget(new ManageDutiesView(mainWindow));
}

void DeleteDutyView::handleDeleteButtonPressed()
{

}
