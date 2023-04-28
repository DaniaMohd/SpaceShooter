#ifndef SPRITERENDERER_H
#define SPRITERENDERER_H

#include "pch.h"
#include "ResourceManager/SpriteManager.h"

class SpriteRenderer{

    template <typename T>
    void Update(T& gameObj, SpriteManager& spriteManager){
       Texture2D sprite = spriteManager.GetSprite(gameObj.sprite.name);
       
    }
};

#endif /* SPRITERENDERER_H */
