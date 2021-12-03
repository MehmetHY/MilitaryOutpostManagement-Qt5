#ifndef UPDATESQUADVIEW_H
#define UPDATESQUADVIEW_H

#include <QWidget>

namespace Ui {
class UpdateSquadView;
}

class UpdateSquadView : public QWidget
{
    Q_OBJECT

public:
    explicit UpdateSquadView(class MainWindow *parent = nullptr);
    ~UpdateSquadView();

private:
    MainWindow* mainWindow;
    Ui::UpdateSquadView *ui;
    void initializeComboBox();
    void handleUpdateButtonPressed();
    void handleBackButtonPressed() const;
};

#endif // UPDATESQUADVIEW_H
