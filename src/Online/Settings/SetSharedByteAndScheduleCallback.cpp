#include <globaldefs.h>
ARM
extern "C" void WfcUtility_DisableBottomButtonTouch(void);
extern "C" void System_QueueTimedCallbackForSharedRecord(unsigned int value);
extern "C" void ConfigureDisplayPlanesWhenScreenContextClear(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
// Original: arm9/ov031 @ 0x02229528; symbol: func_ov031_02229528; size: 0x20.
extern "C" void SetSharedByteAndScheduleCallback(void) {
    WfcUtility_DisableBottomButtonTouch();
    System_QueueTimedCallbackForSharedRecord(8);
    WfcUtility_SetMainLoopCallback(ConfigureDisplayPlanesWhenScreenContextClear);
}
