#include "createsquadview.h"
#include "ui_createsquadview.h"
#include "../mainwindow.h"
#include "managesquadsview.h"
#include "QMessageBox"
#include "../Models/squad.h"

CreateSquadView::CreateSquadView(MainWindow *parent)
    :   QWidget(parent),  mainWindow(parent), ui(new Ui::CreateSquadView)
{
    ui->setupUi(this);
    connect(ui->cancelButton, &QPushButton::pressed, this, &CreateSquadView::handleCancelButtonPressed);
    connect(ui->createButton, &QPushButton::pressed, this, &CreateSquadView::handleCreateButtonPressed);
}

CreateSquadView::~CreateSquadView()
{
    delete ui;
}

void CreateSquadView::handleCreateButtonPressed() const
{
    QString text = ui->lineEdit->text().trimmed();
    if (text.isEmpty())
    {
        QMessageBox::warning(mainWindow, "Invalid Input", "Squad name cannot be empty!");
        return;
    }
    if (Squad::isSquadExist(text))
    {
        QMessageBox::warning(mainWindow, "Invalid Name", "Squad " + text + " already exist!");
        return;
    }
    Squad::createSquad(text);
    QMessageBox::information(mainWindow, "Success", "Squad created!");
    handleCancelButtonPressed();
}

void CreateSquadView::handleCancelButtonPressed() const
{
    mainWindow->changeRootWidget(new ManageSquadsView(mainWindow));
}
