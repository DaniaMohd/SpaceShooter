#ifndef SYSTEMMANAGER_H
#define SYSTEMMANAGER_H

#include "Time/time.h"
#include "GameObject/GameObject.h"
#include "pch.h"

class System
{
public:
    virtual void Init(std::shared_ptr<GameObject> gObj) {}
    virtual void Update(std::shared_ptr<GameObject> gObj, Time &time) {}
    virtual void Exit(std::shared_ptr<GameObject> gObj) {}
};

class SystemManager
{
    std::vector<std::shared_ptr<System>> listOfSystems;

public:
    template <typename T>
    void RegisterSystem()
    {
        std::shared_ptr<System> system = std::static_pointer_cast<System>(std::make_shared<T>());
        this->listOfSystems.push_back(system);
    }

    void InitAllSystems(std::shared_ptr<GameObject> gObj)
    {
        for (auto system : listOfSystems)
        {
            system->Init(gObj);
        }
    }

    void UpdateAllSystems(std::shared_ptr<GameObject> gObj, Time &time_)
    {
        for (auto system : listOfSystems)
        {
            system->Update(gObj, time_);
        }
    }

    void ExitAllSystems(std::shared_ptr<GameObject> gObj)
    {
        for (auto system : listOfSystems)
        {
            system->Exit(gObj);
        }
    }
};

#endif /* SYSTEMMANAGER_H */
