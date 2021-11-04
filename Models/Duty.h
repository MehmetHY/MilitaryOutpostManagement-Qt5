#ifndef DUTY_H
#define DUTY_H

#include <QObject>

class Duty : public QObject
{
    Q_OBJECT

private:    // fields
    unsigned int dutyId;
    QString dutyName;
    class Soldier* dutyAssignedSoldier;
    class QDateTime* dutyStartDate;
    QDateTime* dutyEndDate;

public:     // constructors
    explicit Duty(QObject *parent = nullptr);
    explicit Duty(unsigned int id, QString name, Soldier* soldier, QDateTime* startDate, QDateTime* endDate, QObject *parent = nullptr);

public:     // properties
    unsigned int GetId() const;

    QString GetName() const;

    Soldier* GetAssignedSoldier() const;
    void SetAssignedSoldier(Soldier* soldier);

    QDateTime* GetStartDate() const;
    void SetStartDate(QDateTime* startDate);

    QDateTime* GetEndDate() const;
    void SetEndDate(QDateTime* endDate);
};

#endif // DUTY_H
