#include <globaldefs.h>
ARM
extern "C" unsigned char data_02108760[];
extern "C" void DispatchStoredHalfwordIndexWithTwoArguments(char *, int, void *);
// Original: arm9/ov025 @ 0x021E49E0; symbol: func_ov025_021e49e0; size: 0x20.
extern "C" int DispatchObjectHalfwordIndexWithZeroAndReturnOne(void *object) {
    DispatchStoredHalfwordIndexWithTwoArguments((char *)data_02108760, (int)*(unsigned short *)((char *)object + 8), 0);
    return 1;
}
