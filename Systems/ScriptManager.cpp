#include "Systems/ScriptManager.h"

ScriptSystem::ScriptSystem(MatchaEngine &engine)
{
    player.Init(engine);
}

void ScriptSystem::operator()(MatchaEngine &engine)
{
    auto &gObjs = engine.gObjManager.GetAllGameObject();

    for (auto &obj : gObjs)
    {
        if (obj.script)
        {
            obj.script(engine, obj);
        }
    }
}