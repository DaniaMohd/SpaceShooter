#ifndef SPRITEMANAGER_H
#define SPRITEMANAGER_H

#include "pch.h"

class SpriteManager
{
    std::unordered_map<std::string, Texture2D> nameToTexture2D;

public:
    void Init()
    {
        std::string path = "/Assets";
        for (const auto &entry : fs::directory_iterator(path))
            std::cout << entry.path() << std::endl;
    }
}

#endif /* SPRITEMANAGER_H */
