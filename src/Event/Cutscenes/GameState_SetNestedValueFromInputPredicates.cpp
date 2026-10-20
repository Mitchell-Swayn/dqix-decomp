#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" void Input_SampleKeysWhenLidOpenAndDisplayVisible(void*); extern "C" int Input_IsYButtonHeld(void*); extern "C" int Input_IsXButtonHeld(void*); extern "C" int Input_IsAHeld(void*); extern "C" int Input_IsKeyBitOneSet(void*); extern "C" void Script_WriteIntegerReferenceOutput(void*,int); extern "C" char KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov001 @ 0x0215AE1C; symbol: GameState_SetNestedValueFromInputPredicates; size: 0x68.
// Updates input state and writes the sum of four input predicates when enabled.
extern "C" int GameState_SetNestedValueFromInputPredicates(void* object, int enabled) { if(enabled<1) return 0; Input_SampleKeysWhenLidOpenAndDisplayVisible(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage); int a=Input_IsYButtonHeld(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage); int b=Input_IsXButtonHeld(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage); int c=Input_IsAHeld(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage); int d=Input_IsKeyBitOneSet(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage); Script_WriteIntegerReferenceOutput(object, a+(b+(c+d))); return 1; }
