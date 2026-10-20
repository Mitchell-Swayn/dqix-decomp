#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x0223566C; symbol: ComputeRectangleBoundsForOrientation; size: 0xD8.
// Original data: arm9/ov031 @ 0x2290cf4; symbol: data_ov031_02290cf4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int WfcScrollbarDestroy_UnknownRoleZeroInitializedStorage;
// Original data: arm9/ov031 @ 0x22491f4; symbol: data_ov031_022491f4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 55361e00.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcScrollbarGetPartBounds_UnknownRoleInitializedBytes[];
extern "C" void WfcScrollbar_GetPartBounds(unsigned int direction, unsigned short* bounds)
{
    unsigned short x = *(unsigned short*)(*(unsigned int*)(&WfcScrollbarDestroy_UnknownRoleZeroInitializedStorage) + 0x10);
    bounds[0] = x;
    bounds[2] = x + 12;
    switch (direction) {
    case 1: {
        unsigned int rect = *(unsigned int*)(&WfcScrollbarDestroy_UnknownRoleZeroInitializedStorage);
        bounds[1] = *(unsigned short*)(rect + 0x12) + *(unsigned char*)(rect + 0x1a);
        bounds[3] = bounds[1] + WfcScrollbarGetPartBounds_UnknownRoleInitializedBytes[*(unsigned char*)(*(unsigned int*)(&WfcScrollbarDestroy_UnknownRoleZeroInitializedStorage) + 0x1b)];
        break;
    }
    case 2: {
        bounds[1] = *(unsigned short*)(*(volatile unsigned int*)(&WfcScrollbarDestroy_UnknownRoleZeroInitializedStorage) + 0x12) - 13;
        bounds[3] = *(unsigned short*)(*(volatile unsigned int*)(&WfcScrollbarDestroy_UnknownRoleZeroInitializedStorage) + 0x12);
        break;
    }
    case 3: {
        unsigned int rect = *(unsigned int*)(&WfcScrollbarDestroy_UnknownRoleZeroInitializedStorage);
        bounds[1] = *(unsigned short*)(rect + 0x12) + *(unsigned char*)(rect + 0x19);
        bounds[3] = bounds[1] + 13;
        break;
    }
    case 4: {
        unsigned int rect = *(volatile unsigned int*)(&WfcScrollbarDestroy_UnknownRoleZeroInitializedStorage);
        unsigned short y = *(unsigned short*)(rect + 0x12);
        bounds[1] = y;
        rect = *(volatile unsigned int*)(&WfcScrollbarDestroy_UnknownRoleZeroInitializedStorage);
        bounds[3] = y + *(unsigned char*)(rect + 0x19);
        break;
    }
    }
}
