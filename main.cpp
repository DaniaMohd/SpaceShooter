
#include "pch.h"
#include "GameObject/GameObjectManager.h"
#include "Resource Manager/SpriteManager.h"

using namespace std;

int main()
{

    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Space Shooters");
    SetTargetFPS(60);

    SpriteManager sm;
    sm.Init();

    std::cout << sm;

    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(BLACK);

        // DrawCircle(ball_x,ball_y,ball_radius, WHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}