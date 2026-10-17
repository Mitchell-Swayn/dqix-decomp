#include <globaldefs.h>
extern "C" int Object_TestNewlySetHalfwordMask(unsigned short *, unsigned);
extern "C" int func_0205d97c(void *);
extern "C" unsigned short data_02114e30;
// Original: arm9/ov000 @ 0x0217C5F4; symbol: func_ov000_0217c5f4; size: 0x44.
extern "C" int OV000_HasRelevantFlagOrStatus(void *owner) {
    int globalMask = Object_TestNewlySetHalfwordMask(&data_02114e30, 0x802);
    int statusMatch = func_0205d97c((char *)owner + 0x188) == 2;
    return (globalMask | statusMatch) != 0;
}
