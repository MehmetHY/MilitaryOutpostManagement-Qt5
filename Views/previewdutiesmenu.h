#ifndef PREVIEWDUTIESMENU_H
#define PREVIEWDUTIESMENU_H

#include <QWidget>

namespace Ui {
class PreviewDutiesMenu;
}

class PreviewDutiesMenu : public QWidget
{
    Q_OBJECT

public:
    explicit PreviewDutiesMenu(class MainWindow* window, QWidget *parent = nullptr);
    ~PreviewDutiesMenu();

private:
    Ui::PreviewDutiesMenu *ui;
    MainWindow* mainWindow;

    void HandleBackButtonPressed();
};

#endif // PREVIEWDUTIESMENU_H
