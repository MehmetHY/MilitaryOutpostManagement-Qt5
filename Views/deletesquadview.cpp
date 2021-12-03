#include "deletesquadview.h"
#include "ui_deletesquadview.h"
#include "../mainwindow.h"
#include "../Models/squad.h"
#include "managesquadsview.h"

DeleteSquadView::DeleteSquadView(MainWindow *parent)
    :   QWidget(parent), mainWindow(parent), ui(new Ui::DeleteSquadView)
{
    ui->setupUi(this);
    initializeComboBox();
    connect(ui->backButton, &QPushButton::pressed, this, &DeleteSquadView::handleBackButtonPressed);
}

DeleteSquadView::~DeleteSquadView()
{
    delete ui;
}

void DeleteSquadView::initializeComboBox()
{
    QStringList squads;
    Squad::getAllSquadNames(squads);
    ui->comboBox->addItems(squads);
}

void DeleteSquadView::handleBackButtonPressed() const
{
    mainWindow->changeRootWidget(new ManageSquadsView(mainWindow));
}
