#ifndef SYSTEM_H
#define SYSTEM_H

#include "pch.h"
#include "Core/Matcha.h"

class System
{
public:
    virtual void operator()(MatchaEngine &engine) = 0;
};

#endif /* SYSTEM_H */
