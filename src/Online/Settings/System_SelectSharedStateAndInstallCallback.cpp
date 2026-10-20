#include <globaldefs.h>
ARM
struct Fields { unsigned long long identifier,other; unsigned short c,d; };
extern "C" void WfcUtility_DecodePersistentIdentifierFields(Fields*);
extern "C" int WfcUtility_GetBottomButtonSelection();
extern "C" void WfcUtility_SetBottomButtonSelection(signed char);
extern "C" void WfcUtility_SetMainLoopCallback(void(*)());
extern "C" void WfcUtility_ScheduleOptionsSelectionPalette();
extern "C" void WfcUtility_PlaySequenceArchiveEntry(int);
extern "C" void SetSharedByteAndScheduleCallback();
// Original data: arm9/ov031 @ 0x2290c5c; symbol: data_ov031_02290c5c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcUtilityReadOptionsMenuInput_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x02229484; symbol: func_ov031_02229484; size: 0xA4.
extern "C" void System_SelectSharedStateAndInstallCallback() {
switch(WfcUtility_GetBottomButtonSelection()){
case 0:WfcUtility_PlaySequenceArchiveEntry(7);break;
case 1:{Fields fields;WfcUtility_DecodePersistentIdentifierFields(&fields);
if(WfcUtilityReadOptionsMenuInput_UnknownRoleZeroInitializedStorage[0] && fields.identifier==0){WfcUtility_PlaySequenceArchiveEntry(9);WfcUtility_SetBottomButtonSelection(-1);return;}
WfcUtility_PlaySequenceArchiveEntry(6);WfcUtility_ScheduleOptionsSelectionPalette();WfcUtilityReadOptionsMenuInput_UnknownRoleZeroInitializedStorage[1]=1;break;}
default:return;
}
WfcUtility_SetMainLoopCallback(SetSharedByteAndScheduleCallback);
}
