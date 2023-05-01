#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "pch.h"
#include "Components/Component.h"

class MatchaEngine;

struct GameObject
{
    Transform transform;
    RigidBody rigidbody;
    Sprite sprite;

    // Add stuff
    std::function<void(MatchaEngine &, GameObject &)> script;
};



#endif /* GAMEOBJECT_H */
