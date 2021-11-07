#ifndef TEAM_H
#define TEAM_H

#include <QObject>

class Squad;

class Team : public QObject
{
    Q_OBJECT

private:    // fields
    unsigned int teamId;
    QString teamName;

    class SoldierManager* soldierManager;

public:     // constructors
    explicit Team(unsigned int id, QString name, class Squad *parent = nullptr);

public:     // properties
    unsigned int GetId() const;
    QString GetName() const;
};

#endif // TEAM_H
