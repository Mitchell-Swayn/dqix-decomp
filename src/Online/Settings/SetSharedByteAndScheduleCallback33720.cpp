#include <globaldefs.h>
ARM
extern "C" void WfcUtility_DisableBottomButtonTouch(void);
extern "C" void System_QueueTimedCallbackForSharedRecord(unsigned int value);
extern "C" void System_ConfigureSecondaryDisplayMode(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
// Original: arm9/ov031 @ 0x02233700; symbol: func_ov031_02233700; size: 0x20.
extern "C" void SetSharedByteAndScheduleCallback33720(void) {
    WfcUtility_DisableBottomButtonTouch();
    System_QueueTimedCallbackForSharedRecord(8);
    WfcUtility_SetMainLoopCallback(System_ConfigureSecondaryDisplayMode);
}
