#ifndef MANAGESQUADSVIEW_H
#define MANAGESQUADSVIEW_H

#include <QWidget>

namespace Ui {
class ManageSquadsView;
}

class ManageSquadsView : public QWidget
{
    Q_OBJECT

public:
    explicit ManageSquadsView(class MainWindow *parent = nullptr);
    ~ManageSquadsView();

private:
    MainWindow* mainWindow;
    Ui::ManageSquadsView *ui;

    void handleCreateButtonPressed() const;
    void handleUpdateButtonPressed() const;
    void handleDeleteButtonPressed() const;
    void handleBackButtonPressed() const;
};

#endif // MANAGESQUADSVIEW_H
