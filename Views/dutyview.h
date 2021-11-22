#ifndef DUTYVIEW_H
#define DUTYVIEW_H

#include <QWidget>

namespace Ui {
class DutyView;
}

class DutyView : public QWidget
{
    Q_OBJECT

public:
    explicit DutyView(QWidget *parent = nullptr);
    ~DutyView();

private:
    Ui::DutyView *ui;
};

#endif // DUTYVIEW_H
