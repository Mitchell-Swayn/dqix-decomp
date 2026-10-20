#include <globaldefs.h>
ARM
extern "C" unsigned char *WfcUtility_GetEditableConnectionProfile(void);
extern "C" void System_CreateCopyAndFinalizeResource(int value);
// Original: arm9/ov031 @ 0x02223A0C; symbol: func_ov031_02223a0c; size: 0x18.
extern "C" void System_AdvanceSharedRegionIndex(void) {
    unsigned char index = WfcUtility_GetEditableConnectionProfile()[0xf4];
    System_CreateCopyAndFinalizeResource(index + 2);
}
