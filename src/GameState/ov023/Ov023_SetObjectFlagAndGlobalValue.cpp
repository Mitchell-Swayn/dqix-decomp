#include <globaldefs.h>
ARM
extern "C" unsigned int data_ov023_021ff9e0[];
// Original: arm9/ov023 @ 0x021DBFA8; symbol: func_ov023_021dbfa8; size: 0x28.
extern "C" void Ov023_SetObjectFlagAndGlobalValue(void *object, unsigned int value) {
    if (!value)
        return;
    data_ov023_021ff9e0[1] = value;
    unsigned int flags = *((unsigned char *)object + 0x79b);
    flags &= ~1u;
    flags |= 1u;
    *((unsigned char *)object + 0x79b) = (unsigned char)flags;
}
