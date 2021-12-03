#include "deletesquadview.h"
#include "ui_deletesquadview.h"
#include "../mainwindow.h"
#include "../Models/squad.h"
#include "managesquadsview.h"

#include <QMessageBox>

DeleteSquadView::DeleteSquadView(MainWindow *parent)
    :   QWidget(parent), mainWindow(parent), ui(new Ui::DeleteSquadView)
{
    ui->setupUi(this);
    initializeComboBox();
    connect(ui->backButton, &QPushButton::pressed, this, &DeleteSquadView::handleBackButtonPressed);
    connect(ui->deleteButton, &QPushButton::pressed, this, &DeleteSquadView::handleDeleteButtonPressed);
}

DeleteSquadView::~DeleteSquadView()
{
    delete ui;
}

void DeleteSquadView::initializeComboBox()
{
    QStringList squads;
    Squad::getAllSquadNames(squads);
    ui->comboBox->addItems(squads);
}

void DeleteSquadView::handleBackButtonPressed() const
{
    mainWindow->changeRootWidget(new ManageSquadsView(mainWindow));
}

void DeleteSquadView::handleDeleteButtonPressed()
{
    if (ui->comboBox->count() < 1)
    {
        QMessageBox::warning(mainWindow, "Empty List", "There is no squad!");
        return;
    }
    QString squad = ui->comboBox->currentText();
    QMessageBox::StandardButton reply = QMessageBox::question(mainWindow, "Delete", "Are you sure you want to delete squad: " + squad);
    if (reply == QMessageBox::Yes)
    {
        Squad::deleteSquad(squad);
        ui->comboBox->clear();
        initializeComboBox();
    }
}
