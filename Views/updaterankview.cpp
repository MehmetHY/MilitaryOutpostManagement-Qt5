#include "updaterankview.h"
#include "ui_updaterankview.h"
#include "../mainwindow.h"
#include "../Models/rank.h"
#include "manageranksview.h"
#include "QMessageBox"

UpdateRankView::UpdateRankView(MainWindow *parent) :
    QWidget(parent),
    mainWindow(parent),
    ui(new Ui::UpdateRankView)
{
    ui->setupUi(this);
    connect(ui->updateButton, &QPushButton::pressed, this, &UpdateRankView::handleUpdateButtonPressed);
    connect(ui->backButton, &QPushButton::pressed, this, &UpdateRankView::handleBackButtonPressed);
    loadComboBox();
}

UpdateRankView::~UpdateRankView()
{
    delete ui;
}

void UpdateRankView::loadComboBox()
{
    QStringList ranks;
    Rank::getAllRankNames(ranks);
    ui->comboBox->clear();
    ui->comboBox->addItems(ranks);
}

void UpdateRankView::handleUpdateButtonPressed()
{

}

void UpdateRankView::handleBackButtonPressed() const
{
    mainWindow->changeRootWidget(new ManageRanksView(mainWindow));
}
