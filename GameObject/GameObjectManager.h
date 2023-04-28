#ifndef GAMEOBJECTMANAGER_H
#define GAMEOBJECTMANAGER_H

#include "pch.h"
#include "GameObject.h"

template <typename T>
class GameObjectManager
{
    std::vector<T> allTemplatedGameObjs;

public:
    void Init(){
        
    }

    void Update(){
        for(T& obj : this->allTemplatedGameObjs){
            //Apply your systems here

        }
    }

    void Exit(){

    }
};

#endif /* GAMEOBJECTMANAGER_H */
