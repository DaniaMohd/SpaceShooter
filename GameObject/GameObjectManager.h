#ifndef GAMEOBJECTMANAGER_H
#define GAMEOBJECTMANAGER_H

#include "pch.h"
#include "GameObject.h"

class GameObjectManager
{
    std::vector<GameObject> allGameObjects;

public:
    GameObject &CreateObject()
    {
        GameObject obj;
        this->allGameObjects.push_back(obj);
        return allGameObjects.back();
    }

    std::vector<GameObject> &GetAllGameObject()
    {
        return this->allGameObjects;
    }
};

#endif /* GAMEOBJECTMANAGER_H */
