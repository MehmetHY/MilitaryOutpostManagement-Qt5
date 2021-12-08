#ifndef SQUAD_H
#define SQUAD_H

#include <QString>
#include <QList>

class Squad
{
private:
    int id;
    QString name;

public:
    Squad(const int id, const QString &name);

    const int getId() const;
    const QString &getName() const;
    void setName(const QString &newName);

    static void createSquad(const QString& name);
    static bool isSquadExist(const QString& name);
    static void getAllSquadNames(QStringList& outList);
    static void deleteSquad(const QString& name);
    static void updateSquad(const QString& newName, const QString &oldName);
    static int getIdByName(const QString& name);
    static Squad* getSquadByName(const QString& name);
    static Squad* getSquadById(const int id);
};

#endif // SQUAD_H
