#ifndef SPRITEMANAGER_H
#define SPRITEMANAGER_H

#include "pch.h"

class SpriteManager
{
    std::unordered_map<const char*, Texture2D> nameToTexture2D;
public:
    void Init()
    {
        std::string path = "./Assets/Images";
        for (const auto &entry : std::filesystem::directory_iterator(path))
        {
            std::string texturePath = entry.path().string();
            Texture2D texture = LoadTexture(texturePath.c_str());
            nameToTexture2D.insert({texturePath.c_str(), texture});
        }
    }

    friend std::ostream& operator<<(std::ostream& os, SpriteManager& sm){

        for(auto const& pair : sm.nameToTexture2D){
            os << pair.first << ", " << '\n';
        }
        return os;
    }
};

#endif /* SPRITEMANAGER_H */
