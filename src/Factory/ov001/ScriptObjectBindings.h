#pragma once

#include "World/Object3D.h"

// Field-object handles belong to the main-module object manager. Its position
// routine dispatches to the handle's placement or Object3D instance.
struct ScriptFieldObject;

struct ScriptObjectBinding {
    int kind;
    int objectID;
    int enabled;
    union {
        Object3D* object;
        ScriptFieldObject* fieldObject;
    } target;
};

// The allocator reserves 0x200 bytes and callers index 32 16-byte records.
struct ScriptObjectBindings {
    ScriptObjectBinding entries[32];
};
