#ifndef DUTYMANAGER_H
#define DUTYMANAGER_H

#include <QObject>

class DutyManager : public QObject
{
    Q_OBJECT

private:
    QList<class Duty*> duties;
public:
    explicit DutyManager(class Platoon *parent = nullptr);

signals:

};

#endif // DUTYMANAGER_H
