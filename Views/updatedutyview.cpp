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
    handlingSquadChanged(false),
    handlingTeamChanged(false)
{
    ui->setupUi(this);
    connect(ui->updateButton, &QPushButton::pressed, this, &UpdateDutyView::handleUpdateButtonPressed);
    connect(ui->backButton, &QPushButton::pressed, this, &UpdateDutyView::handleBackButtonPressed);
    initializeElements();
}

UpdateDutyView::~UpdateDutyView()
{
    delete ui;
}

void UpdateDutyView::handleUpdateButtonPressed()
{

}

void UpdateDutyView::handleBackButtonPressed() const
{
    mainWindow->changeRootWidget(new ManageDutiesView(mainWindow));
}

void UpdateDutyView::handleSquadChanged()
{

}

void UpdateDutyView::handleTeamChanged()
{

}

void UpdateDutyView::initializeElements()
{
    loadDutiesFromDb();
}

void UpdateDutyView::loadDutiesFromDb()
{
    QStringList duties;
    Duty::getAllDutyNames(duties);
    ui->dutyComboBox->addItems(duties);
    setupActiveDuty();
}

void UpdateDutyView::loadSquadsFromDb()
{

}

void UpdateDutyView::loadTeamsFromDb()
{

}

void UpdateDutyView::loadSoldiersFromDb()
{

}

void UpdateDutyView::unloadTeams()
{

}

void UpdateDutyView::unloadSoldiers()
{

}

void UpdateDutyView::resetActiveSquad()
{

}

void UpdateDutyView::setupActiveSquad()
{

}

void UpdateDutyView::resetActiveTeam()
{

}

void UpdateDutyView::setupActiveTeam()
{

}

void UpdateDutyView::resetActiveDuty()
{

}

void UpdateDutyView::setupActiveDuty()
{
    QString name = ui->dutyComboBox->currentText();
    activeDuty = name.isEmpty() ? nullptr : Duty::getDutyByName(name);
}

void UpdateDutyView::resetInputFields()
{

}

void UpdateDutyView::setupInputFields()
{

}
