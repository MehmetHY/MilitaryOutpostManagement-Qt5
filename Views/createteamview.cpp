#include "createteamview.h"
#include "ui_createteamview.h"
#include "../mainwindow.h"
#include "manageteamsview.h"
#include "QMessageBox"
#include "../Models/team.h"
#include "../Models/squad.h"

CreateTeamView::CreateTeamView(MainWindow *parent)
    :   QWidget(parent),  mainWindow(parent), ui(new Ui::CreateTeamView)
{
    ui->setupUi(this);
    connect(ui->backButton, &QPushButton::pressed, this, &CreateTeamView::handleBackButtonPressed);
    connect(ui->createButton, &QPushButton::pressed, this, &CreateTeamView::handleCreateButtonPressed);
    initializeComboBox();
}

CreateTeamView::~CreateTeamView()
{
    delete ui;
}

void CreateTeamView::handleCreateButtonPressed() const
{
    if (ui->comboBox->count() < 1)
    {
        QMessageBox::warning(mainWindow, "Empty List", "There is no squad!");
        return;
    }
    QString name = ui->lineEdit->text().trimmed();
    if (name.isEmpty())
    {
        QMessageBox::warning(mainWindow, "Invalid Input", "Team name cannot be empty!");
        return;
    }
    int squadId = Squad::getIdByName(ui->comboBox->currentText());
    if (Team::isTeamExist(name, squadId))
    {
        QMessageBox::warning(mainWindow, "Invalid Name", "Team " + name + " already exist!");
        return;
    }
    Team::createTeam(name, squadId);
    QMessageBox::information(mainWindow, "Success", "Team created!");
    ui->lineEdit->clear();
}

void CreateTeamView::handleBackButtonPressed() const
{
    mainWindow->changeRootWidget(new ManageTeamsView(mainWindow));
}

void CreateTeamView::initializeComboBox()
{
    QStringList squads;
    Squad::getAllSquadNames(squads);
    ui->comboBox->addItems(squads);
}
