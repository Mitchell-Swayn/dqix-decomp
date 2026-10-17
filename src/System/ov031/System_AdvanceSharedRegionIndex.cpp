#include <globaldefs.h>
ARM
extern "C" unsigned char *GetSharedObjectRegionAtOffset1024(void);
extern "C" void System_CreateCopyAndFinalizeResource(int value);
// Original: arm9/ov031 @ 0x02223A0C; symbol: func_ov031_02223a0c; size: 0x18.
extern "C" void System_AdvanceSharedRegionIndex(void) {
    unsigned char index = GetSharedObjectRegionAtOffset1024()[0xf4];
    System_CreateCopyAndFinalizeResource(index + 2);
}
