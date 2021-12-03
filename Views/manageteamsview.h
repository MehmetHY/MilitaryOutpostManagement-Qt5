#ifndef MANAGETEAMSVIEW_H
#define MANAGETEAMSVIEW_H

#include <QWidget>

namespace Ui {
class ManageTeamsView;
}

class ManageTeamsView : public QWidget
{
    Q_OBJECT

public:
    explicit ManageTeamsView(class MainWindow *parent = nullptr);
    ~ManageTeamsView();

private:
    MainWindow* mainWindow;
    Ui::ManageTeamsView *ui;

    void handleCreateButtonPressed() const;
    void handleUpdateButtonPressed() const;
    void handleDeleteButtonPressed() const;
    void handleBackButtonPressed() const;
};

#endif // MANAGETEAMSVIEW_H
