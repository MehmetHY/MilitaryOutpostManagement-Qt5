#include "staticmanager.h"
#include "DataManager.h"
#include "rankmanager.h"

void StaticManager::InitializeStaticManagers()
{
    DataManager::Initialize();
    RankManager::Initialize();
}

void StaticManager::EndStaticManagers()
{
    RankManager::End();
    DataManager::End();
}
