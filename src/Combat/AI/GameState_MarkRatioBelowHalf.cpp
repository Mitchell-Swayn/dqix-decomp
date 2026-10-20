#include <globaldefs.h>
ARM
extern "C" void *Combat_FindIndexedMonsterObject(void *, int);
extern "C" float Combat_GetCurrentHealthFraction(unsigned char *);
extern "C" int _fgeq(float, float);
// Original: arm9/ov024 @ 0x021F3688; symbol: func_ov024_021f3688; size: 0x44.
extern "C" int GameState_MarkRatioBelowHalf(void **owner, short value, void *unused, int *outFlag, short *outValue) {
    void *object = Combat_FindIndexedMonsterObject(*owner, value);
    if (!object) return 0;
    float ratio = Combat_GetCurrentHealthFraction((unsigned char *)object);
    if (_fgeq(ratio, 0.5f)) return 0;
    *outFlag = 1;
    *outValue = value;
    return 1;
}
