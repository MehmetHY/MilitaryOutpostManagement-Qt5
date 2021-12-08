#ifndef MANAGEDUTIESVIEW_H
#define MANAGEDUTIESVIEW_H

#include <QWidget>

namespace Ui {
class ManageDutiesView;
}

class ManageDutiesView : public QWidget
{
    Q_OBJECT

public:
    explicit ManageDutiesView(class MainWindow *parent = nullptr);
    ~ManageDutiesView();

private:
    MainWindow* mainWindow;
    Ui::ManageDutiesView *ui;

    void handleCreateButtonPressed() const;
    void handleUpdateButtonPressed() const;
    void handleDeleteButtonPressed() const;
    void handleBackButtonPressed() const;
};

#endif // MANAGEDUTIESVIEW_H
