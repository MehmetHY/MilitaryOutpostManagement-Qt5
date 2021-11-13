#ifndef SOLDIER_H
#define SOLDIER_H

#include <QString>

class Soldier
{
private:
    QString name;
    QString rank;
    QString role;
public:
    Soldier(const QString &name, const QString &rank, const QString &role);

    const QString &getName() const;
    void setName(const QString &newName);
    const QString &getRank() const;
    void setRank(const QString &newRank);
    const QString &getRole() const;
    void setRole(const QString &newRole);
};

#endif // SOLDIER_H
