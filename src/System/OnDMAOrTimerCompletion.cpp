#include "System/Interrupts.h"
#include "System/InterruptResponse.h"
#include "System/DTCM.h"

#pragma optimize_for_size off

// Original: arm9/main @ 0x020C69CC; symbol: _Z22OnDMAOrTimerCompletioni; size: 0x88.
void OnDMAOrTimerCompletion(int index)
{
    unsigned int irqMask = 1 << OnDMAOrTimerCompletion_UnknownRoleInitializedBytes[index];

    DMACompletionCallback callback = GetInterruptHandler_UnknownRoleZeroInitializedStorage[index].callback;
    GetInterruptHandler_UnknownRoleZeroInitializedStorage[index].callback = NULL;

    if (callback != NULL)
        callback(GetInterruptHandler_UnknownRoleZeroInitializedStorage[index].userdata);

    DTCM_DATA_INTERRUPTS_FIRED |= irqMask;

    if (!GetInterruptHandler_UnknownRoleZeroInitializedStorage[index].stayEnabledAfter)
        DisableSpecificInterrupts(irqMask);
}
