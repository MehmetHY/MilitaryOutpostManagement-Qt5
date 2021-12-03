#include "createteamview.h"
#include "ui_createteamview.h"

CreateTeamView::CreateTeamView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateTeamView)
{
    ui->setupUi(this);
}

CreateTeamView::~CreateTeamView()
{
    delete ui;
}
