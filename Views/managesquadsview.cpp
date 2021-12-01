#include "managesquadsview.h"
#include "ui_managesquadsview.h"
#include "../mainwindow.h"

ManageSquadsView::ManageSquadsView(MainWindow *parent) :
    QWidget(parent),
    ui(new Ui::ManageSquadsView)
{
    ui->setupUi(this);
}

ManageSquadsView::~ManageSquadsView()
{
    delete ui;
}
