#include "dutyview.h"
#include "ui_dutyview.h"
#include "../mainwindow.h"
#include "../Data/datamanager.h"
#include "../Models/duty.h"

DutyView::DutyView(MainWindow *parent) : QWidget(parent), ui(new Ui::DutyView), mainWindow(parent)
{
    ui->setupUi(this);
}

DutyView::~DutyView()
{
    delete ui;
}

void DutyView::setupDutyTable()
{
    QList<Duty> duties;
}
