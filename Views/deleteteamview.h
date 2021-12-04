#ifndef DELETETEAMVIEW_H
#define DELETETEAMVIEW_H

#include <QWidget>

namespace Ui {
class DeleteTeamView;
}

class DeleteTeamView : public QWidget
{
    Q_OBJECT

public:
    explicit DeleteTeamView(class MainWindow *parent = nullptr);
    ~DeleteTeamView();

private:
    MainWindow* mainWindow;
    Ui::DeleteTeamView *ui;
    void handleBackButtonPressed() const;
    void handleDeleteButtonPressed();
    void initializeComboBoxes();
    void loadSquadComboBox();
    void loadTeamComboBox();
};

#endif // DELETETEAMVIEW_H
