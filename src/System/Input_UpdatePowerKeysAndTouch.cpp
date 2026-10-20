#include <globaldefs.h>
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
extern "C" char KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[],Main_UnknownRoleZeroInitializedStorage_Variant4[];
extern "C" void PowerManagement_HandleLidStateAndResourceTransitions();
extern "C" void Input_ResumeSamplingWhenSuppressionExpires();
extern "C" void Input_SampleKeysWhenLidOpenAndDisplayVisible(void*);
extern "C" void TouchInput_UpdateSampleAndPressState(void*);
// Original: arm9/main @ 0x02012EFC; symbol: func_02012efc; size: 0x28.
extern "C" void Input_UpdatePowerKeysAndTouch() {PowerManagement_HandleLidStateAndResourceTransitions();Input_ResumeSamplingWhenSuppressionExpires();Input_SampleKeysWhenLidOpenAndDisplayVisible(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage);TouchInput_UpdateSampleAndPressState(Main_UnknownRoleZeroInitializedStorage_Variant4);}
