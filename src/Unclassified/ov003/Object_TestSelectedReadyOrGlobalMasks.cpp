#include <globaldefs.h>
ARM
extern "C" int TestSelectedRecordReadyAndByteFlagBitOne(char *p, int ignored);
extern "C" int Object_TestNewlySetHalfwordMask(unsigned short *p, unsigned int mask);
extern "C" unsigned short data_02114e30[];
// Original: arm9/ov003 @ 0x0215DCB8; symbol: func_ov003_0215dcb8; size: 0x48.
extern "C" int Object_TestSelectedReadyOrGlobalMasks(unsigned char *object) {
    int ready = TestSelectedRecordReadyAndByteFlagBitOne((char *)(object + 0x98), 0x14);
    int first = Object_TestNewlySetHalfwordMask(data_02114e30, 1);
    int second = Object_TestNewlySetHalfwordMask(data_02114e30, 0x400);
    return (first | second | ready) != 0;
}
