#include "System/ProcessorContext.h"
#include "System/Interrupts.h"

#pragma dont_inline on
#pragma optimize_for_size off

#if defined(jpn)
#define func_020c9bf0 func_020cb6bc
#endif
extern "C" void func_020c9bf0();

void SleepCompletionProc(ProcessorContext **ppContext)
{
    ProcessorContext* context = *ppContext;
    *ppContext = NULL;
    context->sleepAlarm = NULL;
    MarkContextReadyAndSwitch(context);
}

PFNSwitchContextProc SetSwitchContextProcB(PFNSwitchContextProc proc)
{
    int priorState = DisableIRQInterrupts();
    PFNSwitchContextProc oldProc = data_021112e0.substruct_24.switchContextProcB;
    data_021112e0.substruct_24.switchContextProcB = proc;
    SetIRQInterruptState(priorState);
    return oldProc;
}

void InterruptWaitLoopFunction(void* unusedUserdata)
{
    EnableIRQInterrupts();
    while (true)
        func_020c9bf0();
}

