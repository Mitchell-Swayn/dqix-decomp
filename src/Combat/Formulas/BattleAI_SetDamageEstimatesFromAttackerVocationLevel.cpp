#include <globaldefs.h>
ARM
extern "C" int GameObject_GetCurrentVocationLevel(void*);
extern "C" int _fflt(int);
extern "C" unsigned int _fmul(unsigned int, unsigned int);
// Original: arm9/ov024 @ 0x021F70BC; symbol: func_ov024_021f70bc; size: 0x44.
extern "C" int BattleAI_SetDamageEstimatesFromAttackerVocationLevel(void* p) {
    int value = (GameObject_GetCurrentVocationLevel(*(void**)p) << 1) + 0x7d;
    *(unsigned int*)((char*)p + 0x1c) = (unsigned int)_fflt(value);
    *(unsigned int*)((char*)p + 0x20) = _fmul(0x3f59999a, (unsigned int)_fflt(value));
    return 1;
}
