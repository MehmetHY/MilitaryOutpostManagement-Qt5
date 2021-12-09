#include "dutyview.h"
#include "ui_dutyview.h"
#include "../mainwindow.h"
#include "../Models/duty.h"
#include "../Models/soldier.h"
#include "dashboard.h"
#include "QDebug"

DutyView::DutyView(MainWindow *parent) : QWidget(parent), ui(new Ui::DutyView), mainWindow(parent)
{
    ui->setupUi(this);
    connect(ui->backButton, &QPushButton::pressed, this, &DutyView::handleBackButtonPressed);
    setupDutyTable();
}

DutyView::~DutyView()
{
    delete ui;
}

void DutyView::setupDutyTable()
{
    QList<Duty*> duties;
    Duty::getAllDuties(duties);
    qDebug() << "Duty count: " << duties.count();
    ui->dutyTable->setRowCount(duties.count());
    for (int i = 0; i < duties.count(); i++)
    {
        QString name = duties[i]->getName();
        QString soldierName = Soldier::getSoldierNameById(duties[i]->getSoldierId());
        QString startDate = duties[i]->getStartDate().toString("dd MMMM yyyy hh:mm");
        QString endDate = duties[i]->getEndDate().toString("dd MMMM yyyy hh:mm");
        qDebug() << name;
        qDebug() << soldierName;
        qDebug() << startDate;
        qDebug() << endDate;
        QTableWidgetItem* nameItem = new QTableWidgetItem(name);
        nameItem->setFlags(nameItem->flags() ^ Qt::ItemFlag::ItemIsEditable);
        QTableWidgetItem* soldierItem = new QTableWidgetItem(soldierName, 1);
        soldierItem->setFlags(soldierItem->flags() ^ Qt::ItemFlag::ItemIsEditable);
        QTableWidgetItem* startDateItem = new QTableWidgetItem(startDate, 1);
        startDateItem->setFlags(startDateItem->flags() ^ Qt::ItemFlag::ItemIsEditable);
        QTableWidgetItem* endDateItem = new QTableWidgetItem(endDate, 1);
        endDateItem->setFlags(endDateItem->flags() ^ Qt::ItemFlag::ItemIsEditable);
        ui->dutyTable->setItem(i, 0, nameItem);
        ui->dutyTable->setItem(i, 1, soldierItem);
        ui->dutyTable->setItem(i, 2, startDateItem);
        ui->dutyTable->setItem(i, 3, endDateItem);
    }
    qDeleteAll(duties);
}

void DutyView::handleBackButtonPressed() const
{
    mainWindow->changeRootWidget(new DashBoard(mainWindow));
}
