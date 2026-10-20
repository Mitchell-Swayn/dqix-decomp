#include <globaldefs.h>
ARM
extern "C" void WfcUtility_DisableBottomButtonTouch(void);
extern "C" void System_QueueTimedCallbackForSharedRecord(int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void Ov031_ConfigureThirdDisplayContext(void);
// Original: arm9/ov031 @ 0x02229B5C; symbol: func_ov031_02229b5c; size: 0x20.
extern "C" void Overlay_InitializeSharedByteAndCallback(void) {
    WfcUtility_DisableBottomButtonTouch();
    System_QueueTimedCallbackForSharedRecord(8);
    WfcUtility_SetMainLoopCallback(Ov031_ConfigureThirdDisplayContext);
}
