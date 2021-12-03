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
    explicit CreateTeamView(QWidget *parent = nullptr);
    ~CreateTeamView();

private:
    Ui::CreateTeamView *ui;
};

#endif // CREATETEAMVIEW_H
