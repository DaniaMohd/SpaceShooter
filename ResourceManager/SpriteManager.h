#ifndef SPRITEMANAGER_H
#define SPRITEMANAGER_H

#include "pch.h"

class SpriteManager
{
    std::unordered_map<std::string, Texture2D> nameToTexture2D;
public:
    void Init()
    {
        std::string path = "./Assets/Images";
        for (const auto &entry : std::filesystem::directory_iterator(path))
        {
            std::string texturePath = entry.path().string();
            Texture2D texture = LoadTexture(texturePath.c_str());

            auto i = texturePath.find('\\');
            std::string assetName = texturePath.substr(i+1);
            nameToTexture2D.insert({assetName, texture});
        }
    }

    void Exit(){
        for(auto& pair : this->nameToTexture2D){
            UnloadTexture(pair.second);
        }
    }

    Texture2D GetSprite(std::string assetName){
        auto iterator = this->nameToTexture2D.find(assetName);

        if(iterator != this->nameToTexture2D.end()){
            return iterator->second;
        }

        return this->nameToTexture2D.find("Alert.png")->second;
    }

    friend std::ostream& operator<<(std::ostream& os, SpriteManager& sm){

        for(auto const& pair : sm.nameToTexture2D){
            os << pair.first << ", " << '\n';
        }
        return os;
    }
};

#endif /* SPRITEMANAGER_H */
