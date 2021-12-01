#include "createsquadview.h"
#include "ui_createsquadview.h"
#include "../mainwindow.h"

CreateSquadView::CreateSquadView(MainWindow *parent)
    :   QWidget(parent),  mainWindow(parent), ui(new Ui::CreateSquadView)
{
    ui->setupUi(this);
}

CreateSquadView::~CreateSquadView()
{
    delete ui;
}
