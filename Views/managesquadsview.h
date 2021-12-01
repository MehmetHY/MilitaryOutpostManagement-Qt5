#ifndef MANAGESQUADSVIEW_H
#define MANAGESQUADSVIEW_H

#include <QWidget>

namespace Ui {
class ManageSquadsView;
}

class ManageSquadsView : public QWidget
{
    Q_OBJECT

public:
    explicit ManageSquadsView(class MainWindow *parent = nullptr);
    ~ManageSquadsView();

private:
    Ui::ManageSquadsView *ui;
};

#endif // MANAGESQUADSVIEW_H
