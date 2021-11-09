#ifndef RANKMANAGER_H
#define RANKMANAGER_H

#include <QObject>

class RankManager : public QObject
{
    Q_OBJECT
private:
    QMap<int, QString>*
public:

    explicit RankManager(QObject *parent = nullptr);

signals:

};

#endif // RANKMANAGER_H
