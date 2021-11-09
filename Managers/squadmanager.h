#ifndef SQUADMANAGER_H
#define SQUADMANAGER_H

#include <QObject>

class SquadManager : public QObject
{
    Q_OBJECT

private:
    class Platoon* platoon;
    QList<class Squad*>* squads;

    void LoadSquadsFromDB();
public:
    explicit SquadManager(Platoon *parent = nullptr);
    ~SquadManager();

    int GetSquadCount() const;
    QList<Squad*>* GetSquads() const;
};

#endif // SQUADMANAGER_H
