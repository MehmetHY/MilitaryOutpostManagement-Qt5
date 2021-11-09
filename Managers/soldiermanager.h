#ifndef SOLDIERMANAGER_H
#define SOLDIERMANAGER_H

#include <QObject>

class SoldierManager : public QObject
{
    Q_OBJECT

private:
    class Team* team;
    QList<class Soldier*>* soldiers;

    void LoadSoldiersFromDB();
public:
    explicit SoldierManager(Team *parent = nullptr);
    ~SoldierManager();

    QList<Soldier*>* GetSoldiers() const;

};

#endif // SOLDIERMANAGER_H
