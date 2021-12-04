#include "updatesoldierview.h"
#include "ui_updatesoldierview.h"
#include "../mainwindow.h"
#include "../Models/squad.h"
#include "../Models/team.h"
#include "QMessageBox"
#include "managesoldiersview.h"

UpdateSoldierView::UpdateSoldierView(MainWindow *parent)
    :   QWidget(parent), mainWindow(parent), ui(new Ui::UpdateSoldierView)
{
    ui->setupUi(this);
    connect(ui->squadComboBox, &QComboBox::currentTextChanged, this, &UpdateSoldierView::loadTeamComboBox);
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

}

void UpdateSoldierView::loadTeamComboBox()
{

}

void UpdateSoldierView::loadSoldierComboBox()
{

}

void UpdateSoldierView::loadLineEditTexts()
{

}
