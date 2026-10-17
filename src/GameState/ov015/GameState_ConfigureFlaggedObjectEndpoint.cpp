#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" void *GameState_FindOffset3B0ObjectWithFlag2(void *);
extern "C" void Object_SetStateTwoAndClearWord218(int);
extern "C" void WriteWordAtOffset218(int, unsigned);
extern "C" void Object_ReadVectorComponentsAtOffset70(int *, int *, int *, int *);
extern "C" void ComputeRotatedEndpointFromAngleHeightAndLength(char *, int, int, int);
// Original: arm9/ov015 @ 0x02192544; symbol: func_ov015_02192544; size: 0x64.
extern "C" void GameState_ConfigureFlaggedObjectEndpoint(void) {
    void *state = _ZN9GameState11GetInstanceEv();
    if (state == 0) return;
    void *object = GameState_FindOffset3B0ObjectWithFlag2(state);
    if (object == 0) return;
    Object_SetStateTwoAndClearWord218((int)object);
    WriteWordAtOffset218((int)object, 2);
    int x;
    int y;
    int z;
    Object_ReadVectorComponentsAtOffset70((int *)object, &x, &y, &z);
    ComputeRotatedEndpointFromAngleHeightAndLength((char *)object, x, 0x13D7, z);
}
