#ifndef ENTITY_H
#define ENTITY_H

#include "pch.h"

struct Entity
{
    enum class Flags : Signature
    {
        TRANSFORM = 1U << 0,
        SPRITE    = 1U << 1,
        RIGIDBODY = 1U << 2
    };
};

#endif /* ENTITY_H */
