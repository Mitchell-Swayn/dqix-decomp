#include <globaldefs.h>
ARM
extern "C" void SoundSfx_RestoreHeapAfterGroupPlayback(unsigned char *);
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov017 @ 0x021BE3EC; symbol: func_ov017_021be3ec; size: 0x20.
extern "C" void Resource_DispatchStoredHandleAndMarkObjectActive(unsigned char *p) {
    SoundSfx_RestoreHeapAfterGroupPlayback(Main_UnknownRoleZeroInitializedStorage);
    p[1] = 1;
}
