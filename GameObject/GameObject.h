#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "pch.h"
#include "GameObjectManager.h"

struct Component
{
    virtual ~Component(){};


    virtual Component* Clone(){
        return nullptr;
    };
};

template <typename T>
struct TComponent : Component{
    Component* Clone(){
        T component = *dynamic_cast<T*>(this);
        return new T(component);
    }
};

struct Vector
{
    float x, y, z, r;
};

struct MyTransform : public TComponent<MyTransform>
{
    Vector position;
};

struct RigidBody : public TComponent<RigidBody>
{
    std::string name = "InitRigidBody";
    Vector velocity;
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

    template <typename T>
    bool HasComponent()
    {
        for (Component *comp : this->mComponents)
        {
            if (dynamic_cast<T *>(comp) != nullptr)
            {
                return true;
            }
        }
        return false;
    }

    template <typename T>
    T &GetComponent()
    {
        for (Component *comp : this->mComponents)
        {
            if (dynamic_cast<T *>(comp) != nullptr)
            {
                T *tComp = dynamic_cast<T *>(comp);
                return *tComp;
            }
        }

        std::cout << "Component " + std::string(typeid(T).name()) + " does not exist!" << std::endl;
        throw(this);
    }

    GameObject *Clone()
    {
        GameObject* clone = new GameObject;

        for (Component *comp : this->mComponents)
        {
            Component* clonedComp = comp->Clone();
            clone->mComponents.push_back(clonedComp);
        }

        return clone;
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
