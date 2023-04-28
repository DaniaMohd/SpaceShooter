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
    int screenWidth = 800;
    int screenHeight = 600;

public:
    void Init()
    {
        InitWindow(screenWidth, screenHeight, "Space Shooters");
        SetTargetFPS(60);

        
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
