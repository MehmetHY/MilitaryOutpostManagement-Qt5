#include "deletesoldierview.h"
#include "ui_deletesoldierview.h"
#include "../mainwindow.h"
#include "../Models/squad.h"
#include "../Models/team.h"
#include "../Models/soldier.h"
#include "managesoldiersview.h"
#include "QMessageBox"

DeleteSoldierView::DeleteSoldierView(MainWindow *parent)
    :   QWidget(parent), mainWindow(parent), ui(new Ui::DeleteSoldierView)
{
    ui->setupUi(this);
    initializeComboBoxes();
    connect(ui->squadComboBox, &QComboBox::currentTextChanged, this, &DeleteSoldierView::loadTeamComboBox);
    connect(ui->teamComboBox, &QComboBox::currentTextChanged, this, &DeleteSoldierView::loadSoldierComboBox);
    connect(ui->backButton, &QPushButton::pressed, this, &DeleteSoldierView::handleBackButtonPressed);
    connect(ui->deleteButton, &QPushButton::pressed, this, &DeleteSoldierView::handleDeleteButtonPressed);
}

DeleteSoldierView::~DeleteSoldierView()
{
    delete ui;
}

void DeleteSoldierView::handleBackButtonPressed() const
{
    mainWindow->changeRootWidget(new ManageSoldiersView(mainWindow));
}

void DeleteSoldierView::handleDeleteButtonPressed()
{
    if (ui->squadComboBox->count() < 1)
    {
        QMessageBox::warning(mainWindow, "Empty List", "There is no squad!");
        return;
    }
    if (ui->teamComboBox->count() < 1)
    {
        QMessageBox::warning(mainWindow, "Empty List", "There is no team!");
        return;
    }
    if (ui->soldierComboBox->count() < 1)
    {
        QMessageBox::warning(mainWindow, "Empty List", "There is no soldier!");
        return;
    }
    QString name = ui->soldierComboBox->currentText();
    QMessageBox::StandardButton reply = QMessageBox::question(mainWindow, "Delete", "Are you sure you want to delete soldier " + name + "?");
    if (reply == QMessageBox::Yes)
    {
        int squadId = Squad::getIdByName(ui->squadComboBox->currentText());
        int teamId = Team::getTeamId(squadId, ui->teamComboBox->currentText());
        Soldier::deleteSoldier(ui->soldierComboBox->currentText(), teamId);
        loadSoldierComboBox();
    }
}

void DeleteSoldierView::initializeComboBoxes()
{
    loadSquadComboBox();
    loadTeamComboBox();
    loadSoldierComboBox();
}

void DeleteSoldierView::loadSquadComboBox()
{
    QStringList squads;
    Squad::getAllSquadNames(squads);
    ui->squadComboBox->addItems(squads);
}

void DeleteSoldierView::loadTeamComboBox()
{
    int squadId = Squad::getIdByName(ui->squadComboBox->currentText());
    QStringList teams;
    Team::getAllTeamNames(squadId, teams);
    ui->teamComboBox->clear();
    ui->teamComboBox->addItems(teams);
}

void DeleteSoldierView::loadSoldierComboBox()
{
    QStringList soldiers;
    int squadId = Squad::getIdByName(ui->squadComboBox->currentText());
    int teamId = Team::getTeamId(squadId, ui->teamComboBox->currentText());
    Soldier::getAllSoldierNames(teamId, soldiers);
    ui->soldierComboBox->clear();
    ui->soldierComboBox->addItems(soldiers);
}
