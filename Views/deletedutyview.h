#ifndef DELETEDUTYVIEW_H
#define DELETEDUTYVIEW_H

#include <QWidget>

namespace Ui {
class DeleteDutyView;
}

class DeleteDutyView : public QWidget
{
    Q_OBJECT

public:
    explicit DeleteDutyView(class MainWindow *parent = nullptr);
    ~DeleteDutyView();

private:
    MainWindow* mainWindow;
    Ui::DeleteDutyView *ui;
    void handleBackButtonPressed() const;
    void handleDeleteButtonPressed();
};

#endif // DELETEDUTYVIEW_H
