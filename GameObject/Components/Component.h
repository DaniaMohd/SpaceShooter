#ifndef COMPONENT_H
#define COMPONENT_H

struct Component
{
    // static inline std::unordered_map<std::string, size_t> componentIndexMap;

    virtual ~Component(){};
    virtual std::shared_ptr<Component> Clone()
    {
        return nullptr;
    };
};

template <typename T>
struct TComponent : Component
{
    std::shared_ptr<Component> Clone()
    {
        T component = *dynamic_cast<T *>(this);
        return std::dynamic_pointer_cast<Component>(std::make_shared<T>(component));
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
    std::string name;
    Vector velocity;
};

struct Sprite : public TComponent<Sprite>
{
    std::string name;
};


struct SuperGameObject{
    RigidBody rigidbody;
};

class Physics{
    template <typename T = SuperGameObject>
    void Update(T& object){
        object.rigidbody;
    }
};


#endif /* COMPONENT_H */
