#ifndef DUTY_H
#define DUTY_H

#include <QString>
#include <QDateTime>

class Duty
{
private:
    int id;
    QString name;
    int soldierId;
    QDateTime startDate;
    QDateTime endDate;

public:
    Duty(const int id, const QString &name, const int soldierId, const QDateTime &startDate, const QDateTime &endDate);

    const int getId() const;
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
    static Duty* getDutyByName(const QString& name);
    static void updateDuty(const int id, const QString& name, const int soldierId, const QDateTime& startDate, const QDateTime& endDate);
    static void deleteAllDutiesOfSoldier(const int soldierId);
};

#endif // DUTY_H
