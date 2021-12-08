#ifndef SOLDIER_H
#define SOLDIER_H

#include <QString>
#include <Qlist>

class Soldier
{
private:
    int id;
    QString name;
    int rankId;
    QString role;
    int teamId;

public:
    Soldier(const int id, const QString &name, const int rankId, const QString &role, const int teamId);

    const int getId() const;
    const QString &getName() const;
    void setName(const QString &newName);
    const int getRankId() const;
    void setRankId(const int newRankId);
    const QString &getRole() const;
    void setRole(const QString &newRole);
    const int getTeamId() const;

    static Soldier* getSoldierByName(const int teamId, const QString& name);
    static Soldier* getSoldierById(const int id);
    static void createSoldier(const QString& name, const int rankId, const QString& role, const int teamId);
    static void updateSoldier(const int id, const QString& name, const int rankId, const QString& role);
    static void getAllSoldierNames(const int teamId, QStringList& outList);
    static void deleteSoldier(const QString& name, const int teamId);
    static int getSoldierId(const int teamId, const QString& name);
    static const QString getSoldierRole(const int id);
    static const int getSoldierRankId(const int id);
};

#endif // SOLDIER_H
