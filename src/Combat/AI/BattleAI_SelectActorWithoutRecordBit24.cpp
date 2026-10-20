#include <globaldefs.h>
ARM
extern "C" void* Combat_FindIndexedMonsterObject(void*, int);
extern "C" int Combat_HasSuperHighTension(void*);
// Original: arm9/ov024 @ 0x021F3524; symbol: func_ov024_021f3524; size: 0x40.
extern "C" int BattleAI_SelectActorWithoutRecordBit24(void** gameState, short index, int unused, int* found, short* value) {
    short requested = index;
    void* object = Combat_FindIndexedMonsterObject(*gameState, requested);
    if (!object) return 0;
    if (Combat_HasSuperHighTension(object)) return 0;
    *found = 1;
    *value = requested;
    return 1;
}
