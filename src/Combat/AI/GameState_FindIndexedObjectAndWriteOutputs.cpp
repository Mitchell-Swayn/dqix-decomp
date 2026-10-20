#include <globaldefs.h>
ARM
extern "C" void *Combat_FindIndexedMonsterObject(void *, int);
// Original: arm9/ov024 @ 0x021F5428; symbol: func_ov024_021f5428; size: 0x50.
extern "C" int GameState_FindIndexedObjectAndWriteOutputs(void **state, int index, int unused, unsigned int *outFlag, unsigned short *outIndex) {
    void *object = Combat_FindIndexedMonsterObject(*state, index);
    if (object == 0) return 0;
    void *nested = *(void **)((char *)object + 0x138);
    unsigned short value = *(unsigned short *)((char *)nested + 0x30);
    if (value != 0x1C && value != 0x247) return 0;
    *outFlag = 1;
    *outIndex = (unsigned short)index;
    return 1;
}
