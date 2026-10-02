#include "ScriptObjectBindings.h"

extern "C" {
void func_02040774(ScriptFieldObject*, fix32_t, fix32_t, fix32_t);

int func_ov001_02164194(ScriptObjectBinding* binding, int kind, int objectID,
                       Object3D* object) {
    if (!object)
        return 0;
    binding->kind = kind;
    switch (kind) {
    case 0:
    case 1:
    case 4:
    case 5:
        binding->objectID = objectID;
        binding->target.object = object;
        return 1;
    default:
        return 0;
    }
}

int func_ov001_021641e0(ScriptObjectBinding* binding, int kind, int objectID,
                       ScriptFieldObject* object) {
    if (!object)
        return 0;
    binding->kind = kind;
    switch (kind) {
    case 2:
    case 6:
        binding->objectID = objectID;
        binding->target.fieldObject = object;
        return 1;
    default:
        return 0;
    }
}

int func_ov001_02164214(ScriptObjectBindings* bindings, int index, int kind,
                       int objectID, Object3D* object) {
    if (index < 0 || index >= 32)
        return 0;
    return func_ov001_02164194(&bindings->entries[index], kind, objectID, object);
}

int func_ov001_02164248(ScriptObjectBindings* bindings, int index, int kind,
                       int objectID, ScriptFieldObject* object) {
    if (index < 0 || index >= 32)
        return 0;
    return func_ov001_021641e0(&bindings->entries[index], kind, objectID, object);
}

int func_ov001_0216427c(ScriptObjectBindings* bindings, int index,
                       fix32_t x, fix32_t y, fix32_t z) {
    if (index < 0 || index >= 32)
        return 0;
    ScriptObjectBinding* binding = &bindings->entries[index];
    switch (binding->kind) {
    case 0:
    case 1:
    case 4:
    case 5: {
        Object3D* object = binding->target.object;
        if (!object)
            return 0;
        object->position_.x = x;
        object->position_.y = y;
        object->position_.z = z;
        return 1;
    }
    case 2:
    case 6:
        if (!binding->target.fieldObject)
            return 0;
        func_02040774(binding->target.fieldObject, x, y, z);
        return 1;
    default:
        return 0;
    }
}
}
