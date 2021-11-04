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
    Squad* teamSquad;

public:     // constructors
    explicit Team(QObject *parent = nullptr);
    explicit Team(unsigned int id, QString name, Squad* squad, QObject *parent = nullptr);

public:     // properties
    unsigned int GetId() const;

    QString GetName() const;

    Squad* GetSquad() const;
    void SetSquad(Squad* squad);

signals:

};

#endif // TEAM_H
