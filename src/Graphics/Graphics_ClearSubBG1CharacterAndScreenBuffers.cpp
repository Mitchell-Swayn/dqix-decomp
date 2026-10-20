#include <System/BGBases.h>
// Reviewed original control flow and widths; initialization retains per-field writes.
#include <System/Cache.h>
#include <System/LoadToVRAM.h>
#include <System/Graphics.h>
// Original data: arm9/main @ 0x20ef74c; symbol: data_020ef74c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 407d00000800000008000000ffffffff.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" void* memcpy(void*,const void*,unsigned int);extern "C" void* memset(void*,int,unsigned int);extern "C" unsigned int DebugMenuInitialize_UnknownRoleInitializedBytes[];struct Pair{unsigned int first:10;unsigned int second:10;unsigned int rest:12;};
// Original: arm9/main @ 0x020A64E8; symbol: func_020a64e8; size: 0x64.
extern "C" void Graphics_ClearSubBG1CharacterAndScreenBuffers(){unsigned char zero[32];*(volatile unsigned int*)0x04001014=0;memset(zero,0,32);CleanCacheRange(zero,32);CleanInvalidateCacheRange(zero,32);LoadToSubBG1CharacterData(zero,0,32);void* screen=(void*)GetSubBG1ScreenBase();memset(screen,0,0x800);}
