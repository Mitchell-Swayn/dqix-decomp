#include <globaldefs.h>
ARM
extern "C" int Object_TestNewlySetHalfwordMask(unsigned short*, unsigned int);
extern "C" void DispatchStoredHalfwordIndexWithTwoArguments(char*, int, void*);
extern "C" unsigned short data_02114e30;
extern "C" unsigned char data_02114e54;
extern "C" unsigned int data_02108760;
// Original: arm9/ov023 @ 0x021ED014; symbol: func_ov023_021ed014; size: 0x50.
extern "C" int func_ov023_021ed014(void) {
    if (!Object_TestNewlySetHalfwordMask(&data_02114e30, 0xf03) && *((unsigned char*)&data_02114e54 + 0x55) == 0) return 0;
    DispatchStoredHalfwordIndexWithTwoArguments((char*)&data_02108760, 1, 0);
    return 1;
}
