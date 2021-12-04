#include "deleteteamview.h"
#include "ui_deleteteamview.h"
#include "../mainwindow.h"
#include "../Models/squad.h"
#include "../Models/team.h"
#include "manageteamsview.h"
#include "QMessageBox"

DeleteTeamView::DeleteTeamView(MainWindow *parent)
    :   QWidget(parent), mainWindow(parent), ui(new Ui::DeleteTeamView)
{
    ui->setupUi(this);
    initializeComboBoxes();
    connect(ui->squadComboBox, &QComboBox::currentTextChanged, this, &DeleteTeamView::loadTeamComboBox);
    connect(ui->backButton, &QPushButton::pressed, this, &DeleteTeamView::handleBackButtonPressed);
    connect(ui->deleteButton, &QPushButton::pressed, this, &DeleteTeamView::handleDeleteButtonPressed);
}

DeleteTeamView::~DeleteTeamView()
{
    delete ui;
}

void DeleteTeamView::initializeComboBoxes()
{
    loadSquadComboBox();
    loadTeamComboBox();
}

void DeleteTeamView::loadSquadComboBox()
{
    QStringList squads;
    Squad::getAllSquadNames(squads);
    ui->squadComboBox->clear();
    ui->squadComboBox->addItems(squads);
}

void DeleteTeamView::loadTeamComboBox()
{
    int squadId = Squad::getIdByName(ui->squadComboBox->currentText());
    QStringList teams;
    Team::getAllTeamNames(squadId, teams);
    ui->teamComboBox->clear();
    ui->teamComboBox->addItems(teams);
}

void DeleteTeamView::handleBackButtonPressed() const
{
    mainWindow->changeRootWidget(new ManageTeamsView(mainWindow));
}

void DeleteTeamView::handleDeleteButtonPressed()
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
    QString name = ui->teamComboBox->currentText();
    QMessageBox::StandardButton reply = QMessageBox::question(mainWindow, "Delete", "Are you sure you want to delete squad: " + name);
    if (reply == QMessageBox::Yes)
    {
        int squadId = Squad::getIdByName(ui->squadComboBox->currentText());
        Team::deleteTeam(squadId, name);
        ui->teamComboBox->clear();
        loadTeamComboBox();
    }
}
