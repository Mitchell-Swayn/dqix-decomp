#include <globaldefs.h>

#include <System/ProcessorContext.h>

// Original: arm9/main @ 0x020D9834; symbol: func_020d9834; size: 0x1C.
extern "C" ARM void ProcessorContext_SleepOrYieldPriorityPeers(unsigned milliseconds) {
    if (milliseconds) SleepCurrentContext(milliseconds);
    else CycleCurrentPriorityContexts();
}
