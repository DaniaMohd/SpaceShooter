#ifndef GAMEOBJECTMANAGER_H
#define GAMEOBJECTMANAGER_H

#include "pch.h"
#include "GameObject.h"

class GameObject{

};

template <typename T>
class GameObjectManager
{
    std::vector<T> allTemplatedGameObjs;

public:
    void Init(){
        
    }

    void Update(MatchaEngine& engine){
        for(T& obj : this->allTemplatedGameObjs){
            //Apply your systems here

        }
    }

    void Exit(){

    }
};


class Functor{
    void operator()(){
        
    }
};



#endif /* GAMEOBJECTMANAGER_H */
