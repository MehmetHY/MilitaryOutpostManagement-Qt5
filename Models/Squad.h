#ifndef SQUAD_H
#define SQUAD_H

#include <QObject>

class Squad : public QObject
{
    Q_OBJECT
private:    // fields
    unsigned int squadId;
    QString squadName;
    QList<class Team*> teams;

public:     // constructors
    explicit Squad(QObject *parent = nullptr);
    explicit Squad(unsigned int id, QString name, QObject *parent = nullptr);

public:     // properties
    unsigned int GetId() const;
    QString GetName() const;

    friend class DataManager;
};

#endif // SQUAD_H
