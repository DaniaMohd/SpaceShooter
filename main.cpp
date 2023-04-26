
#include "pch.h"
#include "GameObject/GameObjectManager.h"

using namespace std;

int main()
{

    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Space Shooters");
    SetTargetFPS(60);

    MyTransform tf;
    tf.position.x = 1.5;
    tf.position.y = 1.4;
    tf.position.z = 1.3;
    tf.position.r = 10;

    GameObject object;
    object.AddComponent<MyTransform>(tf);

    GameObject *clone = object.Clone();

    std::cout << object.GetComponent<MyTransform>().position.x << '\n';
    std::cout << clone->GetComponent<MyTransform>().position.x << '\n';
    std::cout << object.GetComponent<RigidBody>().velocity << '\n';

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