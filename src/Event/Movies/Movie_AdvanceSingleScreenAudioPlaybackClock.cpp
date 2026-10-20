#include <globaldefs.h>
ARM
#pragma optimization_level 4
// Original data: arm9/ov016 @ 0x219d0c0; symbol: data_ov016_0219d0c0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov016.md.
extern "C" unsigned long long MemoryAllocateSafe_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov016 @ 0x0218BCC4; symbol: func_ov016_0218bcc4; size: 0x24.
extern "C" void Movie_AdvanceSingleScreenAudioPlaybackClock(void) {
    ++MemoryAllocateSafe_UnknownRoleZeroInitializedStorage[9];
}
