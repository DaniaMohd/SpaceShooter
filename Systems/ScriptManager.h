#ifndef SCRIPTMANAGER_H
#define SCRIPTMANAGER_H

#include "pch.h"
#include "Scripts/Script.h"
#include "System.h"
#include "Core/Matcha.h"

class ScriptSystem : public System
{
    // All Scripts
    Player player;

public:
    ScriptSystem()
    {
    }

    ScriptSystem(MatchaEngine &engine);

    void operator()(MatchaEngine &engine);
};

#endif /* SCRIPTMANAGER_H */
