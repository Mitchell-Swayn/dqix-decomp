#pragma once
#include "System/DMA.h"

struct DMAOrTimerResponse {
    DMACompletionCallback callback;
    unsigned int stayEnabledAfter;
    int userdata;
};

#if defined(jpn)
#define GetInterruptHandler_UnknownRoleZeroInitializedStorage data_02110f1c
#define OnDMAOrTimerCompletion_UnknownRoleInitializedBytes data_020f23e0
#endif

// Slots 0..3 are DMA channels; slots 4..7 are timers.
// Original data: arm9/main @ 0x211127c; symbol: data_0211127c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 96 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern DMAOrTimerResponse GetInterruptHandler_UnknownRoleZeroInitializedStorage[8];
// Original data: arm9/main @ 0x20f2274; symbol: data_020f2274.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 080009000a000b000300040005000600.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned short OnDMAOrTimerCompletion_UnknownRoleInitializedBytes[8];
typedef char DMAOrTimerResponseSizeCheck[sizeof(DMAOrTimerResponse) == 12 ? 1 : -1];
