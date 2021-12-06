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
    :   QWidget(parent), mainWindow(parent), ui(new Ui::UpdateSoldierView), activeSquad(nullptr), activeTeam(nullptr), activeSoldier(nullptr), activeRank(nullptr)
{
    ui->setupUi(this);
    connect(ui->updateButton, &QPushButton::pressed, this, &UpdateSoldierView::handleUpdateButtonPressed);
    connect(ui->backButton, &QPushButton::pressed, this, &UpdateSoldierView::handleBackButtonPressed);
    initializeElements();
}

UpdateSoldierView::~UpdateSoldierView()
{
    if (activeRank) delete activeRank;
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
}

void UpdateSoldierView::handleBackButtonPressed() const
{
    mainWindow->changeRootWidget(new ManageSoldiersView(mainWindow));
}

void UpdateSoldierView::initializeElements()
{
    loadSquad();
    loadTeam();
    loadSoldier();
}

void UpdateSoldierView::loadSquad()
{
    if (activeSquad) delete activeSquad;
    ui->squadComboBox->clear();
    QStringList squads;
    Squad::getAllSquadNames(squads);
    if (squads.count() < 1) qDebug() << "There is no squad!";
    else
    {
        ui->squadComboBox->addItems(squads);
        QString name = ui->squadComboBox->currentText();
        activeSquad = Squad::getSquadByName(name);
    }
    loadTeam();
}

void UpdateSoldierView::loadTeam()
{
    if (activeTeam) delete activeTeam;
    ui->teamComboBox->clear();
    if (!activeSquad) return;
    QStringList teams;
    Team::getAllTeamNames(activeSquad->getId(), teams);
    if (teams.count() < 1) qDebug() << "There is no team!";
    else
    {
        ui->teamComboBox->addItems(teams);
        QString name = ui->teamComboBox->currentText();
        int id = Team::getTeamId(activeSquad->getId(), name);
        activeTeam = new Team(id, name, activeSquad->getId());
    }
    loadSoldier();
}

void UpdateSoldierView::loadSoldier()
{
    if (activeSoldier) delete activeSoldier;
    ui->soldierComboBox->clear();
    if (!activeTeam) return;
    QStringList soldiers;
    Soldier::getAllSoldierNames(activeTeam->getId(), soldiers);
    if (soldiers.count() < 1) qDebug() << "There is no soldier!";
    else
    {
        ui->soldierComboBox->addItems(soldiers);
        QString name = ui->soldierComboBox->currentText();
        int id = Soldier::getSoldierId(activeTeam->getId(), name);
        activeSoldier = Soldier::getSoldierByName(activeTeam->getId(), name);
    }
}

void UpdateSoldierView::loadRank()
{
}

void UpdateSoldierView::setupUpdateFields()
{
}
