#ifndef SQUADMANAGER_H
#define SQUADMANAGER_H

#include <QObject>

class SquadManager : public QObject
{
    Q_OBJECT

private:
    QList<class Squad*> squads;
public:
    explicit SquadManager(class Platoon *parent = nullptr);

signals:

};

#endif // SQUADMANAGER_H
