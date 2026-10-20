#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];extern "C" int Input_IsKeyMaskNewlyPressed(void*,int);
// Original: arm9/main @ 0x020E2984; symbol: func_020e2984; size: 0x24.
extern "C" bool Input_TestPressedKeyBitOne(){return Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,2)!=0;}
