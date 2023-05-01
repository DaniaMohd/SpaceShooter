#include "Core/Matcha.h"

MatchaEngine::MatchaEngine()
{
    InitWindow(screenWidth, screenHeight, "Space Shooters");
    SetTargetFPS(60);
    spriteManager.Init();
    scriptManager = ScriptSystem(*this);
}

void MatchaEngine::Init()
{
    InitWindow(screenWidth, screenHeight, "Space Shooters");
    SetTargetFPS(60);
    spriteManager.Init();
    scriptManager = ScriptSystem(*this);
}

void MatchaEngine::Update()
{
    while (WindowShouldClose() == false)
    {
        time.CoreUpdate([this]()
                        { 
                scriptManager(*this);
                spriteRenderer(*this); });
    }
}

void MatchaEngine::Exit()
{
    spriteManager.Exit();
    CloseWindow();
}