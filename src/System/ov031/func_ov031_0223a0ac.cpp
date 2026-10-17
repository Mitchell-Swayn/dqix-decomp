#include <globaldefs.h>
ARM
extern "C" void SetSharedObjectWord54UnlessStateNineOrTen(unsigned int);
extern "C" void SetStateWithTransitionCallbacks(int);
extern "C" int WriteSharedFieldC8UnderIRQProtection(unsigned int);
extern "C" int System_HaltIfField2Equals8();
// Original: arm9/ov031 @ 0x0223A0AC; symbol: func_ov031_0223a0ac; size: 0x50.
extern "C" void func_ov031_0223a0ac(void *p) {
    unsigned int value = *(unsigned short *)((char *)p + 2);
    if (value != 0) {
        SetSharedObjectWord54UnlessStateNineOrTen(value);
        SetStateWithTransitionCallbacks(10);
        return;
    }
    value = WriteSharedFieldC8UnderIRQProtection((unsigned int)System_HaltIfField2Equals8);
    if (value != 0) {
        SetSharedObjectWord54UnlessStateNineOrTen(value);
        SetStateWithTransitionCallbacks(10);
    } else {
        SetStateWithTransitionCallbacks(1);
    }
}
