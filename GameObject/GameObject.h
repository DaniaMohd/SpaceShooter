#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "pch.h"
#include "GameObjectManager.h"

struct Component
{
    static inline uint8_t count = 0;
    Signature signature;
};

struct Vector
{
    float x, y, z, r;
};

struct MyTransform : public Component
{
    Vector position;
};

struct RigidBody : public Component
{
    float velocity;
};

struct GameObject
{
    Signature signature;
    std::vector<Component *> mComponents;

    template <typename T>
    void AddComponent(T component)
    {
        T *newComp = new T(component);
        this->mComponents.push_back(static_cast<Component *>(newComp));
    }

    ~GameObject()
    {
        for (Component *comp : this->mComponents)
        {
            delete comp;
        }

        mComponents.clear();
    }
};

#endif /* GAMEOBJECT_H */
