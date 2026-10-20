#include <globaldefs.h>
ARM
extern "C" void *Combat_FindIndexedMonsterObject(void *, int, int, int);
extern "C" unsigned int Combat_GetCurrentHealthFraction(void *);
extern "C" int _fgeq(unsigned int, unsigned int);
extern "C" void *memset(void *, int, unsigned int);
// Original: arm9/ov024 @ 0x021F4E84; symbol: func_ov024_021f4e84; size: 0x50.
extern "C" int BattleAI_ClearTargetsWhenActorBelowHalfHp(void **object, int a, int b, void *out, void *buffer) {
    void *record = Combat_FindIndexedMonsterObject(*object, a, b, (int)out);
    if (record == 0) return 0;
    if (_fgeq(Combat_GetCurrentHealthFraction(record), 0x3f000000)) return 0;
    *(int *)out = 0;
    memset(buffer, -1, 0x10);
    return 1;
}
