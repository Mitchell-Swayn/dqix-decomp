#include <globaldefs.h>
extern "C" {
// Original data: arm9/main @ 0x20e9200; symbol: data_020e9200.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000000000400000004000400000000000800000000000400040008000000000008000400080008000000080004000c00000000000000000008000c0000000c0.
// Observed span: 64 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned int GraphicsGetOBJShapeSizeBits_UnknownRoleInitializedBytes[][4];
// Original: arm9/main @ 0x020B11AC; symbol: func_020b11ac; size: 0x1C.
unsigned int Graphics_GetOBJShapeSizeBits(unsigned char *p){return GraphicsGetOBJShapeSizeBits_UnknownRoleInitializedBytes[p[1]][p[0]];}
}
