#ifndef SQUAD_H
#define SQUAD_H

#include <QObject>

class Squad : public QObject
{
    Q_OBJECT
private:    // fields
    unsigned int squadId;
    QString squadName;

    class TeamManager* teamManager;

public:     // constructors
    explicit Squad(unsigned int id, QString name, class Platoon *parent = nullptr);
    unsigned int GetId() const;
    QString GetName() const;
    TeamManager* GetTeamManager() const;

public:     // properties
};

#endif // SQUAD_H
