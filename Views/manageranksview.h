#ifndef MANAGERANKSVIEW_H
#define MANAGERANKSVIEW_H

#include <QWidget>

namespace Ui {
class ManageRanksView;
}

class ManageRanksView : public QWidget
{
    Q_OBJECT

public:
    explicit ManageRanksView(class MainWindow *parent = nullptr);
    ~ManageRanksView();

private:
    MainWindow* mainWindow;
    Ui::ManageRanksView *ui;

    void handleCreateButtonPressed() const;
    void handleUpdateButtonPressed() const;
    void handleDeleteButtonPressed() const;
    void handleBackButtonPressed() const;
};

#endif // MANAGERANKSVIEW_H
