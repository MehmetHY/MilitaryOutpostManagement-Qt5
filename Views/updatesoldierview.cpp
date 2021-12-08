#include "updatesoldierview.h"
#include "ui_updatesoldierview.h"
#include "../mainwindow.h"
#include "../Models/squad.h"
#include "../Models/team.h"
#include "../Models/rank.h"
#include "../Models/soldier.h"
#include "QMessageBox"
#include "managesoldiersview.h"
#include "QDebug"

UpdateSoldierView::UpdateSoldierView(MainWindow *parent)
    :   QWidget(parent), mainWindow(parent), ui(new Ui::UpdateSoldierView), activeSquad(nullptr), activeTeam(nullptr), activeSoldier(nullptr), handlingSquadChanged(false), handlingTeamChanged(false), handlingSoldierChanged(false)
{
    ui->setupUi(this);
    initializeElements();
    connect(ui->squadComboBox, &QComboBox::currentTextChanged, this, &UpdateSoldierView::handleSquadChanged);
    connect(ui->teamComboBox, &QComboBox::currentTextChanged, this, &UpdateSoldierView::handleTeamChanged);
    connect(ui->soldierComboBox, &QComboBox::currentTextChanged, this, &UpdateSoldierView::handleSoldierChanged);
    connect(ui->updateButton, &QPushButton::pressed, this, &UpdateSoldierView::handleUpdateButtonPressed);
    connect(ui->backButton, &QPushButton::pressed, this, &UpdateSoldierView::handleBackButtonPressed);
}

UpdateSoldierView::~UpdateSoldierView()
{
    if (activeSoldier) delete activeSoldier;
    if (activeSquad) delete activeSquad;
    if (activeTeam) delete activeTeam;
    delete ui;
}

void UpdateSoldierView::handleUpdateButtonPressed()
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
    QString name = ui->nameLineEdit->text().trimmed();
    if (name.isEmpty())
    {
        QMessageBox::warning(mainWindow, "Invalid Input", "Name cannot be empty!");
        return;
    }
    if (ui->rankComboBox->count() < 1)
    {
        QMessageBox::warning(mainWindow, "Empty List", "There is no rank!");
        return;
    }
    QString role = ui->roleLineEdit->text().trimmed();
    if (role.isEmpty())
    {
        QMessageBox::warning(mainWindow, "Invalid Input", "Role cannot be empty!");
        return;
    }
    int rankId = Rank::getRankId(ui->rankComboBox->currentText());
    Soldier::updateSoldier(activeSoldier->getId(), name, rankId, role);
    QMessageBox::information(mainWindow, "Success", "Soldier updated!");
    resetElements();
    initializeElements();
}

void UpdateSoldierView::handleBackButtonPressed() const
{
    mainWindow->changeRootWidget(new ManageSoldiersView(mainWindow));
}

void UpdateSoldierView::handleSquadChanged()
{
    if (handlingSquadChanged) return;
    handlingSquadChanged = true;
    resetActiveSquad();
    setupActiveSquad();
    handlingTeamChanged = true;
    unloadTeams();
    handlingTeamChanged = false;
    loadTeamsFromDb();
    handlingSquadChanged = false;
}

void UpdateSoldierView::handleTeamChanged()
{
    if (handlingTeamChanged) return;
    handlingTeamChanged = true;
    qDebug("Team changed");
    resetActiveTeam();
    setupActiveTeam();
    handlingSoldierChanged = true;
    unloadSoldiers();
    handlingSoldierChanged = false;
    loadSoldiersFromDb();
    handlingTeamChanged = false;
}

void UpdateSoldierView::handleSoldierChanged()
{
    if (handlingSoldierChanged) return;
    handlingSoldierChanged = true;
    qDebug("Soldier changed");
    resetActiveSoldier();
    setupActiveSoldier();
    resetInputFields();
    setupInputFields();
    handlingSoldierChanged = false;
}

