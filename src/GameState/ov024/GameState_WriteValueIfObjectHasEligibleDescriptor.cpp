#include <globaldefs.h>
ARM
extern "C" void *FindIndexedGameStateObjectWithFlag400(void *, int);
extern "C" int TestLinkedDescriptorFlag04000000(void *);
extern "C" int func_ov024_021f1440(void *);
// Original: arm9/ov024 @ 0x021F2064; symbol: func_ov024_021f2064; size: 0x54.
extern "C" int GameState_WriteValueIfObjectHasEligibleDescriptor(void **owner, short value, void *unused, int *outFlag, short *outValue) {
    void *object = FindIndexedGameStateObjectWithFlag400(*owner, value);
    if (!object) return 0;
    if (TestLinkedDescriptorFlag04000000(object)) return 0;
    if (!func_ov024_021f1440(object)) return 0;
    *outValue = value;
    *outFlag = 1;
    return 1;
}
