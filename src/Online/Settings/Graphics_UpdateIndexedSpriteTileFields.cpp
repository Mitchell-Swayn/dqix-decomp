#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290c8c; symbol: data_ov031_02290c8c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char * volatile TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x0222C5D4; symbol: func_ov031_0222c5d4; size: 0x8C.
extern "C" void Graphics_UpdateIndexedSpriteTileFields(int index, int slot) {
    char *state = TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage[1];
    if (index >= *(unsigned char*)(state + 0x51)) return;
    int offset = index * 42;
    unsigned short *first = *(unsigned short**)(state + 0x10 + slot * 4);
    char *record = *(char**)state + offset;
    first[2] = (first[2] & ~0x3ff) | *(unsigned short*)(state + 0x42 + *(unsigned char*)(record + 0x28) * 2);
    state = TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage[1];
    record = *(char**)state + offset;
    unsigned short *second = *(unsigned short**)(state + 0x24 + slot * 4);
    second[2] = (second[2] & ~0x3ff) | *(unsigned short*)(state + 0x48 + *(unsigned short*)(record + 0x26) * 2);
}