void UpdateSoldierView::initializeElements()
{
    handlingSoldierChanged = true;
    handlingSquadChanged = true;
    handlingTeamChanged = true;
    loadSquadsFromDb();
    loadTeamsFromDb();
    loadSoldiersFromDb();
    loadRanksFromDb();
    setupInputFields();
    handlingSoldierChanged = false;
    handlingSquadChanged = false;
    handlingTeamChanged = false;
}

void UpdateSoldierView::resetElements()
{
    unloadSquads();
}

void UpdateSoldierView::loadSquadsFromDb()
{
    QStringList squads;
    Squad::getAllSquadNames(squads);
    if (squads.count() < 1)
    {
        qDebug() << "There is no squad!";
        return;
    }
    ui->squadComboBox->addItems(squads);
    setupActiveSquad();
}

void UpdateSoldierView::loadTeamsFromDb()
{
    if (!activeSquad) return;
    QStringList teams;
    Team::getAllTeamNames(activeSquad->getId(), teams);
    if (teams.count() < 1)
    {
        qDebug() << "There is no team!";
        return;
    }
    ui->teamComboBox->addItems(teams);
    setupActiveTeam();
}

void UpdateSoldierView::loadSoldiersFromDb()
{
    if (!activeTeam) return;
    QStringList soldiers;
    Soldier::getAllSoldierNames(activeTeam->getId(), soldiers);
    if (soldiers.count() < 1)
    {
        qDebug() << "There is no soldier!";
        return;
    }
    ui->soldierComboBox->addItems(soldiers);
    setupActiveSoldier();
}

void UpdateSoldierView::loadRanksFromDb()
{
    QStringList ranks;
    Rank::getAllRankNames(ranks);
    ui->rankComboBox->addItems(ranks);
}

void UpdateSoldierView::unloadSquads()
{
    ui->squadComboBox->clear();
    handlingTeamChanged = true;
    unloadTeams();
    handlingTeamChanged = false;
    resetActiveSquad();
}

void UpdateSoldierView::unloadTeams()
{
    ui->teamComboBox->clear();
    handlingSoldierChanged = true;
    unloadSoldiers();
    handlingSoldierChanged = false;
    resetActiveTeam();
}

void UpdateSoldierView::unloadSoldiers()
{
    ui->soldierComboBox->clear();
    resetActiveSoldier();
    resetInputFields();
}

void UpdateSoldierView::unloadRanks()
{
    ui->rankComboBox->clear();
}

void UpdateSoldierView::resetActiveSquad()
{
    if (activeSquad != nullptr)
    {
        delete activeSquad;
        activeSquad = nullptr;
    }
}

void UpdateSoldierView::setupActiveSquad()
{
    activeSquad = Squad::getSquadByName(ui->squadComboBox->currentText());
}

void UpdateSoldierView::resetActiveTeam()
{
    if (activeTeam != nullptr)
    {
        delete activeTeam;
        activeTeam = nullptr;
    }
}

void UpdateSoldierView::setupActiveTeam()
{
    if (!activeSquad) return;
    activeTeam = Team::getTeamByName(activeSquad->getId(), ui->teamComboBox->currentText());
}

void UpdateSoldierView::resetActiveSoldier()
{
    if (activeSoldier != nullptr)
    {
        delete activeSoldier;
        activeSoldier = nullptr;
    }
}

void UpdateSoldierView::setupActiveSoldier()
{
    if (!activeTeam) return;
    activeSoldier = Soldier::getSoldierByName(activeTeam->getId(), ui->soldierComboBox->currentText());
}

void UpdateSoldierView::resetInputFields()
{
    ui->nameLineEdit->clear();
    ui->roleLineEdit->clear();
}

void UpdateSoldierView::setupInputFields()
{
    if (activeSoldier != nullptr)
    {
        ui->nameLineEdit->setText(activeSoldier->getName());
        ui->roleLineEdit->setText(activeSoldier->getRole());
        int index = ui->rankComboBox->findText(Rank::getRankName(activeSoldier->getRankId()));
        ui->rankComboBox->setCurrentIndex(index);
    }
}
