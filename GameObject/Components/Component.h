#ifndef COMPONENT_H
#define COMPONENT_H

struct Component
{
protected:
    bool isActive = false;
public:
    virtual ~Component(){};

    virtual std::shared_ptr<Component> Clone()
    {
        return nullptr;
    };

    bool IsActive(){
        return this->isActive;
    }

    void SetActive(){
        this->isActive = true;
    }

    void UnSetActive(){
        this->isActive = false;
    }
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
    Vector velocity;
};

struct Sprite : public Component
{
    enum class Type
    {
        SPRITE,
        SPRITESHEET
    };

    std::string name;
};

#endif /* COMPONENT_H */
