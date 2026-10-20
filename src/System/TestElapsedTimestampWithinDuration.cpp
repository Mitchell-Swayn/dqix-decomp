#include <globaldefs.h>
#include <System/Timing.h>
// Original data: arm9/main @ 0x2153628; symbol: data_02153628.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct State {unsigned duration;unsigned long long start;};extern "C" State TestElapsedTimestampWithinDuration_UnknownRoleZeroInitializedStorage;
// Original: arm9/main @ 0x020E11E4; symbol: func_020e11e4; size: 0x58.
extern "C" ARM bool TestElapsedTimestampWithinDuration(){unsigned long long elapsed=GetCurrentTimestamp()-TestElapsedTimestampWithinDuration_UnknownRoleZeroInitializedStorage.start;return (elapsed*64/33514)<TestElapsedTimestampWithinDuration_UnknownRoleZeroInitializedStorage.duration;}
