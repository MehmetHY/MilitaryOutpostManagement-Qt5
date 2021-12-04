#ifndef CREATESOLDIERVIEW_H
#define CREATESOLDIERVIEW_H

#include <QWidget>

namespace Ui {
class CreateSoldierView;
}

class CreateSoldierView : public QWidget
{
    Q_OBJECT

public:
    explicit CreateSoldierView(class MainWindow *parent = nullptr);
    ~CreateSoldierView();

private:
    MainWindow* mainWindow;
    Ui::CreateSoldierView *ui;

    void handleCreateButtonPressed() const;
    void handleBackButtonPressed() const;
};

#endif // CREATESOLDIERVIEW_H
