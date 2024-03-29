#include "updatesquadview.h"
#include "ui_updatesquadview.h"
#include "../mainwindow.h"
#include "../Models/squad.h"
#include "managesquadsview.h"
#include "QMessageBox"

UpdateSquadView::UpdateSquadView(MainWindow *parent)
    :   QWidget(parent), mainWindow(parent), ui(new Ui::UpdateSquadView)
{
    ui->setupUi(this);
    connect(ui->updateButton, &QPushButton::pressed, this, &UpdateSquadView::handleUpdateButtonPressed);
    connect(ui->backButton, &QPushButton::pressed, this, &UpdateSquadView::handleBackButtonPressed);
    initializeComboBox();
}

UpdateSquadView::~UpdateSquadView()
{
    delete ui;
}

void UpdateSquadView::initializeComboBox()
{
    QStringList squads;
    Squad::getAllSquadNames(squads);
    ui->comboBox->addItems(squads);
}

void UpdateSquadView::handleUpdateButtonPressed()
{
    if (ui->comboBox->count() < 1)
    {
        QMessageBox::warning(mainWindow, "Empty List", "There is no squad!");
        return;
    }
    QString newName = ui->lineEdit->text().trimmed();
    if (newName.isEmpty())
    {
        QMessageBox::warning(mainWindow, "Invalid Input", "Squad name cannot be empty!");
        return;
    }
    if (Squad::isSquadExist(newName))
    {
        QMessageBox::warning(mainWindow, "Invalid Name", "Squad " + newName + " already exist!");
        return;
    }
    QString oldName = ui->comboBox->currentText();
    Squad::updateSquad(newName, oldName);
    ui->comboBox->clear();
    ui->lineEdit->clear();
    initializeComboBox();
}

void UpdateSquadView::handleBackButtonPressed() const
{
    mainWindow->changeRootWidget(new ManageSquadsView(mainWindow));
}
