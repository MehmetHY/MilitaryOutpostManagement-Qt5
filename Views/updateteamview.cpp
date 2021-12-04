#include "updateteamview.h"
#include "ui_updateteamview.h"
#include "../mainwindow.h"
#include "../Models/squad.h"
#include "../Models/team.h"
#include "QMessageBox"
#include "manageteamsview.h"

UpdateTeamView::UpdateTeamView(MainWindow *parent)
    :   QWidget(parent), mainWindow(parent), ui(new Ui::UpdateTeamView)
{
    ui->setupUi(this);
    connect(ui->squadComboBox, &QComboBox::currentTextChanged, this, &UpdateTeamView::loadTeamComboBox);
    connect(ui->teamComboBox, &QComboBox::currentTextChanged, this, &UpdateTeamView::loadLineEditText);
    connect(ui->updateButton, &QPushButton::pressed, this, &UpdateTeamView::handleUpdateButtonPressed);
    connect(ui->backButton, &QPushButton::pressed, this, &UpdateTeamView::handleBackButtonPressed);
    initializeElements();
}

UpdateTeamView::~UpdateTeamView()
{
    delete ui;
}

void UpdateTeamView::initializeElements()
{
    loadSquadComboBox();
    loadTeamComboBox();
    loadLineEditText();
}

void UpdateTeamView::handleUpdateButtonPressed()
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
    QString name = ui->lineEdit->text().trimmed();
    if (name.isEmpty())
    {
        QMessageBox::warning(mainWindow, "Invalid Input", "Name cannot be empty!");
        return;
    }
    int squadId = Squad::getIdByName(ui->squadComboBox->currentText());
    if (Team::isTeamExist(name, squadId))
    {
        QMessageBox::warning(mainWindow, "Invalid Input", "Team " + name + " already exist!");
        return;
    }
    QString oldName = ui->teamComboBox->currentText();
    Team::updateTeam(squadId, oldName, name);
    loadTeamComboBox();
    ui->lineEdit->clear();
}

void UpdateTeamView::handleBackButtonPressed() const
{
    mainWindow->changeRootWidget(new ManageTeamsView(mainWindow));
}

void UpdateTeamView::loadSquadComboBox()
{
    QStringList squads;
    Squad::getAllSquadNames(squads);
    ui->squadComboBox->addItems(squads);
}

void UpdateTeamView::loadTeamComboBox()
{
    int squadId = Squad::getIdByName(ui->squadComboBox->currentText());
    QStringList teams;
    Team::getAllTeamNames(squadId, teams);
    ui->teamComboBox->clear();
    ui->teamComboBox->addItems(teams);
}

void UpdateTeamView::loadLineEditText()
{
    ui->lineEdit->setText(ui->teamComboBox->currentText());
}
