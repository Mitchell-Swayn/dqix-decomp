#include <globaldefs.h>
ARM
#include <System/LoadToVRAM.h>
extern "C" void* memset(void*,int,unsigned);
// Original data: arm9/main @ 0x2105fd8; symbol: data_02105fd8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 1536 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x21065d8; symbol: data_021065d8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4096 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned char GraphicsClearSubBackgroundCharacterBuffers_UnknownRoleZeroInitializedStorage_Variant2[],GraphicsClearSubBackgroundCharacterBuffers_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x0203B678; symbol: func_0203b678; size: 0xA0.
extern "C" void Graphics_ClearSubBackgroundCharacterBuffers(int* object,int screen,int layer){unsigned char zero[32];object[screen]=32;*(int*)((char*)(object+screen)+0x20)=1;memset(zero,0,32);if(screen==1){switch(layer){case 0:memset(GraphicsClearSubBackgroundCharacterBuffers_UnknownRoleZeroInitializedStorage_Variant2,0,0x1000);LoadToSubBG0CharacterData(zero,0,32);break;case 1:memset(GraphicsClearSubBackgroundCharacterBuffers_UnknownRoleZeroInitializedStorage,0,0x600);LoadToSubBG1CharacterData(zero,0,32);break;}}}
