#ifndef UPDATESOLDIERVIEW_H
#define UPDATESOLDIERVIEW_H

#include <QWidget>

namespace Ui {
class UpdateSoldierView;
}

class UpdateSoldierView : public QWidget
{
    Q_OBJECT

public:
    explicit UpdateSoldierView(class MainWindow *parent = nullptr);
    ~UpdateSoldierView();

private:
    MainWindow* mainWindow;
    Ui::UpdateSoldierView *ui;
    class Squad* activeSquad;
    class Team* activeTeam;
    class Soldier* activeSoldier;
    bool handlingSquadChanged;
    bool handlingTeamChanged;
    bool handlingSoldierChanged;

    void handleUpdateButtonPressed();
    void handleBackButtonPressed() const;
    void handleSquadChanged();
    void handleTeamChanged();
    void handleSoldierChanged();
    void initializeElements();
    void resetElements();
    void loadSquadsFromDb();
    void loadTeamsFromDb();
    void loadSoldiersFromDb();
    void loadRanksFromDb();
    void unloadSquads();
    void unloadTeams();
    void unloadSoldiers();
    void unloadRanks();
    void resetActiveSquad();
    void setupActiveSquad();
    void resetActiveTeam();
    void setupActiveTeam();
    void resetActiveSoldier();
    void setupActiveSoldier();
    void resetInputFields();
    void setupInputFields();
};

#endif // UPDATESOLDIERVIEW_H
