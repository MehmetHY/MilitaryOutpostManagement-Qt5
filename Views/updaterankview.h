#ifndef UPDATERANKVIEW_H
#define UPDATERANKVIEW_H

#include <QWidget>

namespace Ui {
class UpdateRankView;
}

class UpdateRankView : public QWidget
{
    Q_OBJECT

public:
    explicit UpdateRankView(class MainWindow *parent = nullptr);
    ~UpdateRankView();

private:
    MainWindow* mainWindow;
    Ui::UpdateRankView *ui;
    void loadComboBox();
    void handleUpdateButtonPressed();
    void handleBackButtonPressed() const;
};

#endif // UPDATERANKVIEW_H
