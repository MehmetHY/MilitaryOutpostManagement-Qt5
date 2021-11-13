#ifndef DUTY_H
#define DUTY_H

#include <QString>
#include <QDateTime>

class Duty
{
private:
    QString name;
    class Soldier* soldier;
    QDateTime startDate;
    QDateTime endDate;

public:
    Duty(const QString &name, Soldier *soldier, const QDateTime &startDate, const QDateTime &endDate);

    const QString &getName() const;
    void setName(const QString &newName);
    Soldier *getSoldier() const;
    void setSoldier(Soldier *newSoldier);
    const QDateTime &getStartDate() const;
    void setStartDate(const QDateTime &newStartDate);
    const QDateTime &getEndDate() const;
    void setEndDate(const QDateTime &newEndDate);
};

#endif // DUTY_H
