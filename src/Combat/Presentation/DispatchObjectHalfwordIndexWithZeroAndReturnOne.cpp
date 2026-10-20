#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage[];
extern "C" void SoundSfx_StartCurrentSequenceArchiveEntry(char *, int, void *);
// Original: arm9/ov025 @ 0x021E49E0; symbol: func_ov025_021e49e0; size: 0x20.
extern "C" int DispatchObjectHalfwordIndexWithZeroAndReturnOne(void *object) {
    SoundSfx_StartCurrentSequenceArchiveEntry((char *)Main_UnknownRoleZeroInitializedStorage, (int)*(unsigned short *)((char *)object + 8), 0);
    return 1;
}
