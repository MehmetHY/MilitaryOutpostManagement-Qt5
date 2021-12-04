#ifndef CREATERANKVIEW_H
#define CREATERANKVIEW_H

#include <QWidget>

namespace Ui {
class CreateRankView;
}

class CreateRankView : public QWidget
{
    Q_OBJECT

public:
    explicit CreateRankView(class MainWindow *parent = nullptr);
    ~CreateRankView();

private:
    MainWindow* mainWindow;
    Ui::CreateRankView *ui;

    void handleCreateButtonPressed() const;
    void handleBackButtonPressed() const;
};

#endif // CREATERANKVIEW_H
