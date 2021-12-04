#include "updatesoldierview.h"
#include "ui_updatesoldierview.h"
#include "../mainwindow.h"
#include "../Models/squad.h"
#include "../Models/team.h"
#include "../Models/soldier.h"
#include "QMessageBox"
#include "managesoldiersview.h"

UpdateSoldierView::UpdateSoldierView(MainWindow *parent)
    :   QWidget(parent), mainWindow(parent), ui(new Ui::UpdateSoldierView)
{
    ui->setupUi(this);
    connect(ui->squadComboBox, &QComboBox::currentTextChanged, this, &UpdateSoldierView::loadTeamComboBox);
    connect(ui->teamComboBox, &QComboBox::currentTextChanged, this, &UpdateSoldierView::loadSoldierComboBox);
    connect(ui->soldierComboBox, &QComboBox::currentTextChanged, this, &UpdateSoldierView::loadLineEditTexts);
    connect(ui->updateButton, &QPushButton::pressed, this, &UpdateSoldierView::handleUpdateButtonPressed);
    connect(ui->backButton, &QPushButton::pressed, this, &UpdateSoldierView::handleBackButtonPressed);
    initializeElements();
}

UpdateSoldierView::~UpdateSoldierView()
{
    delete ui;
}

void UpdateSoldierView::initializeElements()
{
    loadSquadComboBox();
    loadTeamComboBox();
    loadSoldierComboBox();
    loadLineEditTexts();
}

void UpdateSoldierView::handleUpdateButtonPressed()
{

}

void UpdateSoldierView::handleBackButtonPressed() const
{
    mainWindow->changeRootWidget(new ManageSoldiersView(mainWindow));
}

void UpdateSoldierView::loadSquadComboBox()
{
    QStringList squads;
    Squad::getAllSquadNames(squads);
    ui->squadComboBox->addItems(squads);
}

void UpdateSoldierView::loadTeamComboBox()
{
    int squadId = Squad::getIdByName(ui->squadComboBox->currentText());
    QStringList teams;
    Team::getAllTeamNames(squadId, teams);
    ui->teamComboBox->clear();
    ui->teamComboBox->addItems(teams);
}

void UpdateSoldierView::loadSoldierComboBox()
{
    int squadId = Squad::getIdByName(ui->squadComboBox->currentText());
    int teamId = Team::getTeamId(squadId, ui->teamComboBox->currentText());
    QStringList soldiers;
    Soldier::getAllSoldierNames(teamId, soldiers);
    ui->soldierComboBox->clear();
    ui->soldierComboBox->addItems(soldiers);
}

void UpdateSoldierView::loadLineEditTexts()
{
    int squadId = Squad::getIdByName(ui->squadComboBox->currentText());
    int teamId = Team::getTeamId(squadId, ui->teamComboBox->currentText());
    int soldierId = Soldier::getSoldierId(teamId, ui->soldierComboBox->currentText());
    Soldier* soldier = Soldier::getSoldierById(soldierId);
    ui->nameLineEdit->clear();
    ui->rankLineEdit->clear();
    ui->roleLineEdit->clear();
    if (soldier != nullptr)
    {
        ui->nameLineEdit->setText(soldier->getName());
        ui->rankLineEdit->setText(soldier->getRank());
        ui->roleLineEdit->setText(soldier->getRole());
        delete soldier;
    }
}
