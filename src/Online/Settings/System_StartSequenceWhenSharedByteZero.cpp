#include <globaldefs.h>
ARM
extern "C" int WfcUtility_GetBottomButtonSelection(void);
extern "C" void WfcUtility_StopSequenceImmediately(void);
extern "C" unsigned int WfcUtility_PlaySequenceArchiveEntry(unsigned int index);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void System_InitializeSharedCallbackSequence(void);
// Original: arm9/ov031 @ 0x0222AC5C; symbol: func_ov031_0222ac5c; size: 0x2C.
extern "C" void System_StartSequenceWhenSharedByteZero(void) {
    if (WfcUtility_GetBottomButtonSelection() != 0)
        return;
    WfcUtility_StopSequenceImmediately();
    WfcUtility_PlaySequenceArchiveEntry(7);
    WfcUtility_SetMainLoopCallback(System_InitializeSharedCallbackSequence);
}
