#pragma once
#include "System/DMA.h"

struct DMAOrTimerResponse {
    DMACompletionCallback callback;
    unsigned int stayEnabledAfter;
    int userdata;
};

#if defined(jpn)
#define data_0211127c data_02110f1c
#define data_020f2274 data_020f23e0
#endif

// Slots 0..3 are DMA channels; slots 4..7 are timers.
extern DMAOrTimerResponse data_0211127c[8];
extern unsigned short data_020f2274[8];
typedef char DMAOrTimerResponseSizeCheck[sizeof(DMAOrTimerResponse) == 12 ? 1 : -1];
