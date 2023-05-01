#ifndef SCRIPT_H
#define SCRIPT_H

#include "pch.h"
#include "Core/Matcha.h"

struct Script
{
    virtual void Init(MatchaEngine &engine) = 0;
    virtual void operator()(MatchaEngine &engine, GameObject &gObj) = 0;
    virtual void Exit(MatchaEngine &engine) = 0;
};

struct Player : public Script
{
    GameObject *player = nullptr;

    Player(){};

    void Init(MatchaEngine &engine);

    void operator()(MatchaEngine &engine, GameObject &gObj);

    void Exit(MatchaEngine &engine);
};

// struct Bullets : public Script
// {
//     void Init(MatchaEngine &engine) {}
//     void operator()(MatchaEngine &engine) {}
//     void Exit(MatchaEngine &engine) {}
// };

#endif /* SCRIPT_H */
