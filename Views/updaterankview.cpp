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
    if (ui->comboBox->count() < 1)
    {
        QMessageBox::warning(mainWindow, "Empty List", "There is no rank!");
        return;
    }
    QString newName = ui->lineEdit->text().trimmed();
    if (newName.isEmpty())
    {
        QMessageBox::warning(mainWindow, "Invalid Input", "Name cannot be empty!");
        return;
    }
    if (Rank::isRankExist(newName))
    {
        QMessageBox::warning(mainWindow, "Invalid Input", "Rank " + newName + " already exist!");
        return;
    }
    QString oldName = ui->comboBox->currentText();
    Rank::updateRank(oldName, newName);
    ui->lineEdit->clear();
    loadComboBox();
}

void UpdateRankView::handleBackButtonPressed() const
{
    mainWindow->changeRootWidget(new ManageRanksView(mainWindow));
}
