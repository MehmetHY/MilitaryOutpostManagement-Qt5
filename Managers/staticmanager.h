#ifndef STATICMANAGER_H
#define STATICMANAGER_H


class StaticManager
{
public:
    static void InitializeStaticManagers();
    static void EndStaticManagers();
    StaticManager() = delete;
};

#endif // STATICMANAGER_H
