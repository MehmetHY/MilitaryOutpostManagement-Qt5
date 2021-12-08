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

    void handleCreateButtonPressed() const;
    void handleBackButtonPressed() const;
};

#endif // CREATEDUTYVIEW_H
