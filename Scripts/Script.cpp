#include "Scripts/Script.h"

void Player::Init(MatchaEngine &engine)
{
    player = &engine.gObjManager.CreateObject();
    player->transform.translation = {0, 0, 0};
    player->sprite.SetActive();
    player->script = std::ref(*this);
}

void Player::operator()(MatchaEngine &engine, GameObject &gObj)
{
    (void)engine;

    if (IsKeyDown(KEY_W))
    {
        gObj.transform.translation.y -= 10;
    }
}

void Player::Exit(MatchaEngine &engine) {}