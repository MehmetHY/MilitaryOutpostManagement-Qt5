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
    class Rank* activeRank;

    void initializeElements();
    void handleUpdateButtonPressed();
    void handleBackButtonPressed() const;
    void loadSquad();
    void loadTeam();
    void loadSoldier();
    void loadRank();
    void setupUpdateFields();
};

#endif // UPDATESOLDIERVIEW_H
