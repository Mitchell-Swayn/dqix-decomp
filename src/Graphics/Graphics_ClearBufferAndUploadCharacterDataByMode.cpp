#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x20ef74c; symbol: data_020ef74c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 407d00000800000008000000ffffffff.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20fe9a4; symbol: data_020fe9a4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" void* DebugMenuUpdateAndRender_UnknownRoleZeroInitializedStorage;extern "C" char DebugMenuInitialize_UnknownRoleInitializedBytes[];extern "C" void* memset(void*,int,unsigned);extern "C" void _Z25CleanInvalidateCacheRangePKvj(const void*,unsigned);extern "C" void LoadToMainBG1CharacterData(const void*,unsigned,unsigned);extern "C" void LoadToSubBG0CharacterData(const void*,unsigned,unsigned);
// Original: arm9/main @ 0x02028E90; symbol: func_02028e90; size: 0xC4.
extern "C" void Graphics_ClearBufferAndUploadCharacterDataByMode(){void* p=DebugMenuUpdateAndRender_UnknownRoleZeroInitializedStorage;if(!p)return;if(p)memset(p,0,24576);int mode=*(int*)(DebugMenuInitialize_UnknownRoleInitializedBytes+12);_Z25CleanInvalidateCacheRangePKvj(DebugMenuUpdateAndRender_UnknownRoleZeroInitializedStorage,24576);if(mode==3){LoadToMainBG1CharacterData(DebugMenuUpdateAndRender_UnknownRoleZeroInitializedStorage,0,24576);return;}if(mode==4){LoadToSubBG0CharacterData(DebugMenuUpdateAndRender_UnknownRoleZeroInitializedStorage,0,24576);return;}if(mode==5){LoadToMainBG1CharacterData(DebugMenuUpdateAndRender_UnknownRoleZeroInitializedStorage,0,24576);return;}if(mode==6)LoadToSubBG0CharacterData(DebugMenuUpdateAndRender_UnknownRoleZeroInitializedStorage,0,24576);}
