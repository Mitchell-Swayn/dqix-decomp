#include <globaldefs.h>
#include <System/ProcessorContext.h>
extern "C" unsigned int data_ov031_0224c980[];
// Sleeps for the shared delay when nonzero; otherwise cycles the current context.
// Original: arm9/ov031 @ 0x02200264; symbol: func_ov031_02200264; size: 0x28.
extern "C" ARM void SleepOrCycleCurrentContextFromSharedState()
{
    unsigned int delay = data_ov031_0224c980[0x24 / 4];
    if (delay == 0) CycleCurrentPriorityContexts();
    else SleepCurrentContext(delay);
}
