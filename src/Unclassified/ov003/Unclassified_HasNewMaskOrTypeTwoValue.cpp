#include <globaldefs.h>
ARM

extern "C" int Object_TestNewlySetHalfwordMask(unsigned short *, unsigned int);
extern "C" int func_0205d97c(void *);
extern "C" unsigned short data_02114e30[];

// Original: arm9/ov003 @ 0x02169554; symbol: func_ov003_02169554; size: 0x40.
extern "C" int Unclassified_HasNewMaskOrTypeTwoValue(void *object) {
    int hasMask = Object_TestNewlySetHalfwordMask(data_02114e30, 2);
    return (hasMask | (func_0205d97c((char *)object + 0xE4) == 2)) != 0;
}
