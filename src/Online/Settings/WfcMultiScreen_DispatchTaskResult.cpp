#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290cac; symbol: data_ov031_02290cac.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcMultiScreenDispatchTaskResult_UnknownRoleZeroInitializedStorage;
extern "C" void WfcUtility_SetMainLoopCallback(void(*)());
extern "C" void System_ConfigureSharedByteAndAlternateCallback();
extern "C" void System_InstallCallback02231518WhenSharedByte1BZero();
extern "C" void WfcUtility_StopSequenceImmediately();
extern "C" int WfcUtility_PlaySequenceArchiveEntry(unsigned);
extern "C" void WfcUtility_CreateSlidingDialog(int,int,int,int,int);
extern "C" void WfcUtility_DisableBottomButtonTouch();
// Original: arm9/ov031 @ 0x02231468; symbol: System_DispatchState2OrFourCallbackTransition; size: 0x84.
extern "C" int System_QuerySharedStateWithSnapshot(int);
extern "C" void WfcMultiScreen_DispatchTaskResult(int fallback) {
 switch(System_QuerySharedStateWithSnapshot(fallback)) {
 case 2:WfcMultiScreenDispatchTaskResult_UnknownRoleZeroInitializedStorage=1;WfcUtility_SetMainLoopCallback(System_ConfigureSharedByteAndAlternateCallback);break;
 case 4:WfcMultiScreenDispatchTaskResult_UnknownRoleZeroInitializedStorage=0;WfcUtility_StopSequenceImmediately();WfcUtility_PlaySequenceArchiveEntry(9);WfcUtility_CreateSlidingDialog(13,1,1,-1,0);WfcUtility_DisableBottomButtonTouch();WfcUtility_SetMainLoopCallback(System_InstallCallback02231518WhenSharedByte1BZero);break;
 }
}
