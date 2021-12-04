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
    void initializeElements();
    void handleUpdateButtonPressed();
    void handleBackButtonPressed() const;
    void loadSquadComboBox();
    void loadTeamComboBox();
    void loadSoldierComboBox();
    void loadLineEditTexts();
};

#endif // UPDATESOLDIERVIEW_H
