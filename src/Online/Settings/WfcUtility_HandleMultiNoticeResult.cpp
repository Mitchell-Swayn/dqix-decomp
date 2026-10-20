#include <globaldefs.h>
ARM
extern "C" void WfcUtility_InitializeConnectionProfilesAndHeaders();
// Original data: arm9/ov031 @ 0x2290c68; symbol: data_ov031_02290c68.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcUtilityHandleMultiNoticeResult_UnknownRoleZeroInitializedStorage;
extern "C" void WfcUtility_StopSequenceImmediately();
extern "C" int WfcUtility_PlaySequenceArchiveEntry(unsigned);
extern "C" void WfcUtility_SetConnectionEventCallback(unsigned);
extern "C" unsigned WfcUtility_ScheduleConnectionActivation();
extern "C" void System_ConfigureModeAndInstallCallback();
extern "C" void WfcUtility_SetMainLoopCallback(void(*)());
// Original: arm9/ov031 @ 0x02229964; symbol: SelectTransitionGroupAndInstallCallback; size: 0x88.
// Selects transition byte/group from mode2/3/other, clears global field and installs next callback.
extern "C" void WfcUtility_HandleMultiNoticeResult(int mode){
 if(mode==2){WfcUtility_InitializeConnectionProfilesAndHeaders();WfcUtilityHandleMultiNoticeResult_UnknownRoleZeroInitializedStorage=1;WfcUtility_StopSequenceImmediately();WfcUtility_PlaySequenceArchiveEntry(16);}
 else if(mode==3){WfcUtilityHandleMultiNoticeResult_UnknownRoleZeroInitializedStorage=2;WfcUtility_StopSequenceImmediately();WfcUtility_PlaySequenceArchiveEntry(18);}
 else {WfcUtilityHandleMultiNoticeResult_UnknownRoleZeroInitializedStorage=0;WfcUtility_StopSequenceImmediately();WfcUtility_PlaySequenceArchiveEntry(18);}
 WfcUtility_SetConnectionEventCallback(0);WfcUtility_ScheduleConnectionActivation();WfcUtility_SetMainLoopCallback(System_ConfigureModeAndInstallCallback);
}
