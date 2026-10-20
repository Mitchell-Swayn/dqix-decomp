#include <globaldefs.h>
ARM
class GameObject;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" GameObject* _ZN9GameState31GetMaybeWanderingMonsterByIndexEi(void*, int);
extern "C" void GameObject_EnableAnimationFlags(GameObject* object);
extern "C" void GameObject_ClearUnknownAnimationOverrideFlags(unsigned char* p);
extern "C" int Combat_DispatchSelectionProcedure(void* context, void* action, int selector, int* output);
// Original: arm9/ov025 @ 0x021E7520; symbol: func_ov025_021e7520; size: 0x84.
extern "C" int Combat_SetSelectedObjectAnimationFlags(char *params, void *action, int unused, void *context) {
    void *state = _ZN9GameState11GetInstanceEv();
    int indices[8];
    int count = Combat_DispatchSelectionProcedure(context, action, *(unsigned short *)(params + 8), indices);
    for (int i = 0; i < count; ++i) {
        GameObject *object = _ZN9GameState31GetMaybeWanderingMonsterByIndexEi(state, indices[i]);
        if (object) {
            if (*(int *)(params + 12)) GameObject_EnableAnimationFlags(object);
            else GameObject_ClearUnknownAnimationOverrideFlags((unsigned char *)object);
        }
    }
    return 1;
}
