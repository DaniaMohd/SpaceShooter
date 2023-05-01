#ifndef MATCHA_H
#define MATCHA_H

#include "pch.h"
#include "Time/time.h"
#include "GameObject/GameObjectManager.h"
#include "Systems/SystemManager.h"
#include "ResourceManager/SpriteManager.h"
#include "Systems/SpriteRenderer.h"
#include "Systems/ScriptManager.h"

class MatchaEngine
{

    int screenWidth = 800;
    int screenHeight = 600;

public:
    Time time;
    GameObjectManager gObjManager;
    SpriteManager spriteManager;
    SpriteRenderer spriteRenderer;
    ScriptSystem scriptManager;

    MatchaEngine();

    void Init();
    void Update();
    void Exit();
};

#endif /* MATCHA_H */
