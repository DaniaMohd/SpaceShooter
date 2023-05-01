#include "Systems/SpriteRenderer.h"

void SpriteRenderer::operator()(MatchaEngine &engine)
{
    BeginDrawing();
    ClearBackground(BLACK);

    auto &gObjs = engine.gObjManager.GetAllGameObject();

    for (auto &obj : gObjs)
    {
        Transform &transform = obj.transform;
        Sprite &sprite = obj.sprite;

        if (sprite.IsActive() == true)
        {
            Texture2D texture = engine.spriteManager.GetSprite(sprite.name);
            DrawTexture(texture, transform.translation.x, transform.translation.y, WHITE);
        }
    }

    EndDrawing();
}