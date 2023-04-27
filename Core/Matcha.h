#ifndef MATCHA_H
#define MATCHA_H

#include "pch.h"
#include "Time/time.h"
#include "GameObject/GameObjectManager.h"
#include "Systems/SystemManager.h"
#include "ResourceManager/SpriteManager.h"

class MatchaEngine
{
    Time time;
    GameObjectManager gObjManager;
    SystemManager sysManager;
    SpriteManager sprManager;

    int screenWidth = 800;
    int screenHeight = 600;

public:
    void Init()
    {
        InitWindow(screenWidth, screenHeight, "Space Shooters");
        SetTargetFPS(60);

        sprManager.Init();

        gObjManager.InitGameObject([&sysManager = this->sysManager](std::shared_ptr<GameObject> obj){
            
        });
    }

    void Update()
    {
        while (WindowShouldClose() == false)
        {
            BeginDrawing();
            ClearBackground(BLACK);

            // DrawCircle(ball_x,ball_y,ball_radius, WHITE);
            EndDrawing();
        }
    }

    void Exit()
    {
        CloseWindow();
    }
};

#endif /* MATCHA_H */
