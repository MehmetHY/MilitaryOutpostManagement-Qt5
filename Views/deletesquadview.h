#ifndef DELETESQUADVIEW_H
#define DELETESQUADVIEW_H

#include <QWidget>

namespace Ui {
class DeleteSquadView;
}

class DeleteSquadView : public QWidget
{
    Q_OBJECT

public:
    explicit DeleteSquadView(class MainWindow *parent = nullptr);
    ~DeleteSquadView();

private:
    MainWindow* mainWindow;
    Ui::DeleteSquadView *ui;
    void initializeComboBox();
    void handleBackButtonPressed() const;
};

#endif // DELETESQUADVIEW_H
