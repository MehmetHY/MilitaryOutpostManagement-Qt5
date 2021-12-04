#ifndef UPDATETEAMVIEW_H
#define UPDATETEAMVIEW_H

#include <QWidget>

namespace Ui {
class UpdateTeamView;
}

class UpdateTeamView : public QWidget
{
    Q_OBJECT

public:
    explicit UpdateTeamView(class MainWindow *parent = nullptr);
    ~UpdateTeamView();

private:
    MainWindow* mainWindow;
    Ui::UpdateTeamView *ui;
    void initializeComboBoxes();
    void handleUpdateButtonPressed();
    void handleBackButtonPressed() const;
};

#endif // UPDATETEAMVIEW_H
