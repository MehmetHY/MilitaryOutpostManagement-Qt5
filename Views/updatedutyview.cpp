#include "updatedutyview.h"
#include "ui_updatedutyview.h"
#include "../mainwindow.h"
#include "../Models/squad.h"
#include "../Models/team.h"
#include "../Models/duty.h"
#include "../Models/soldier.h"
#include "QMessageBox"
#include "managedutiesview.h"
#include "QDebug"

UpdateDutyView::UpdateDutyView(MainWindow *parent) :
    QWidget(parent),
    mainWindow(parent),
    ui(new Ui::UpdateDutyView),
    activeSquad(nullptr),
    activeTeam(nullptr),
    activeSoldier(nullptr),
    activeDuty(nullptr),
    handlingDutyChanged(false),
    handlingSquadChanged(false),
    handlingTeamChanged(false),
    handlingSoldierChanged(false)
{
    ui->setupUi(this);
    initializeElements();
    connect(ui->updateButton, &QPushButton::pressed, this, &UpdateDutyView::handleUpdateButtonPressed);
    connect(ui->backButton, &QPushButton::pressed, this, &UpdateDutyView::handleBackButtonPressed);
    connect(ui->dutyComboBox, &QComboBox::currentTextChanged, this, &UpdateDutyView::handleDutyComboBoxChanged);
    connect(ui->squadComboBox, &QComboBox::currentTextChanged, this, &UpdateDutyView::handleSquadComboBoxChanged);
    connect(ui->teamComboBox, &QComboBox::currentTextChanged, this, &UpdateDutyView::handleTeamComboBoxChanged);
    connect(ui->soldierComboBox, &QComboBox::currentTextChanged, this, &UpdateDutyView::handleSoldierComboBoxChanged);
}

UpdateDutyView::~UpdateDutyView()
{
    delete ui;
    resetActiveDuty();
    resetActiveSoldier();
    resetActiveSquad();
    resetActiveTeam();
}

void UpdateDutyView::handleUpdateButtonPressed()
{
    if (!activeDuty || ui->dutyComboBox->count() < 1)
    {
        QMessageBox::warning(mainWindow, "Empty List", "There is no duty!");
        return;
    }
    if (!activeSoldier || ui->soldierComboBox->count() < 1)
    {
        QMessageBox::warning(mainWindow, "Empty List", "There is no soldier!");
        return;
    }
    QString name = ui->nameLineEdit->text().trimmed();
    if (name.isEmpty())
    {
        QMessageBox::warning(mainWindow, "Invalid Input", "Name cannot be empty!");
        return;
    }
    if (name != activeDuty->getName())
    {
        if (Duty::isDutyExist(name))
        {
            QMessageBox::warning(mainWindow, "Invalid Input", "Duty '" + name + "' already exists!");
            return;
        }
    }
    int id = activeDuty->getId();
    int soldierId = activeSoldier->getId();
    QDateTime startDate = ui->startDateTimeEdit->dateTime();
    QDateTime endDate = ui->endDateTimeEdit->dateTime();
    Duty::updateDuty(id, name, soldierId, startDate, endDate);
    QMessageBox::information(mainWindow, "Success", "Duty updated!");
    resetElements();
    initializeElements();
}

void UpdateDutyView::handleBackButtonPressed() const
{
    mainWindow->changeRootWidget(new ManageDutiesView(mainWindow));
}

void UpdateDutyView::handleDutyComboBoxChanged()
{
    if (handlingDutyChanged) return;
    handlingDutyChanged = true;
    handlingSquadChanged = true;
    handlingTeamChanged = true;
    handlingSoldierChanged = true;
    resetActiveDuty();
    resetActiveSoldier();
    resetActiveTeam();
    resetActiveSquad();
    setupActiveDutyFromComboBox();
    setupActiveSoldierFromDuty();
    setupActiveTeamFromSoldier();
    setupActiveSquadFromTeam();
    unloadTeams();
    unloadSoldiers();
    switchToActiveSquadInComboBox();
    loadTeamsFromDb();
    switchToActiveTeamInComboBox();
    loadSoldiersFromDb();
    switchToActiveSoldierInComboBox();
    setupInputFields();
    handlingSquadChanged = false;
    handlingTeamChanged = false;
    handlingSoldierChanged = false;
    handlingDutyChanged = false;
}

void UpdateDutyView::handleSquadComboBoxChanged()
{
    if (handlingSquadChanged) return;
    handlingSquadChanged = true;
    resetActiveSquad();
    setupActiveSquadFromComboBox();
    handlingTeamChanged = true;
    unloadTeams();
    handlingTeamChanged = false;
    loadTeamsFromDb();
    handlingSquadChanged = false;
}

void UpdateDutyView::handleTeamComboBoxChanged()
{
    if (handlingTeamChanged) return;
    handlingTeamChanged = true;
    resetActiveTeam();
    setupActiveTeamFromComboBox();
    handlingSoldierChanged = true;
    unloadSoldiers();
    handlingSoldierChanged = false;
    loadSoldiersFromDb();
    handlingTeamChanged = false;
}

void UpdateDutyView::handleSoldierComboBoxChanged()
{
    if (handlingSoldierChanged) return;
    handlingSoldierChanged = true;
    resetActiveSoldier();
    setupActiveSoldierFromComboBox();
    handlingSoldierChanged = false;
}

