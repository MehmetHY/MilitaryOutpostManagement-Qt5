#include "managesquadsview.h"
#include "ui_managesquadsview.h"
#include "../mainwindow.h"
#include "createsquadview.h"

ManageSquadsView::ManageSquadsView(MainWindow *parent)
    : QWidget(parent),  mainWindow(parent), ui(new Ui::ManageSquadsView)
{
    ui->setupUi(this);
    connect(ui->createButton, &QPushButton::pressed, this, &ManageSquadsView::handleCreateButtonPressed);
}

ManageSquadsView::~ManageSquadsView()
{
    delete ui;
}

void ManageSquadsView::handleCreateButtonPressed() const
{
    mainWindow->changeRootWidget(new CreateSquadView(mainWindow));
}
