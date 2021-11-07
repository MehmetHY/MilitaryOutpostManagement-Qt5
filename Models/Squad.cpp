#include "Squad.h"
#include "Platoon.h"

Squad::Squad(unsigned int id, QString name, Platoon *parent)
 : QObject(parent), squadId(id), squadName(name)
{

}
