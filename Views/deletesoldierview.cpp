#include "deletesoldierview.h"
#include "ui_deletesoldierview.h"
#include "../mainwindow.h"
#include "../Models/squad.h"
#include "../Models/team.h"
#include "managesoldiersview.h"
#include "QMessageBox"

DeleteSoldierView::DeleteSoldierView(MainWindow *parent)
    :   QWidget(parent), mainWindow(parent), ui(new Ui::DeleteSoldierView)
{
    ui->setupUi(this);
    initializeComboBoxes();
    connect(ui->squadComboBox, &QComboBox::currentTextChanged, this, &DeleteSoldierView::loadTeamComboBox);
    connect(ui->backButton, &QPushButton::pressed, this, &DeleteSoldierView::handleBackButtonPressed);
    connect(ui->deleteButton, &QPushButton::pressed, this, &DeleteSoldierView::handleDeleteButtonPressed);
}

DeleteSoldierView::~DeleteSoldierView()
{
    delete ui;
}

void DeleteSoldierView::handleBackButtonPressed() const
{
    mainWindow->changeRootWidget(new ManageSoldiersView(mainWindow));
}

void DeleteSoldierView::handleDeleteButtonPressed()
{

}

void DeleteSoldierView::initializeComboBoxes()
{

}

void DeleteSoldierView::loadSquadComboBox()
{

}

void DeleteSoldierView::loadTeamComboBox()
{

}

void DeleteSoldierView::loadSoldierComboBox()
{

}
