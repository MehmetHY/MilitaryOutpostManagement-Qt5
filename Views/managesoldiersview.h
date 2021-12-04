#ifndef MANAGESOLDIERSVIEW_H
#define MANAGESOLDIERSVIEW_H

#include <QWidget>

namespace Ui {
class ManageSoldiersView;
}

class ManageSoldiersView : public QWidget
{
    Q_OBJECT

public:
    explicit ManageSoldiersView(class MainWindow *parent = nullptr);
    ~ManageSoldiersView();

private:
    MainWindow* mainWindow;
    Ui::ManageSoldiersView *ui;

    void handleCreateButtonPressed() const;
    void handleUpdateButtonPressed() const;
    void handleDeleteButtonPressed() const;
    void handleBackButtonPressed() const;
};

#endif // MANAGESOLDIERSVIEW_H
