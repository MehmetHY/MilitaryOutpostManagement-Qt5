#ifndef DUTY_H
#define DUTY_H

#include <QString>
#include <QDateTime>

class Duty
{
private:
    QString name;
    int soldierId;
    QDateTime startDate;
    QDateTime endDate;

public:
    Duty(const QString &name, const int soldierId, const QDateTime &startDate, const QDateTime &endDate);

    const QString &getName() const;
    void setName(const QString &newName);
    const int getSoldierId() const;
    void setSoldierId(const int newSoldierId);
    const QDateTime &getStartDate() const;
    void setStartDate(const QDateTime &newStartDate);
    const QDateTime &getEndDate() const;
    void setEndDate(const QDateTime &newEndDate);

    static void getAllDuties(QList<Duty*>& outList);
    static void getAllDutyNames(QStringList& outList);
    static void createDuty(const QString& name, const int soldierId, const QDateTime& startDate, const QDateTime& endDate);
    static bool isDutyExist(const QString& name);
    static void deleteDuty(const QString& name);
};

#endif // DUTY_H
