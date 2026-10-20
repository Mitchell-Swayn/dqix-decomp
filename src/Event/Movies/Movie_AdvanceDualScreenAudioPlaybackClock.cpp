#include <globaldefs.h>
ARM
struct CounterState { char padding[0x44]; unsigned long long counter; };
// Original data: arm9/ov016 @ 0x219d144; symbol: data_ov016_0219d144.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov016.md.
extern "C" CounterState MoviePlayDualScreenFiles_UnknownRoleZeroInitializedStorage_Variant2;
// Original: arm9/ov016 @ 0x0218CF34; symbol: func_ov016_0218cf34; size: 0x24.
extern "C" void Movie_AdvanceDualScreenAudioPlaybackClock(void) {
    ++MoviePlayDualScreenFiles_UnknownRoleZeroInitializedStorage_Variant2.counter;
}
