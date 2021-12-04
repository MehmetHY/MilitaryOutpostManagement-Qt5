#ifndef CREATESQUADVIEW_H
#define CREATESQUADVIEW_H

#include <QWidget>

namespace Ui {
class CreateSquadView;
}

class CreateSquadView : public QWidget
{
    Q_OBJECT

public:
    explicit CreateSquadView(class MainWindow *parent = nullptr);
    ~CreateSquadView();

private:
    MainWindow* mainWindow;
    Ui::CreateSquadView *ui;

    void handleCreateButtonPressed() const;
    void handleBackButtonPressed() const;
};

#endif // CREATESQUADVIEW_H
