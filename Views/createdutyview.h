#ifndef CREATEDUTYVIEW_H
#define CREATEDUTYVIEW_H

#include <QWidget>

namespace Ui {
class CreateDutyView;
}

class CreateDutyView : public QWidget
{
    Q_OBJECT

public:
    explicit CreateDutyView(class MainWindow *parent = nullptr);
    ~CreateDutyView();

private:
    MainWindow* mainWindow;
    Ui::CreateDutyView *ui;
    class Squad* activeSquad;
    class Team* activeTeam;
    bool handlingSquadComboBoxChanged;
    bool handlingTeamComboBoxChanged;

    void handleCreateButtonPressed();
    void handleBackButtonPressed() const;
    void handleSquadComboBoxChanged();
    void handleTeamComboBoxChanged();
    void InitializeElements();
    void loadSquadsFromDb();
    void loadTeamsFromDb();
    void unloadTeams();
    void loadSoldiersFromDb();
    void unloadSoldiers();
    void resetActiveSquad();
    void setupActiveSquad();
    void resetActiveTeam();
    void setupActiveTeam();
    void clearInputFields();
};

#endif // CREATEDUTYVIEW_H
