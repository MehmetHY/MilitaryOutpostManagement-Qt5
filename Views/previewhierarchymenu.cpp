#include "previewhierarchymenu.h"
#include "ui_previewhierarchymenu.h"
#include "../mainwindow.h"
#include "../Managers/platoonmanager.h"
#include "../Managers/squadmanager.h"
#include "../Managers/teammanager.h"
#include "../Managers/soldiermanager.h"
#include "../Models/Platoon.h"
#include "../Models/Squad.h"
#include "../Models/Team.h"
#include "../Models/Soldier.h"

PreviewHierarchyMenu::PreviewHierarchyMenu(MainWindow* window, QWidget *parent) :
    QWidget(parent), ui(new Ui::PreviewHierarchyMenu), mainWindow(window)
{
    ui->setupUi(this);
    connect(ui->backButton, &QPushButton::pressed, this, &PreviewHierarchyMenu::HandleBackButtonPressed);
    SetupHierarchy();
}

PreviewHierarchyMenu::~PreviewHierarchyMenu()
{
    delete ui;
}

void PreviewHierarchyMenu::HandleBackButtonPressed()
{
    mainWindow->ChangeMenu(MainWindow::Menu::PreviewMenu);
}

void PreviewHierarchyMenu::SetupHierarchy()
{
    Platoon* platoon = mainWindow->GetPlatoonManager()->GetPlatoon();
    ui->platoonLabel->setText(platoon->GetName());

    foreach (Squad* squad, *platoon->GetSquadManager()->GetSquads())
    {
        QVBoxLayout* squadLayout = new QVBoxLayout();
        QLabel* squadLabel = new QLabel(squad->GetName());
        QVBoxLayout* teamContainer = new QVBoxLayout();
        squadLayout->addWidget(squadLabel);
        squadLayout->addLayout(teamContainer);
        ui->squadContainer->addLayout(squadLayout);

        foreach (Team* team, *squad->GetTeamManager()->GetTeams())
        {
            QVBoxLayout* teamLayout = new QVBoxLayout();
            QLabel* teamLabel = new QLabel(team->GetName());
            QVBoxLayout* soldierConteiner = new QVBoxLayout();
            teamLayout->addWidget(teamLabel);
            teamLayout->addLayout(soldierConteiner);
            teamContainer->addLayout(teamLayout);

            foreach (Soldier* soldier, *team->GetSoldierManager()->GetSoldiers())
            {
                QHBoxLayout* soldierLayout = new QHBoxLayout();
                QLabel* soldierNameLabel = new QLabel(soldier->GetName());
                soldierLayout->addWidget(soldierNameLabel);
                soldierConteiner->addLayout(soldierLayout);
            }
        }
    }

}
