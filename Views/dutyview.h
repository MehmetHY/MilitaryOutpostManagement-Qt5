#ifndef DUTYVIEW_H
#define DUTYVIEW_H

#include <QWidget>

namespace Ui {
class DutyView;
}

class DutyView : public QWidget
{
    Q_OBJECT

public:
    explicit DutyView(class MainWindow *parent = nullptr);
    ~DutyView();

private:
    Ui::DutyView *ui;
    MainWindow* mainWindow;

    void setupDutyTable();
};

#endif // DUTYVIEW_H
