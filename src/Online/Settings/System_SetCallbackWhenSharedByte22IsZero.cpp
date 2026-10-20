#include <globaldefs.h>
ARM
extern "C" int WfcUtility_GetBottomButtonSelection(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void WfcUtility_PlaySequenceArchiveEntry(unsigned int value);
extern "C" void Overlay_InitializeSharedByteAndCallback(void);

// Original: arm9/ov031 @ 0x02229B34; symbol: func_ov031_02229b34; size: 0x28.
extern "C" void System_SetCallbackWhenSharedByte22IsZero(void) {
    if (WfcUtility_GetBottomButtonSelection() != 0)
        return;
    WfcUtility_PlaySequenceArchiveEntry(6);
    WfcUtility_SetMainLoopCallback(Overlay_InitializeSharedByteAndCallback);
}
