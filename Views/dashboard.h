#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QWidget>

namespace Ui {
class DashBoard;
}

class DashBoard : public QWidget
{
    Q_OBJECT

public:
    explicit DashBoard(class MainWindow *parent = nullptr);
    ~DashBoard();

private:
    Ui::DashBoard *ui;
    MainWindow* mainWindow;

private slots:
    void handleViewDutiesButtonPressed();
    void handleManageDutiesButtonPressed();
    void handleManageRanksButtonPressed();
    void handleManageSoldiersButtonPressed();
    void handleManageTeamsButtonPressed();
    void handleManageSquadsButtonPressed();
};

#endif // DASHBOARD_H
