#ifndef DELETESOLDIERVIEW_H
#define DELETESOLDIERVIEW_H

#include <QWidget>

namespace Ui {
class DeleteSoldierView;
}

class DeleteSoldierView : public QWidget
{
    Q_OBJECT

public:
    explicit DeleteSoldierView(class MainWindow *parent = nullptr);
    ~DeleteSoldierView();

private:
    MainWindow* mainWindow;
    Ui::DeleteSoldierView *ui;
    void handleBackButtonPressed() const;
    void handleDeleteButtonPressed();
    void initializeComboBoxes();
    void loadSquadComboBox();
    void loadTeamComboBox();
    void loadSoldierComboBox();
};

#endif // DELETESOLDIERVIEW_H
