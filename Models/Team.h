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
    QList<class Soldier*> soldiers;

public:     // constructors
    explicit Team(QObject *parent = nullptr);
    explicit Team(unsigned int id, QString name, QObject *parent = nullptr);

public:     // properties
    unsigned int GetId() const;
    QString GetName() const;


    friend class DataManager;
};

#endif // TEAM_H
