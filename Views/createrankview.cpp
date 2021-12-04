#include "createrankview.h"
#include "ui_createrankview.h"
#include "../mainwindow.h"
#include "manageranksview.h"
#include "QMessageBox"
#include "../Models/rank.h"

CreateRankView::CreateRankView(MainWindow *parent) :
    QWidget(parent),
    mainWindow(parent),
    ui(new Ui::CreateRankView)
{
    ui->setupUi(this);
    connect(ui->backButton, &QPushButton::pressed, this, &CreateRankView::handleBackButtonPressed);
    connect(ui->createButton, &QPushButton::pressed, this, &CreateRankView::handleCreateButtonPressed);
}

CreateRankView::~CreateRankView()
{
    delete ui;
}

void CreateRankView::handleCreateButtonPressed() const
{
    QString name = ui->lineEdit->text().trimmed();
    if (name.isEmpty())
    {
        QMessageBox::warning(mainWindow, "Invalid Input", "Name cannot be empty!");
        return;
    }
    if (Rank::isRankExist(name))
    {
        QMessageBox::warning(mainWindow, "Invalid Input", "Rank " + name + " already exist!");
        return;
    }
    ui->lineEdit->clear();
    Rank::createRank(name);
    QMessageBox::information(mainWindow, "Success", "Rank created!");
}

void CreateRankView::handleBackButtonPressed() const
{
    mainWindow->changeRootWidget(new ManageRanksView(mainWindow));
}
