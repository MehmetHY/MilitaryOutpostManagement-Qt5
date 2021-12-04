#include "updateteamview.h"
#include "ui_updateteamview.h"
#include "../mainwindow.h"
#include "../Models/squad.h"
#include "QMessageBox"
#include "manageteamsview.h"

UpdateTeamView::UpdateTeamView(MainWindow *parent)
    :   QWidget(parent), mainWindow(parent), ui(new Ui::UpdateTeamView)
{
    ui->setupUi(this);
    connect(ui->updateButton, &QPushButton::pressed, this, &UpdateTeamView::handleUpdateButtonPressed);
    connect(ui->backButton, &QPushButton::pressed, this, &UpdateTeamView::handleBackButtonPressed);
    initializeComboBoxes();
}

UpdateTeamView::~UpdateTeamView()
{
    delete ui;
}

void UpdateTeamView::initializeComboBoxes()
{

}

void UpdateTeamView::handleUpdateButtonPressed()
{

}

void UpdateTeamView::handleBackButtonPressed() const
{

}
