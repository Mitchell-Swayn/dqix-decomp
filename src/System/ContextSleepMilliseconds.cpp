#include "System/ProcessorContext.h"
#include "System/Interrupts.h"
#include <globaldefs.h>
// Blocks the active processor context until a one-shot alarm clears its pointer.
// Original: arm9/main @ 0x020C7B40; symbol: _Z19SleepCurrentContextj; size: 0xA8.
void SleepCurrentContext(unsigned int milliseconds)
{
    Alarm timing;
    ZeroInitializeAlarm(&timing);
    ProcessorContext* volatile context = *OSInitThread_UnknownRoleZeroInitializedStorage.ppActiveContext;

    int priorState = DisableIRQInterrupts();

    uint64_t numTicks = (uint64_t)milliseconds * TIMER_TICKS_PER_MILLISECOND >> 6;
    context->sleepAlarm = &timing;
    SetTimeout(&timing, numTicks, &SleepCompletionProc, (ProcessorContext**)&context);

    if (context != NULL)
    {
        do {
            BlockCurrentContext(NULL);
        } while (context != NULL);
    }

    SetIRQInterruptState(priorState);
}
