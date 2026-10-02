#include "System/ProcessorContext.h"
#include "System/Interrupts.h"

#pragma dont_inline on
#pragma optimize_for_size off

unsigned int AddContextSwitchLock()
{
    int priorState = DisableIRQInterrupts();

    // Original leaves the return register unchanged when the counter is saturated.
    // The return value is unspecified in that case; do not manufacture a new value.
    unsigned int oldCount;
    if (data_021112e0.contextSwitchLock < (unsigned int)-1)
    {
        oldCount = data_021112e0.contextSwitchLock;
        data_021112e0.contextSwitchLock++;
    }

    SetIRQInterruptState(priorState);
    return oldCount;
}

unsigned int RemoveContextSwitchLock()
{
    int priorState = DisableIRQInterrupts();

    unsigned int oldCount = 0;
    if (data_021112e0.contextSwitchLock > 0)
    {
        oldCount = data_021112e0.contextSwitchLock;
        data_021112e0.contextSwitchLock--;
    }

    SetIRQInterruptState(priorState);
    return oldCount;
}

void SetContextEndProc(ProcessorContext* context, ProcessorContext::ExitRoutine proc)
{
    context->exitProc = proc;
}

