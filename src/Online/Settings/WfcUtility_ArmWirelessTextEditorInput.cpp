#include <globaldefs.h>
ARM
extern "C" unsigned WfcUtility_IsScreenTransitionBusy(int);
extern "C" void WfcKeyboard_Create();
extern "C" int WfcUtility_PlaySequenceArchiveEntry(unsigned);
extern "C" void WfcKeyboard_SetDeleteEnabled(unsigned char);
extern "C" void WfcKeyboard_SetCharacterEntryEnabled(unsigned char);
// Original data: arm9/ov031 @ 0x2290c94; symbol: data_ov031_02290c94.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char* WfcUtilityReleaseWirelessTextEditor_UnknownRoleZeroInitializedStorage;
extern "C" void RegisterMainLoopCallbackUnlessSentinel();
extern "C" void WfcUtility_SetMainLoopCallback(void(*)());
// Original: arm9/ov031 @ 0x0222CE24; symbol: AdvanceIdleContextsAndSetCallback; size: 0x7c.
// Waits for both context bytes to clear, resolves group14, and chooses transition resets.
extern "C" void WfcUtility_ArmWirelessTextEditorInput(){
 if(WfcUtility_IsScreenTransitionBusy(1))return;
 if(WfcUtility_IsScreenTransitionBusy(0))return;
 WfcKeyboard_Create();WfcUtility_PlaySequenceArchiveEntry(0x14);
 if(!WfcUtilityReleaseWirelessTextEditor_UnknownRoleZeroInitializedStorage[0x29])WfcKeyboard_SetDeleteEnabled(0);
 if(WfcUtilityReleaseWirelessTextEditor_UnknownRoleZeroInitializedStorage[0x29]==0x20)WfcKeyboard_SetCharacterEntryEnabled(0);
 WfcUtility_SetMainLoopCallback(RegisterMainLoopCallbackUnlessSentinel);
}
