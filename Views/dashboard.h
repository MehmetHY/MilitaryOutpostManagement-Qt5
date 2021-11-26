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
    explicit DashBoard(QWidget *parent = nullptr);
    ~DashBoard();

private:
    Ui::DashBoard *ui;

private slots:
    void handleViewDutiesButtonPressed();
    void handleManageDutiesButtonPressed();
    void handleManageSoldiersButtonPressed();
    void handleManageTeamsButtonPressed();
    void handleManageSquadsButtonPressed();
};

#endif // DASHBOARD_H
