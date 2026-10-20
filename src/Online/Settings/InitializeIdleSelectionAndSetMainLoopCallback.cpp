#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290c98; symbol: data_ov031_02290c98.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned WfcUtility_IsScreenTransitionBusy(int);extern "C" void WfcNumberPad_Create();extern "C" int WfcUtility_PlaySequenceArchiveEntry(unsigned);extern "C" char* WfcUtilityReleaseIpv4Editor_UnknownRoleZeroInitializedStorage;
extern "C" void Ov031_SetCurrentObjectByte66(unsigned char);extern "C" void WfcNumberPad_SetDigitEntryEnabled(unsigned char);extern "C" void WfcNumberPad_SetAdvanceFieldEnabled(int);extern "C" int Util_TestSelectedThreeDigitValueAtLeast(int);extern "C" void WfcUtility_SetMainLoopCallback(void(*)());extern "C" void System_InstallInputStateCallbackUnlessByte60Is1F();
// Original: arm9/ov031 @ 0x0222D9A4; symbol: InitializeIdleSelectionAndSetMainLoopCallback; size: 0x8C.
// Initializes selection flags only when both contexts are idle, then advances the callback.
extern "C" void InitializeIdleSelectionAndSetMainLoopCallback(){if(WfcUtility_IsScreenTransitionBusy(1))return;if(WfcUtility_IsScreenTransitionBusy(0))return;WfcNumberPad_Create();WfcUtility_PlaySequenceArchiveEntry(20);if(!*(unsigned char*)(WfcUtilityReleaseIpv4Editor_UnknownRoleZeroInitializedStorage+0x14)){Ov031_SetCurrentObjectByte66(0);WfcNumberPad_SetAdvanceFieldEnabled(0);}else {if(Util_TestSelectedThreeDigitValueAtLeast(26))WfcNumberPad_SetDigitEntryEnabled(0);WfcNumberPad_SetAdvanceFieldEnabled(0);}WfcUtility_SetMainLoopCallback(System_InstallInputStateCallbackUnlessByte60Is1F);}
