#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290cb8; symbol: data_ov031_02290cb8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char Ov031InitializeMapTransition_UnknownRoleZeroInitializedStorage;
extern "C" void WfcUtility_SetMainLoopCallback(void(*)());
extern "C" void System_SetSharedByteAndInstallMode8Callback();
extern "C" void InitializeCallbackWhenSharedByte1BIsZero();
extern "C" void WfcUtility_StopSequenceImmediately();
extern "C" int WfcUtility_PlaySequenceArchiveEntry(unsigned);
extern "C" void WfcUtility_CreateSlidingDialog(int,int,int,int,int);
extern "C" void WfcUtility_DisableBottomButtonTouch();
// Original: arm9/ov031 @ 0x02231F54; symbol: System_DispatchState1OrFourCallbackTransition; size: 0x84.
extern "C" int System_QuerySharedStateWithSnapshot(int);
extern "C" void WfcStepThreeScreen_DispatchTaskResult(int fallback) {
 switch(System_QuerySharedStateWithSnapshot(fallback)) {
 case 1:Ov031InitializeMapTransition_UnknownRoleZeroInitializedStorage=1;WfcUtility_SetMainLoopCallback(System_SetSharedByteAndInstallMode8Callback);break;
 case 4:Ov031InitializeMapTransition_UnknownRoleZeroInitializedStorage=0;WfcUtility_StopSequenceImmediately();WfcUtility_PlaySequenceArchiveEntry(9);WfcUtility_CreateSlidingDialog(13,1,1,-1,0);WfcUtility_DisableBottomButtonTouch();WfcUtility_SetMainLoopCallback(InitializeCallbackWhenSharedByte1BIsZero);break;
 }
}
