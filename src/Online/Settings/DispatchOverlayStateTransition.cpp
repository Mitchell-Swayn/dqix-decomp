#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x02231864; symbol: DispatchOverlayStateTransition; size: 0xD8.
extern "C" int System_QuerySharedStateWithSnapshot(int fallback);
extern "C" void WfcUtility_DisableBottomButtonTouch(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void System_ConfigureSharedStateFromValidatedBuffer(void);
extern "C" int WfcUtility_PlaySequenceArchiveEntry(unsigned int index);
extern "C" void WfcUtility_StopSequenceImmediately(void);
extern "C" void WfcUtility_CreateSlidingDialog(unsigned,unsigned,unsigned,unsigned,unsigned);
extern "C" void System_SetSharedByte18AndRegisterConditionalLayerCallback(void);
extern "C" void System_InstallCallbackWhenSharedByte1BZero(void);
extern "C" int WfcUtility_PlaySequenceArchiveEntry(unsigned int);
extern "C" void System_ConfigureSharedStateFromValidatedBuffer(void);
// Original data: arm9/ov031 @ 0x2290cb0; symbol: data_ov031_02290cb0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char DispatchOverlayStateTransition_UnknownRoleZeroInitializedStorage[];
extern "C" void DispatchOverlayStateTransition(int fallback)
{
    int state = System_QuerySharedStateWithSnapshot(fallback);
    switch (state) {
    case 3:
        DispatchOverlayStateTransition_UnknownRoleZeroInitializedStorage[0] = 1;
        WfcUtility_StopSequenceImmediately();
        System_ConfigureSharedStateFromValidatedBuffer();
        WfcUtility_SetMainLoopCallback(System_SetSharedByte18AndRegisterConditionalLayerCallback);
        break;
    case 4:
        DispatchOverlayStateTransition_UnknownRoleZeroInitializedStorage[0] = 0;
        WfcUtility_StopSequenceImmediately();
        WfcUtility_PlaySequenceArchiveEntry(9);
        WfcUtility_CreateSlidingDialog(13, 1, 1, (unsigned)-1, 0);
        WfcUtility_DisableBottomButtonTouch();
        WfcUtility_SetMainLoopCallback(System_InstallCallbackWhenSharedByte1BZero);
        break;
    case 5:
        DispatchOverlayStateTransition_UnknownRoleZeroInitializedStorage[0] = 0;
        WfcUtility_StopSequenceImmediately();
        WfcUtility_PlaySequenceArchiveEntry(18);
        WfcUtility_CreateSlidingDialog(14, 1, 1, (unsigned)-1, 0);
        WfcUtility_DisableBottomButtonTouch();
        WfcUtility_SetMainLoopCallback(System_InstallCallbackWhenSharedByte1BZero);
        break;
    }
}
