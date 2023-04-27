#ifndef GAMEOBJECTMANAGER_H
#define GAMEOBJECTMANAGER_H

#include "pch.h"
#include "GameObject.h"

class GameObjectManager
{
    std::vector<std::shared_ptr<GameObject>> allGameObjs;

public:
    void AddGameObject(std::shared_ptr<GameObject> gObj)
    {
        this->allGameObjs.push_back(gObj);
    }

    void InitGameObject(std::function<void (std::shared_ptr<GameObject> gObj)> lambda)
    {
        for (auto obj : allGameObjs)
        {
            lambda(obj);
        }
    }

    void UpdateGameObject(std::function<void (std::shared_ptr<GameObject> gObj)> lambda)
    {
        for (auto obj : allGameObjs)
        {
            lambda(obj);
        }
    }

    void ExitGameObject(std::function<void (std::shared_ptr<GameObject> gObj)> lambda)
    {
        for (auto obj : allGameObjs)
        {
            lambda(obj);
        }
    }
};

#endif /* GAMEOBJECTMANAGER_H */
