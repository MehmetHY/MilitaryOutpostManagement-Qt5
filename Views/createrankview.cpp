#include "createrankview.h"
#include "ui_createrankview.h"
#include "../mainwindow.h"
#include "manageranksview.h"

CreateRankView::CreateRankView(MainWindow *parent) :
    QWidget(parent),
    mainWindow(parent),
    ui(new Ui::CreateRankView)
{
    ui->setupUi(this);
    connect(ui->backButton, &QPushButton::pressed, this, &CreateRankView::handleBackButtonPressed);
    connect(ui->createButton, &QPushButton::pressed, this, &CreateRankView::handleCreateButtonPressed);
}

CreateRankView::~CreateRankView()
{
    delete ui;
}

void CreateRankView::handleCreateButtonPressed() const
{

}

void CreateRankView::handleBackButtonPressed() const
{
    mainWindow->changeRootWidget(new ManageRanksView(mainWindow));
}
