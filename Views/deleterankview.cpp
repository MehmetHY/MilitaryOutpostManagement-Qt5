#include "deleterankview.h"
#include "ui_deleterankview.h"
#include "../mainwindow.h"
#include "manageranksview.h"

DeleteRankView::DeleteRankView(MainWindow *parent) :
    QWidget(parent),
    mainWindow(parent),
    ui(new Ui::DeleteRankView)
{
    ui->setupUi(this);
    initializeComboBox();
    connect(ui->backButton, &QPushButton::pressed, this, &DeleteRankView::handleBackButtonPressed);
    connect(ui->deleteButton, &QPushButton::pressed, this, &DeleteRankView::handleDeleteButtonPressed);
}

DeleteRankView::~DeleteRankView()
{
    delete ui;
}

void DeleteRankView::handleBackButtonPressed() const
{
    mainWindow->changeRootWidget(new ManageRanksView(mainWindow));
}

void DeleteRankView::handleDeleteButtonPressed()
{

}

void DeleteRankView::initializeComboBox()
{

}
