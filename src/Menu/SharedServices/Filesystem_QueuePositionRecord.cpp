#include <globaldefs.h>
ARM
// Original data: arm9/ov004 @ 0x217101c; symbol: data_ov004_0217101c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" unsigned char FilesystemQueuePositionRecord_UnknownRoleZeroInitializedStorage[];
extern "C" void MenuTileGrid_SetCoordinatesByKey(void*, void*, unsigned short, unsigned);
// Original: arm9/ov004 @ 0x02165EF4; symbol: func_ov004_02165ef4; size: 0x38.
extern "C" void Filesystem_QueuePositionRecord(void* object) {
    char* state = *(char**)FilesystemQueuePositionRecord_UnknownRoleZeroInitializedStorage;
    int value = *(short*)(state + 0x4C);
    int adjusted = value + 7;
    int quarter = adjusted >> 2;
    int rounded = adjusted + ((unsigned)quarter >> 29);
    int result = (rounded << 13) >> 16;
    MenuTileGrid_SetCoordinatesByKey(object, (void*)0x5B, 0, result);
}
