#ifndef SPRITERENDERER_H
#define SPRITERENDERER_H

#include "pch.h"
#include "ResourceManager/SpriteManager.h"
#include "Core/Matcha.h"
#include "System.h"

class SpriteRenderer : public System
{
public:
    void operator()(MatchaEngine &engine);
};

#endif /* SPRITERENDERER_H */
