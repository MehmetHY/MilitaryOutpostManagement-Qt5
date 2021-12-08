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
    loadDutiesFromDb();
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
    if (ui->comboBox->count() < 1)
    {
        QMessageBox::warning(mainWindow, "Empty List", "There is no duty!");
        return;
    }
    QString name = ui->comboBox->currentText();
    QMessageBox::StandardButton reply = QMessageBox::question(mainWindow, "Deletion", "Are you sure you want to delete Duty '" + name + "'?");
    if (reply == QMessageBox::Yes)
    {
        Duty::deleteDuty(name);
        unloadDuties();
        loadDutiesFromDb();
    }
}

void DeleteDutyView::loadDutiesFromDb()
{
    QStringList duties;
    Duty::getAllDutyNames(duties);
    ui->comboBox->addItems(duties);
}

void DeleteDutyView::unloadDuties()
{
    ui->comboBox->clear();
}
