#include <globaldefs.h>
ARM
#include <Graphics/Vector.h>
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* _ZN9GameState19GetCombatantByIndexEi(void*, int);
extern "C" unsigned _ZNK9GameState21GetEffectiveDeltaTimeEv(void*);
extern "C" void Object3D_SetNormalizedAngleAndUpdatePosition(char* object,int value);
// Original: arm9/ov025 @ 0x021EECA4; symbol: func_ov025_021eeca4; size: 0xB4.
extern "C" int Combat_AdvanceInterpolatedObjectAngle(char *self) {
    void *state = _ZN9GameState11GetInstanceEv();
    unsigned delta = _ZNK9GameState21GetEffectiveDeltaTimeEv(state);
    char *object = _ZN9GameState19GetCombatantByIndexEi(state,*(unsigned short *)(self + 8));
    if (*(unsigned short *)(self + 10) <= delta) {
        Object3D_SetNormalizedAngleAndUpdatePosition(object,*(short *)(self + 12));
        return 1;
    }
    int current = *(int *)(object + 0x54);
    float distance = (float)fix32SignedAngleDistance(current,*(short *)(self + 12));
    float step = (float)delta;
    float duration = (float)*(unsigned short *)(self + 10);
    int angle = fix32ReduceAngle0To2Pi(current + (int)(distance * (step / duration)));
    Object3D_SetNormalizedAngleAndUpdatePosition(object,angle);
    *(unsigned short *)(self + 10) -= delta;
    return 0;
}
