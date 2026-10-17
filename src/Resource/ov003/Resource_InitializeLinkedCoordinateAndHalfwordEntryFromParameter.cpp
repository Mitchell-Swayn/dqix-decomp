#include <globaldefs.h>
ARM
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void *);
extern "C" unsigned int data_ov003_02180cb8[];
extern "C" void Resource_InitializeLinkedCoordinateAndHalfwordEntry(void *, unsigned int, int);

// Original: arm9/ov003 @ 0x0215E5FC; symbol: func_ov003_0215e5fc; size: 0x2C.
extern "C" int Resource_InitializeLinkedCoordinateAndHalfwordEntryFromParameter(const void *parameter) {
    Resource_InitializeLinkedCoordinateAndHalfwordEntry((void *)data_ov003_02180cb8[1], data_ov003_02180cb8[0], (short)_ZNK6Script9Parameter5ToIntEv(parameter));
    return 1;
}
