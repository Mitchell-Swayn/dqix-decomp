#include <globaldefs.h>
#include <System/Timing.h>
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2114e54; symbol: data_02114e54.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 112 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2153628; symbol: data_02153628.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned TestElapsedTimestampWithinDuration_UnknownRoleZeroInitializedStorage[]; extern unsigned char KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[],Main_UnknownRoleZeroInitializedStorage_Variant4[];
extern "C" void Input_SetKeySamplingEnabled(void*,unsigned char); extern "C" void Input_ClearKeyHistory(void*); extern "C" void TouchInput_SetSamplingEnabled(void*,unsigned char); extern "C" void TouchInput_ResetTrackingStateWrapper(void*);
// Original: arm9/main @ 0x020E1154; symbol: func_020e1154; size: 0x50.
extern "C" void StoreModeTimestampAndDisableTwoInputOwners(unsigned mode) { unsigned long long time=GetCurrentTimestamp(); *(unsigned long long*)(TestElapsedTimestampWithinDuration_UnknownRoleZeroInitializedStorage+1)=time; TestElapsedTimestampWithinDuration_UnknownRoleZeroInitializedStorage[0]=mode; Input_SetKeySamplingEnabled(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0); Input_ClearKeyHistory(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage); TouchInput_SetSamplingEnabled(Main_UnknownRoleZeroInitializedStorage_Variant4,0); TouchInput_ResetTrackingStateWrapper(Main_UnknownRoleZeroInitializedStorage_Variant4); }
