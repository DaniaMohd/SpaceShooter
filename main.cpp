
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

    RigidBody rb;
    rb.name = "FirstGameObject";

    GameObject* object = new GameObject();
    object->AddComponent<MyTransform>(tf);
    object->AddComponent<RigidBody>(rb);

    GameObject *clone = object->Clone();

    std::cout << object->GetComponent<MyTransform>().position.x << '\n';
    std::cout << object->GetComponent<RigidBody>().name << '\n';

    std::cout << "Cloned Game Object Should Match" << '\n';

    std::cout << clone->GetComponent<MyTransform>().position.x << '\n';
    std::cout << clone->GetComponent<RigidBody>().name << '\n';

    object->GetComponent<RigidBody>().name = "Chenged!";

    std::cout << "Original Object chaned: \n";
    
    std::cout << object->GetComponent<MyTransform>().position.x << '\n';
    std::cout << object->GetComponent<RigidBody>().name << '\n';

    std::cout << "Cloned Game Object Should maintain same cloned data even when original Object changes." << '\n';
    std::cout << clone->GetComponent<MyTransform>().position.x << '\n';
    std::cout << clone->GetComponent<RigidBody>().name << '\n';




    



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