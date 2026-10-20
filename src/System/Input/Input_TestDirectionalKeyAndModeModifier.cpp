#include <globaldefs.h>
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[]; extern "C" int Input_TestKeyMask(void*,unsigned);
// Original: arm9/main @ 0x0202A9F4; symbol: func_0202a9f4; size: 0xA0.
extern "C" ARM int Input_TestDirectionalKeyAndModeModifier(const char* state) { switch(*(int*)(state+64)) { case 0: if(Input_TestKeyMask(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,64)) return 1; case 1: if(Input_TestKeyMask(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,64)&&Input_TestKeyMask(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,1024)) return 1; case 2: if(Input_TestKeyMask(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,64)&&Input_TestKeyMask(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,2048)) return 1; } return 0; }
