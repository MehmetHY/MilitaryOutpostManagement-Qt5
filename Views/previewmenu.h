#ifndef PREVIEWMENU_H
#define PREVIEWMENU_H

#include <QWidget>

namespace Ui {
class PreviewMenu;
}

class PreviewMenu : public QWidget
{
    Q_OBJECT

public:
    explicit PreviewMenu(class MainWindow* window, QWidget *parent = nullptr);
    ~PreviewMenu();

private:
    Ui::PreviewMenu *ui;
    MainWindow* mainWindow;

    void HandleBackButtonPressed();
};

#endif // PREVIEWMENU_H
