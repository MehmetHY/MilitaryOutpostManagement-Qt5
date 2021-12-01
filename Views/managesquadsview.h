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
};

#endif // MANAGESQUADSVIEW_H
