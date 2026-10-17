#include "System/Interrupts.h"
#include "System/InterruptResponse.h"
#include "System/DTCM.h"

#pragma optimize_for_size off

// Original: arm9/main @ 0x020C69CC; symbol: _Z22OnDMAOrTimerCompletioni; size: 0x88.
void OnDMAOrTimerCompletion(int index)
{
    unsigned int irqMask = 1 << data_020f2274[index];

    DMACompletionCallback callback = data_0211127c[index].callback;
    data_0211127c[index].callback = NULL;

    if (callback != NULL)
        callback(data_0211127c[index].userdata);

    DTCM_DATA_INTERRUPTS_FIRED |= irqMask;

    if (!data_0211127c[index].stayEnabledAfter)
        DisableSpecificInterrupts(irqMask);
}
