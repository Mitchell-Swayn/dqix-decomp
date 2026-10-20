#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x20fe9a4; symbol: data_020fe9a4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" void* DebugMenuUpdateAndRender_UnknownRoleZeroInitializedStorage;extern "C" void LoadToMainBG1CharacterData(const void*,unsigned int,unsigned int);extern "C" void LoadToSubBG0CharacterData(const void*,unsigned int,unsigned int);
// Original: arm9/main @ 0x020290AC; symbol: func_020290ac; size: 0x3C.
extern "C" void Graphics_UploadMainOrSubBackgroundCharacterBuffer(int sub) { void* p=DebugMenuUpdateAndRender_UnknownRoleZeroInitializedStorage;if(!p)return;if(!sub)LoadToMainBG1CharacterData(p,0,0x6000);else LoadToSubBG0CharacterData(p,0,0x6000); }
