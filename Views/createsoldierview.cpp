#include "createsoldierview.h"
#include "ui_createsoldierview.h"
#include "../mainwindow.h"
#include "managesoldiersview.h"
#include "../Models/squad.h"
#include "../Models/team.h"
#include "../Models/rank.h"
#include "../Models/soldier.h"
#include "QMessageBox"

CreateSoldierView::CreateSoldierView(MainWindow *parent)
    :   QWidget(parent), mainWindow(parent), ui(new Ui::CreateSoldierView)
{
    ui->setupUi(this);
    initializeElements();
    connect(ui->squadComboBox, &QComboBox::currentTextChanged, this, &CreateSoldierView::loadTeamComboBox);
    connect(ui->backButton, &QPushButton::pressed, this, &CreateSoldierView::handleBackButtonPressed);
    connect(ui->createButton, &QPushButton::pressed, this, &CreateSoldierView::handleCreateButtonPressed);
}

CreateSoldierView::~CreateSoldierView()
{
    delete ui;
}

void CreateSoldierView::handleCreateButtonPressed() const
{
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
    int squadId = Squad::getIdByName(ui->squadComboBox->currentText());
    int teamId = Team::getTeamId(squadId, ui->teamComboBox->currentText());
    int rankId = Rank::getRankId(ui->rankComboBox->currentText());
    Soldier::createSoldier(name, rankId, role, teamId);
    ui->nameLineEdit->clear();
    ui->roleLineEdit->clear();
    QMessageBox::information(mainWindow, "Success", "Soldier created!");
}

void CreateSoldierView::handleBackButtonPressed() const
{
    mainWindow->changeRootWidget(new ManageSoldiersView(mainWindow));
}

void CreateSoldierView::initializeElements()
{
    loadSquadComboBox();
    loadTeamComboBox();
    loadRankComboBox();
}

void CreateSoldierView::loadSquadComboBox()
{
    QStringList squads;
    Squad::getAllSquadNames(squads);
    ui->squadComboBox->addItems(squads);
}

void CreateSoldierView::loadTeamComboBox()
{
    ui->teamComboBox->clear();
    QStringList teams;
    int squadId = Squad::getIdByName(ui->squadComboBox->currentText());
    Team::getAllTeamNames(squadId, teams);
    ui->teamComboBox->addItems(teams);
}

void CreateSoldierView::loadRankComboBox()
{
    QStringList ranks;
    Rank::getAllRankNames(ranks);
    ui->rankComboBox->addItems(ranks);
}