void UpdateDutyView::initializeElements()
{
    handlingDutyChanged = true;
    handlingSquadChanged = true;
    handlingTeamChanged = true;
    handlingSoldierChanged = true;
    loadDutiesFromDb();
    setupActiveSoldierFromDuty();
    setupActiveTeamFromSoldier();
    setupActiveSquadFromTeam();
    loadSquadsFromDb();
    switchToActiveSquadInComboBox();
    loadTeamsFromDb();
    switchToActiveTeamInComboBox();
    loadSoldiersFromDb();
    switchToActiveSoldierInComboBox();
    setupInputFields();
    handlingSquadChanged = false;
    handlingTeamChanged = false;
    handlingSoldierChanged = false;
    handlingDutyChanged = false;
}

void UpdateDutyView::resetElements()
{
    handlingDutyChanged = true;
    unloadDuties();
    handlingDutyChanged = false;
    resetActiveDuty();
    resetActiveSoldier();
    resetActiveSquad();
    resetActiveTeam();
}

void UpdateDutyView::loadDutiesFromDb()
{
    QStringList duties;
    Duty::getAllDutyNames(duties);
    ui->dutyComboBox->addItems(duties);
    setupActiveDutyFromComboBox();
}

void UpdateDutyView::setupActiveSoldierFromDuty()
{
    if (!activeDuty) return;
    activeSoldier = Soldier::getSoldierById(activeDuty->getSoldierId());
}

void UpdateDutyView::setupActiveTeamFromSoldier()
{
    if (!activeSoldier) return;
    activeTeam = Team::getTeamById(activeSoldier->getTeamId());
}

void UpdateDutyView::setupActiveSquadFromTeam()
{
    if (!activeTeam) return;
    activeSquad = Squad::getSquadById(activeTeam->getSquadId());
}

void UpdateDutyView::loadSquadsFromDb()
{
    QStringList squads;
    Squad::getAllSquadNames(squads);
    ui->squadComboBox->addItems(squads);
}

void UpdateDutyView::loadTeamsFromDb()
{
    if (!activeSquad) return;
    QStringList teams;
    Team::getAllTeamNames(activeSquad->getId(), teams);
    ui->teamComboBox->addItems(teams);
}

void UpdateDutyView::loadSoldiersFromDb()
{
    if (!activeTeam) return;
    QStringList soldiers;
    Soldier::getAllSoldierNames(activeTeam->getId(), soldiers);
    ui->soldierComboBox->addItems(soldiers);
}

void UpdateDutyView::unloadDuties()
{
    ui->dutyComboBox->clear();
    handlingSquadChanged = true;
    unloadSquads();
    handlingSquadChanged = false;
}

void UpdateDutyView::unloadSquads()
{
    ui->squadComboBox->clear();
    handlingSquadChanged = true;
    unloadTeams();
    handlingSquadChanged = false;
}

void UpdateDutyView::unloadTeams()
{
    ui->teamComboBox->clear();
    handlingSoldierChanged = true;
    unloadSoldiers();
    handlingSoldierChanged = false;
}

void UpdateDutyView::unloadSoldiers()
{
    ui->soldierComboBox->clear();
}

void UpdateDutyView::resetActiveSquad()
{
    if (activeSquad)
    {
        delete activeSquad;
        activeSquad = nullptr;
    }
}

void UpdateDutyView::setupActiveSquadFromComboBox()
{
    activeSquad = Squad::getSquadByName(ui->squadComboBox->currentText());
}

void UpdateDutyView::resetActiveTeam()
{
    if (activeTeam)
    {
        delete activeTeam;
        activeTeam = nullptr;
    }
}

void UpdateDutyView::setupActiveTeamFromComboBox()
{
    if (!activeSquad) return;
    activeTeam = Team::getTeamByName(activeSquad->getId(), ui->teamComboBox->currentText());
}

void UpdateDutyView::resetActiveSoldier()
{
    if (activeSoldier)
    {
        delete activeSoldier;
        activeSoldier = nullptr;
    }
}

void UpdateDutyView::setupActiveSoldierFromComboBox()
{
    if (!activeTeam) return;
    activeSoldier = Soldier::getSoldierByName(activeTeam->getId(), ui->soldierComboBox->currentText());
}

void UpdateDutyView::resetActiveDuty()
{
    if (activeDuty)
    {
        delete activeDuty;
        activeDuty = nullptr;
    }
}

void UpdateDutyView::setupActiveDutyFromComboBox()
{
    QString name = ui->dutyComboBox->currentText();
    activeDuty = name.isEmpty() ? nullptr : Duty::getDutyByName(name);
}

void UpdateDutyView::setupInputFields()
{
    if (!activeDuty) return;
    ui->nameLineEdit->setText(activeDuty->getName());
    ui->startDateTimeEdit->setDateTime(activeDuty->getStartDate());
    ui->endDateTimeEdit->setDateTime(activeDuty->getEndDate());
}

void UpdateDutyView::switchToActiveSquadInComboBox()
{
    if (!activeSquad || ui->squadComboBox->count() < 1) return;
    int index = ui->squadComboBox->findText(activeSquad->getName());
    ui->squadComboBox->setCurrentIndex(index);
}

void UpdateDutyView::switchToActiveTeamInComboBox()
{
    if (!activeTeam || ui->teamComboBox->count() < 1) return;
    int index = ui->teamComboBox->findText(activeTeam->getName());
    ui->teamComboBox->setCurrentIndex(index);
}

void UpdateDutyView::switchToActiveSoldierInComboBox()
{
    if (!activeSoldier || ui->soldierComboBox->count() < 1) return;
    int index = ui->soldierComboBox->findText(activeSoldier->getName());
    ui->soldierComboBox->setCurrentIndex(index);
}
