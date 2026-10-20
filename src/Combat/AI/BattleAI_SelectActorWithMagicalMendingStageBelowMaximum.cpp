#include <globaldefs.h>
ARM
extern "C" void *Combat_FindIndexedMonsterObject(void *, int);
// Original: arm9/ov024 @ 0x021F2D4C; symbol: func_ov024_021f2d4c; size: 0x4C.
extern "C" int BattleAI_SelectActorWithMagicalMendingStageBelowMaximum(void **self, unsigned short value, int unused, int *status, unsigned short *outValue) {
    void *object = Combat_FindIndexedMonsterObject(*self, value);
    if (object == 0) return 0;
    int field = ((int)*(unsigned int *)(*(unsigned int *)((char *)object + 0x138) + 0x58) << 14) >> 29;
    if (field >= 2) return 0;
    *outValue = value;
    *status = 1;
    return 1;
}
