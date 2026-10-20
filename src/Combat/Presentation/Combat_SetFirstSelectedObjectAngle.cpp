#include <globaldefs.h>
ARM
#include <Graphics/Vector.h>
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* _ZN9GameState20GetGameObjectByIndexEi(void*, int);
extern "C" char* _ZN9GameState31GetMaybeWanderingMonsterByIndexEi(void*, int);
extern "C" void Object3D_SetNormalizedAngleAndUpdatePosition(char* object,int value);
extern "C" int Combat_DispatchSelectionProcedure(void* context, void* action, int selector, int* output);
// Original: arm9/ov025 @ 0x021E87F4; symbol: func_ov025_021e87f4; size: 0xA4.
extern "C" int Combat_SetFirstSelectedObjectAngle(char *params, void *action, int unused, void *context) {
    void *state = _ZN9GameState11GetInstanceEv();
    int indices[8];
    if (!Combat_DispatchSelectionProcedure(context, action, *(unsigned char *)(params + 8), indices)) return 1;
    char *object = _ZN9GameState31GetMaybeWanderingMonsterByIndexEi(state, indices[0]);
    if (object) {
        Object3D_SetNormalizedAngleAndUpdatePosition(object, *(int *)(params + 12));
    } else {
        object = _ZN9GameState20GetGameObjectByIndexEi(state, indices[0]);
        if (!object) return 1;
        Vector3i rotation = *(Vector3i *)(object + 0x50);
        rotation.y = *(int *)(params + 12);
        *(Vector3i *)(object + 0x50) = rotation;
    }
    return 1;
}
