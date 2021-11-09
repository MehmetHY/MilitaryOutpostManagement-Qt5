#ifndef PREVIEWHIERARCHYMENU_H
#define PREVIEWHIERARCHYMENU_H

#include <QWidget>

namespace Ui {
class PreviewHierarchyMenu;
}

class PreviewHierarchyMenu : public QWidget
{
    Q_OBJECT

public:
    explicit PreviewHierarchyMenu(class MainWindow* window, QWidget *parent = nullptr);
    ~PreviewHierarchyMenu();

private:
    Ui::PreviewHierarchyMenu *ui;
    MainWindow* mainWindow;

    void HandleBackButtonPressed();
    void SetupHierarchy();
};

#endif // PREVIEWHIERARCHYMENU_H
