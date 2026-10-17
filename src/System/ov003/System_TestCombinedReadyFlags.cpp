#include <globaldefs.h>
ARM
extern "C" int TestSelectedRecordReadyAndByteFlagBitOne(char *, int);
extern "C" int Object_TestNewlySetHalfwordMask(unsigned short *, unsigned int);
extern "C" unsigned short data_02114e30;
// Original: arm9/ov003 @ 0x0216950C; symbol: func_ov003_0216950c; size: 0x48.
extern "C" bool System_TestCombinedReadyFlags(void *object) {
    int ready = TestSelectedRecordReadyAndByteFlagBitOne((char *)object + 0xE4, 0x14);
    int first = Object_TestNewlySetHalfwordMask(&data_02114e30, 1);
    int second = Object_TestNewlySetHalfwordMask(&data_02114e30, 0x400);
    return (first | second) | ready;
}
