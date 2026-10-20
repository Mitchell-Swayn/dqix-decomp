#include <globaldefs.h>
ARM
extern "C" int WfcUtility_GetBottomButtonSelection(void);
extern "C" void WfcUtility_StopSequenceImmediately(void);
extern "C" void WfcUtility_PlaySequenceArchiveEntry(unsigned);
extern "C" void System_SetSharedContextAndInstallThirdCallback(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
// Original: arm9/ov031 @ 0x02232354; symbol: System_EnterModeSevenAndInstallStandardLayerCallback; size: 0x2C.
// When the shared signed byte is zero, dispatches the state setup, selects mode 7, and installs the callback that configures the standard layers.
extern "C" void System_EnterModeSevenAndInstallStandardLayerCallback(void) {
    if (WfcUtility_GetBottomButtonSelection() != 0)
        return;
    WfcUtility_StopSequenceImmediately();
    WfcUtility_PlaySequenceArchiveEntry(7);
    WfcUtility_SetMainLoopCallback(System_SetSharedContextAndInstallThirdCallback);
}
