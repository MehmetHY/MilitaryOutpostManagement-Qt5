#ifndef PLATOON_H
#define PLATOON_H

#include <QObject>

class Platoon : public QObject
{
    Q_OBJECT
private:    // fields
    unsigned int platoonId;
    QString platoonName;

    class SquadManager* squadManager;
    class DutyManager* dutyManager;

public:     // constructors
    explicit Platoon(const unsigned int id, const QString name, QObject *parent = nullptr);

public:     // methods
    QString GetName() const;
    void SetName(const QString name);

    SquadManager* GetSquadManager() const;
};

#endif // PLATOON_H
