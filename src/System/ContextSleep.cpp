#include "System/ProcessorContext.h"
#include "System/Interrupts.h"

#pragma dont_inline on
#pragma optimize_for_size off

#if defined(jpn)
#define OS_Halt func_020cb6bc
#endif
extern "C" void OS_Halt();

// Original: arm9/main @ 0x020C7BE8; symbol: _Z19SleepCompletionProcPP16ProcessorContext; size: 0x20.
void SleepCompletionProc(ProcessorContext **ppContext)
{
    ProcessorContext* context = *ppContext;
    *ppContext = NULL;
    context->sleepAlarm = NULL;
    MarkContextReadyAndSwitch(context);
}

// Original: arm9/main @ 0x020C7C08; symbol: _Z21SetSwitchContextProcBPFvP16ProcessorContextS0_E; size: 0x28.
PFNSwitchContextProc SetSwitchContextProcB(PFNSwitchContextProc proc)
{
    int priorState = DisableIRQInterrupts();
    PFNSwitchContextProc oldProc = OSInitThread_UnknownRoleZeroInitializedStorage.substruct_24.switchContextProcB;
    OSInitThread_UnknownRoleZeroInitializedStorage.substruct_24.switchContextProcB = proc;
    SetIRQInterruptState(priorState);
    return oldProc;
}

// Original: arm9/main @ 0x020C7C30; symbol: _Z25InterruptWaitLoopFunctionPv; size: 0x10.
void InterruptWaitLoopFunction(void* unusedUserdata)
{
    EnableIRQInterrupts();
    while (true)
        OS_Halt();
}

