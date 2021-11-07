#include "Soldier.h"

Soldier::Soldier(unsigned int id, QString name, unsigned int rankId, unsigned int roleId, QObject *parent) : QObject(parent), soldierId(id), soldierName(name), soldierRankId(rankId), soldierRoleId(roleId)
{

}
