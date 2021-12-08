#include "createdutyview.h"
#include "ui_createdutyview.h"
#include "../mainwindow.h"
#include "managedutiesview.h"
#include "QMessageBox"
#include "../Models/squad.h"
#include "../Models/team.h"
#include "../Models/soldier.h"
#include "../Models/duty.h"
#include "QDebug"

CreateDutyView::CreateDutyView(MainWindow *parent) :
    QWidget(parent),
    mainWindow(parent),
    ui(new Ui::CreateDutyView),
    activeSquad(nullptr), activeTeam(nullptr), handlingSquadComboBoxChanged(false), handlingTeamComboBoxChanged(false)
{
    ui->setupUi(this);
    connect(ui->backButton, &QPushButton::pressed, this, &CreateDutyView::handleBackButtonPressed);
    connect(ui->createButton, &QPushButton::pressed, this, &CreateDutyView::handleCreateButtonPressed);
    connect(ui->squadComboBox, &QComboBox::currentTextChanged, this, &CreateDutyView::handleSquadComboBoxChanged);
    connect(ui->teamComboBox, &QComboBox::currentTextChanged, this, &CreateDutyView::handleTeamComboBoxChanged);
    InitializeElements();
}

CreateDutyView::~CreateDutyView()
{
    delete ui;
    if (activeSquad) delete activeSquad;
    if (activeTeam) delete activeTeam;
}

void CreateDutyView::handleCreateButtonPressed()
{
    QString name = ui->nameLineEdit->text().trimmed();
    if (name.isEmpty())
    {
        QMessageBox::warning(mainWindow, "Invalid Input", "Name cannot be empty");
        return;
    }
    if (Duty::isDutyExist(name))
    {
        QMessageBox::warning(mainWindow, "Invalid Input", "Duty '" + name + "' already exists!");
        return;
    }
    if (ui->soldierComboBox->currentText().isEmpty())
    {
        QMessageBox::warning(mainWindow, "Invalid Input", "No soldier selected!");
        return;
    }
    int soldierId = Soldier::getSoldierId(activeTeam->getId(), ui->soldierComboBox->currentText());
    QDateTime startTime = ui->startDateTimeEdit->dateTime();
    QDateTime endTime = ui->endDateTimeEdit->dateTime();
    Duty::createDuty(name, soldierId, startTime, endTime);
    clearInputFields();
    QMessageBox::information(mainWindow, "Success", "Duty created!");
}

void CreateDutyView::handleBackButtonPressed() const
{
    mainWindow->changeRootWidget(new ManageDutiesView(mainWindow));
}

void CreateDutyView::handleSquadComboBoxChanged()
{
    if (handlingSquadComboBoxChanged) return;
    handlingSquadComboBoxChanged = true;
    resetActiveSquad();
    setupActiveSquad();
    handlingTeamComboBoxChanged = true;
    unloadTeams();
    handlingTeamComboBoxChanged = false;
    loadTeamsFromDb();
    handlingSquadComboBoxChanged = false;
}

void CreateDutyView::handleTeamComboBoxChanged()
{
    if (handlingTeamComboBoxChanged) return;
    handlingTeamComboBoxChanged = true;
    resetActiveTeam();
    setupActiveTeam();
    unloadSoldiers();
    loadSoldiersFromDb();
    handlingTeamComboBoxChanged = false;
}

void CreateDutyView::InitializeElements()
{
    loadSquadsFromDb();
    loadTeamsFromDb();
    loadSoldiersFromDb();
}

void CreateDutyView::loadSquadsFromDb()
{
    QStringList squads;
    Squad::getAllSquadNames(squads);
    ui->squadComboBox->addItems(squads);
    setupActiveSquad();
}

void CreateDutyView::loadTeamsFromDb()
{
    if (!activeSquad) return;
    QStringList teams;
    Team::getAllTeamNames(activeSquad->getId(), teams);
    ui->teamComboBox->addItems(teams);
    setupActiveTeam();
}

void CreateDutyView::unloadTeams()
{
    ui->teamComboBox->clear();
    unloadSoldiers();
}

void CreateDutyView::loadSoldiersFromDb()
{
    if (!activeTeam) return;
    QStringList soldiers;
    Soldier::getAllSoldierNames(activeTeam->getId(), soldiers);
    ui->soldierComboBox->addItems(soldiers);
}

void CreateDutyView::unloadSoldiers()
{
    ui->soldierComboBox->clear();
}

void CreateDutyView::resetActiveSquad()
{
    if (activeSquad)
    {
        delete activeSquad;
        activeSquad = nullptr;
    }
}

void CreateDutyView::setupActiveSquad()
{
    activeSquad = Squad::getSquadByName(ui->squadComboBox->currentText());
}

void CreateDutyView::resetActiveTeam()
{
    if (activeTeam)
    {
        delete activeTeam;
        activeTeam = nullptr;
    }
}

void CreateDutyView::setupActiveTeam()
{
    activeTeam = Team::getTeamByName(activeSquad->getId(), ui->teamComboBox->currentText());
}

void CreateDutyView::clearInputFields()
{
    ui->nameLineEdit->clear();
}
