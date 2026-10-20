#include <globaldefs.h>
ARM
extern "C" int WfcUtility_GetBottomButtonSelection(void);
extern "C" void WfcUtility_StopSequenceImmediately(void);
extern "C" void WfcUtility_PlaySequenceArchiveEntry(unsigned);
extern "C" void System_SetSharedByte18AndRegisterConditionalLayerCallback(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
// Original: arm9/ov031 @ 0x022316F8; symbol: System_EnterModeSevenAndInstallConditionalLayerCallback; size: 0x2C.
// When the shared signed byte is zero, dispatches the state setup, selects mode 7, and installs the callback that conditionally configures a layer.
extern "C" void System_EnterModeSevenAndInstallConditionalLayerCallback(void) {
    if (WfcUtility_GetBottomButtonSelection() != 0)
        return;
    WfcUtility_StopSequenceImmediately();
    WfcUtility_PlaySequenceArchiveEntry(7);
    WfcUtility_SetMainLoopCallback(System_SetSharedByte18AndRegisterConditionalLayerCallback);
}
