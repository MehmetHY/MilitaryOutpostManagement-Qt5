#include "platoonmanager.h"
#include "DataManager.h"

PlatoonManager::PlatoonManager(DataManager* manager, QObject *parent)
    : QObject(parent), dataManager(manager)
{
    platoon = dataManager->GetPlatoon();
}

Platoon *PlatoonManager::GetPlatoon() const
{
    return platoon;
}
