#pragma thumb off
struct CounterState {char pad[0x14];unsigned short count;signed char marker;};
// Original data: arm9/ov031 @ 0x2250ba8; symbol: data_ov031_02250ba8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" CounterState* WfcUtilityDestroyBottomButtonBar_UnknownRoleZeroInitializedStorage;
extern "C" void WfcUtility_UpdateBottomButtonTouchSelection(void*,void*);
extern "C" void WfcUtility_SetTaskCallback(void*,void (*)(void*,void*));
// Original: arm9/ov031 @ 0x02222FB0; symbol: func_ov031_02222fb0; size: 0x50.
extern "C" void System_AdvanceFourStepCounterAndSetCallback(void* object,void*) {
 WfcUtilityDestroyBottomButtonBar_UnknownRoleZeroInitializedStorage->marker=-1;
 WfcUtilityDestroyBottomButtonBar_UnknownRoleZeroInitializedStorage->count++;
 if(WfcUtilityDestroyBottomButtonBar_UnknownRoleZeroInitializedStorage->count>=4) {
  WfcUtilityDestroyBottomButtonBar_UnknownRoleZeroInitializedStorage->count=0;
  WfcUtility_SetTaskCallback(object,&WfcUtility_UpdateBottomButtonTouchSelection);
 }
}
