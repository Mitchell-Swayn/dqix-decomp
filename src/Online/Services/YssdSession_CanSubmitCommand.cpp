#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e590; symbol: data_ov031_0224e590.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned YssdSessionTryDestroy_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x02211484; symbol: func_ov031_02211484; size: 0x78.
extern "C" int YssdSession_CanSubmitCommand(int wideMode, unsigned value) {
    volatile unsigned* global = &YssdSessionTryDestroy_UnknownRoleZeroInitializedStorage;
    void* state = (void*)*global;
    if (state == 0) return 0;
    if (*(unsigned*)state != 2) return 0;
    if (*(unsigned*)((char*)state + 0x10) != 0) return 0;
    if (wideMode) {
        if (value < 1 || value > 0xff) return 0;
    } else {
        if (value < 1 || value > 0xf) return 0;
    }
    return 1;
}
