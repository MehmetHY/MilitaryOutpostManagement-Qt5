#ifndef SOLDIER_H
#define SOLDIER_H

#include <QString>
#include <Qlist>

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

    static void populateTeam(QList<Soldier*> outList, unsigned int id);
    static Soldier* getSoldierById(int id);
    static void createSoldier(const QString& name, const QString& rank, const QString& role, const int teamId);
    static void getAllSoldierNames(const int teamId, QStringList& outList);
    static void deleteSoldier(const QString& name, const int teamId);
    static int getSoldierId(const int teamId, const QString& name);
};

#endif // SOLDIER_H
