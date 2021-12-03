#ifndef CREATETEAMVIEW_H
#define CREATETEAMVIEW_H

#include <QWidget>

namespace Ui {
class CreateTeamView;
}

class CreateTeamView : public QWidget
{
    Q_OBJECT

public:
    explicit CreateTeamView(class MainWindow *parent = nullptr);
    ~CreateTeamView();

private:
    MainWindow* mainWindow;
    Ui::CreateTeamView *ui;

    void handleCreateButtonPressed() const;
    void handleBackButtonPressed() const;
    void initializeComboBox();
};

#endif // CREATETEAMVIEW_H
