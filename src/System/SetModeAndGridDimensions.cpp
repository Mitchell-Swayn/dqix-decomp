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
// Original: arm9/main @ 0x02028D68; symbol: func_02028d68; size: 0x74.
extern "C" void SetModeAndGridDimensions(unsigned int mode){DebugMenuInitialize_UnknownRoleInitializedBytes[3]=mode;if(mode==0){DebugMenuInitialize_UnknownRoleInitializedBytes[1]=8;DebugMenuInitialize_UnknownRoleInitializedBytes[2]=8;return;}if(mode-1<=1){DebugMenuInitialize_UnknownRoleInitializedBytes[2]=6;DebugMenuInitialize_UnknownRoleInitializedBytes[1]=12;return;}if(mode-3<=1){DebugMenuInitialize_UnknownRoleInitializedBytes[2]=5;DebugMenuInitialize_UnknownRoleInitializedBytes[1]=10;return;}if(mode-5<=1){DebugMenuInitialize_UnknownRoleInitializedBytes[2]=6;DebugMenuInitialize_UnknownRoleInitializedBytes[1]=12;}}
