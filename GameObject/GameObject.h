#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "pch.h"
#include "GameObjectManager.h"

struct Component
{
    // static inline std::unordered_map<std::string, size_t> componentIndexMap;

    virtual ~Component(){};
    virtual std::shared_ptr<Component> Clone()
    {
        return nullptr;
    };
    virtual void RegisterComponent()
    {
    }
};

using ComponentPtr = std::shared_ptr<Component>;

template <typename T>
struct TComponent : Component
{
    std::shared_ptr<Component> Clone()
    {
        T component = *dynamic_cast<T *>(this);
        return std::dynamic_pointer_cast<Component>(std::make_shared<T>(component));
    }

    // TComponent(){
    //     RegisterComponent();
    // }

    // void RegisterComponent(){
    //     //assert that component hasnt been registered!
    //     if(Component::componentIndexMap.find(typeid(T).name()) == Component::componentIndexMap.end()){
    //         Component::componentIndexMap.insert({typeid(T).name(), Component::componentIndexMap.size()});
    //     }
    // }
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
    std::string name;
    Vector velocity;
};

struct GameObject
{
    std::vector<std::shared_ptr<Component>> mComponents;

    template <typename T>
    void AddComponent(T component)
    {
        std::shared_ptr<T> newComp = std::make_shared<T>(component);
        this->mComponents.push_back(std::static_pointer_cast<Component>(newComp));
    }

    template <typename T>
    bool HasComponent()
    {
        for (auto comp : this->mComponents)
        {
            if (std::dynamic_pointer_cast<T>(comp) != nullptr)
            {
                return true;
            }
        }
        return false;
    }

    template <typename T>
    T &GetComponent()
    {
        for (auto comp : this->mComponents)
        {
            if (std::dynamic_pointer_cast<T>(comp) != nullptr)
            {
                std::shared_ptr<T> tComp = std::dynamic_pointer_cast<T>(comp);
                return *tComp;
            }
        }

        std::cout << "Component " + std::string(typeid(T).name()) + " does not exist!" << std::endl;
        throw(this);
    }

    std::shared_ptr<GameObject> Clone()
    {
        std::shared_ptr<GameObject> clone = std::make_shared<GameObject>();

        for (auto comp : this->mComponents)
        {
            std::shared_ptr<Component> clonedComp = std::static_pointer_cast<Component>(comp.get()->Clone());
            clone->mComponents.push_back(clonedComp);
        }

        return clone;
    }
};

#endif /* GAMEOBJECT_H */
