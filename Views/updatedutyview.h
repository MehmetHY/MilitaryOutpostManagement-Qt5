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
    bool handlingSquadChanged;
    bool handlingTeamChanged;

    void handleUpdateButtonPressed();
    void handleBackButtonPressed() const;
    void handleSquadChanged();
    void handleTeamChanged();
    void initializeElements();
    void loadDutiesFromDb();
    void loadSquadsFromDb();
    void loadTeamsFromDb();
    void loadSoldiersFromDb();
    void unloadTeams();
    void unloadSoldiers();
    void resetActiveSquad();
    void setupActiveSquad();
    void resetActiveTeam();
    void setupActiveTeam();
    void resetInputFields();
    void setupInputFields();
};

#endif // UPDATEDUTYVIEW_H
