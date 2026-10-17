#include <globaldefs.h>
ARM
extern "C" void SetSharedObjectWord54UnlessStateNineOrTen(unsigned value);
extern "C" void SetStateWithTransitionCallbacks(int value);
// Original: arm9/ov031 @ 0x02239B10; symbol: func_ov031_02239b10; size: 0x24.
extern "C" void System_SetStateFromHalfword2(void *object) {
    unsigned short value = *(unsigned short *)((char *)object + 2);
    if (value)
        SetSharedObjectWord54UnlessStateNineOrTen(value);
    else
        SetStateWithTransitionCallbacks(1);
}
