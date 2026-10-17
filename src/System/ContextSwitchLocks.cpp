#include "System/ProcessorContext.h"
#include "System/Interrupts.h"

#pragma dont_inline on
#pragma optimize_for_size off

// Original: arm9/main @ 0x020C7C40; symbol: _Z20AddContextSwitchLockv; size: 0x34.
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

// Original: arm9/main @ 0x020C7C74; symbol: _Z23RemoveContextSwitchLockv; size: 0x34.
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

// Original: arm9/main @ 0x020C7CA8; symbol: _Z17SetContextEndProcP16ProcessorContextPFviE; size: 0x8.
void SetContextEndProc(ProcessorContext* context, ProcessorContext::ExitRoutine proc)
{
    context->exitProc = proc;
}

