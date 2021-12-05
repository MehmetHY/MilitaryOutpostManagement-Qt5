#ifndef DELETERANKVIEW_H
#define DELETERANKVIEW_H

#include <QWidget>

namespace Ui {
class DeleteRankView;
}

class DeleteRankView : public QWidget
{
    Q_OBJECT

public:
    explicit DeleteRankView(class MainWindow *parent = nullptr);
    ~DeleteRankView();

private:
    MainWindow* mainWindow;
    Ui::DeleteRankView *ui;
    void handleBackButtonPressed() const;
    void handleDeleteButtonPressed();
    void initializeComboBox();
};

#endif // DELETERANKVIEW_H
