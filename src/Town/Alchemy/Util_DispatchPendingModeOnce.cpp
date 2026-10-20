#include <globaldefs.h>
ARM
extern "C" void SoundSfx_StartCurrentSequenceArchiveEntry(char* p,int a,void* b);
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov006 @ 0x02159F0C; symbol: func_ov006_02159f0c; size: 0x88.
extern "C" void Util_DispatchPendingModeOnce(char *self) {
    if (*(int*)(self + 0x3ac)) return;
    if (!*(int*)(self + 0x3a4)) return;
    switch (*(int*)(self + 0x39c)) {
    case 0: SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage, 10, 0); break;
    case 1: SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage, 12, 0); break;
    case 2: SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage, 11, 0); break;
    }
    *(int*)(self + 0x3ac) = 1;
}
