#ifndef UPDATEDUTYVIEW_H
#define UPDATEDUTYVIEW_H

#include <QWidget>

namespace Ui {
class UpdateDutyView;
}

class UpdateDutyView : public QWidget
{
    Q_OBJECT

public:
    explicit UpdateDutyView(class MainWindow *parent = nullptr);
    ~UpdateDutyView();

private:
    MainWindow* mainWindow;
    Ui::UpdateDutyView *ui;
    class Squad* activeSquad;
    class Team* activeTeam;
    class Soldier* activeSoldier;
    class Duty* activeDuty;
    bool handlingDutyChanged;
    bool handlingSquadChanged;
    bool handlingTeamChanged;
    bool handlingSoldierChanged;

    void handleUpdateButtonPressed();
    void handleBackButtonPressed() const;
    void handleDutyComboBoxChanged();
    void handleSquadComboBoxChanged();
    void handleTeamComboBoxChanged();
    void handleSoldierComboBoxChanged();
    void initializeElements();
    void resetElements();
    void loadDutiesFromDb();
    void setupActiveSoldierFromDuty();
    void setupActiveTeamFromSoldier();
    void setupActiveSquadFromTeam();
    void loadSquadsFromDb();
    void loadTeamsFromDb();
    void loadSoldiersFromDb();
    void unloadDuties();
    void unloadSquads();
    void unloadTeams();
    void unloadSoldiers();
    void resetActiveSquad();
    void setupActiveSquadFromComboBox();
    void resetActiveTeam();
    void setupActiveTeamFromComboBox();
    void resetActiveSoldier();
    void setupActiveSoldierFromComboBox();
    void resetActiveDuty();
    void setupActiveDutyFromComboBox();
    void setupInputFields();
    void switchToActiveSquadInComboBox();
    void switchToActiveTeamInComboBox();
    void switchToActiveSoldierInComboBox();
};

#endif // UPDATEDUTYVIEW_H
