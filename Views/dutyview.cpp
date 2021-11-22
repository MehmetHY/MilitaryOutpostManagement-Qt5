#include "dutyview.h"
#include "ui_dutyview.h"

DutyView::DutyView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DutyView)
{
    ui->setupUi(this);
}

DutyView::~DutyView()
{
    delete ui;
}
