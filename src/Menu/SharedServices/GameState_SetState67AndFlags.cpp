#include <globaldefs.h>
ARM
extern "C" void Menu_QueueScriptEntry(void*, unsigned int);
extern "C" unsigned int TextContext_GetSharedInstance(void);
// Original data: arm9/ov004 @ 0x2171048; symbol: data_ov004_02171048.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" unsigned int GameStateSetState67AndFlags_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov004 @ 0x0216F824; symbol: func_ov004_0216f824; size: 0x30.
extern "C" int GameState_SetState67AndFlags(void* self) { Menu_QueueScriptEntry(self, 0x67); *(unsigned int*)((char*)TextContext_GetSharedInstance() + 0x2c8) = 1; *((unsigned char*)(unsigned int)GameStateSetState67AndFlags_UnknownRoleZeroInitializedStorage[1] + 0x31) = 1; return 0; }
