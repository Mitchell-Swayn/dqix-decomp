#include <globaldefs.h>
ARM
extern "C" unsigned char *WfcUtility_GetEditableConnectionProfile(void);
extern "C" int System_CreateCopyAndFinalizeResource(int);
// Original: arm9/ov031 @ 0x022239F4; symbol: func_ov031_022239f4; size: 0x18.
extern "C" int System_ConvertSharedRegionByteToIndexPlusFive(void) {
    unsigned char value = WfcUtility_GetEditableConnectionProfile()[0xf4];
    return System_CreateCopyAndFinalizeResource(value + 5);
}
