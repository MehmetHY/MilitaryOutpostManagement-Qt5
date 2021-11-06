#ifndef SOLDIER_H
#define SOLDIER_H

#include <QObject>

class Soldier : public QObject
{
    Q_OBJECT

private:    // fields
    unsigned int soldierId;
    QString soldierName;
    unsigned int soldierRankId;
    unsigned int soldierRoleId;


public:     // constructors
    explicit Soldier(QObject *parent = nullptr);
    explicit Soldier(unsigned int id, QString name, unsigned int rankId, unsigned int roleId, QObject *parent = nullptr);

public:     // properties
    int GetId() const;

    QString GetName() const;
    friend class DataManager;
};

#endif // SOLDIER_H
