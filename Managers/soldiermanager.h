#ifndef SOLDIERMANAGER_H
#define SOLDIERMANAGER_H

#include <QObject>

class SoldierManager : public QObject
{
    Q_OBJECT

private:
    QList<class Soldier*> soldiers;
public:
    explicit SoldierManager(class Team *parent = nullptr);

signals:

};

#endif // SOLDIERMANAGER_H
