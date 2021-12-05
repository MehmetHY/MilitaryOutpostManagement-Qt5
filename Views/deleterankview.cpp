#include "deleterankview.h"
#include "ui_deleterankview.h"
#include "../mainwindow.h"
#include "manageranksview.h"
#include "../Models/rank.h"
#include "QMessageBox"

DeleteRankView::DeleteRankView(MainWindow *parent) :
    QWidget(parent),
    mainWindow(parent),
    ui(new Ui::DeleteRankView)
{
    ui->setupUi(this);
    loadComboBox();
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
    if (ui->comboBox->count() < 1)
    {
        QMessageBox::warning(mainWindow, "Empty List", "There is no rank!");
        return;
    }
    QString name = ui->comboBox->currentText();
    QMessageBox::StandardButton reply = QMessageBox::question(mainWindow, "Delete", "Are you sure you want to delete rank " + name + "?");
    if (reply == QMessageBox::Yes)
    {
        Rank::deleteRank(name);
        loadComboBox();
    }
}

void DeleteRankView::loadComboBox()
{
    QStringList ranks;
    Rank::getAllRankNames(ranks);
    ui->comboBox->clear();
    ui->comboBox->addItems(ranks);
}
