#include "System/ProcessorContext.h"
#include "System/Mutex.h"
#include "System/Timing.h"
#include "System/Interrupts.h"
#include <globaldefs.h>

#pragma dont_inline on
#pragma optimize_for_size off

#if defined(jpn)
#define OS_Halt func_020cb6bc
#define DisableInterruptsAndHaltForever func_020cb6ac
#define MIi_CpuClear32 func_020cbeb8
#endif

extern "C"
{
    // wait for an interrupt
    void OS_Halt();

    // something like abort()
    void DisableInterruptsAndHaltForever();

    // memset with silly signature and assuming alignment
    void MIi_CpuClear32(int value, void* dst, unsigned len);
}

// Original: arm9/main @ 0x020C75B4; symbol: _Z24PopulateProcessorContextP16ProcessorContextjjjjj; size: 0xFC.
void PopulateProcessorContext(ProcessorContext *context, unsigned int startAddress,
    unsigned int userdata, unsigned int stackBottom,
    unsigned int stackSize, unsigned int priority)
{
    int priorState = DisableIRQInterrupts();
    int uniqueID = GenerateUniqueContextID();
    context->priority = priority;
    context->uniqueID = uniqueID;
    context->unknown_74 = context->blockState = 0; // CONTEXT_STATE_BLOCKED

    InsertContextIntoGlobalList(context);

    context->stackBottom = stackBottom;
    context->stackTop = stackBottom - stackSize;
    context->stackUnknownTopSubspaceSize = 0;
    *(int*)(context->stackBottom - 4) = STACK_BOTTOM_MAGIC;
    *(int*)(context->stackTop) = STACK_TOP_MAGIC;
    context->contextsAwaitingThisCompletion.first = context->contextsAwaitingThisCompletion.last = NULL;

    InitializeContextRegisters(context, startAddress, stackBottom - 4);
    context->userModeRegisters[0] = userdata;
    // when the function at startAddress returns, go here
    context->userModeRegisters[14] = (unsigned int)&ContextExecutionReturnProc;

    MIi_CpuClear32(0, (void*)(stackBottom - stackSize + 4), stackSize - 8);
    context->blockingMutex = NULL;
    context->lockedMutexes.pFirst = NULL;
    context->lockedMutexes.pLast = NULL;
    SetContextEndProc(context, NULL);

    context->containerBlockedQueue = NULL;
    context->pNextBlocked = NULL;
    context->pPrevBlocked = NULL;
    MIi_CpuClear32(0, &context->unknown_A4, 12);
    context->sleepAlarm = NULL;

    SetIRQInterruptState(priorState);
}

// Original: arm9/main @ 0x020C76B0; symbol: _Z26ContextExecutionReturnProcv; size: 0x20.
void ContextExecutionReturnProc()
{
    DisableIRQInterrupts();
    ExitContext(data_021112e0.substruct_24.activeContext, 0);
}

// Original: arm9/main @ 0x020C76D0; symbol: _Z11ExitContextP16ProcessorContexti; size: 0x5C.
void ExitContext(ProcessorContext *context, int exitCode)
{
    if (data_021112e0.unknown_1C != 0)
    {
        // context will resume execution with pc at ExitCurrentContext invocation
        // and with IRQ interrupts disabled.
        InitializeContextRegisters(context, (unsigned int)&ExitCurrentContext, data_021112e0.unknown_1C);
        context->userModeRegisters[0] = exitCode;
        context->programStatusRegister |= (1 << 7); // disable IRQ interrupts here
        context->blockState = 1;
        RestoreContext(context);
    }
    else
    {
        ExitCurrentContext(exitCode);
    }
}

// Original: arm9/main @ 0x020C772C; symbol: _Z18ExitCurrentContexti; size: 0x38.
void ExitCurrentContext(int code)
{
    ProcessorContext* context = *data_021112e0.ppActiveContext;
    ProcessorContext::ExitRoutine proc = context->exitProc;
    if (proc != NULL)
    {
        context->exitProc = NULL;
        proc(code);
        DisableIRQInterrupts();
    }
    ShutdownCurrentContext();
}

// Original: arm9/main @ 0x020C7764; symbol: _Z22ShutdownCurrentContextv; size: 0x5C.
void ShutdownCurrentContext()
{
    ProcessorContext* context = *data_021112e0.ppActiveContext;
    AddContextSwitchLock();
    UnlockAllMutexesLockedByContext(context);
    if (context->containerBlockedQueue != NULL)
        context->containerBlockedQueue->Remove(context);

    RemoveContextFromGlobalList(context);
    context->blockState = CONTEXT_STATE_INVALID;
    UnblockContexts(&context->contextsAwaitingThisCompletion);
    RemoveContextSwitchLock();
    SwitchContextUninterrupted();
    DisableInterruptsAndHaltForever();
}

// Original: arm9/main @ 0x020C77C0; symbol: _Z15ShutdownContextP16ProcessorContext; size: 0x7C.
void ShutdownContext(ProcessorContext* context)
{
    int priorState = DisableIRQInterrupts();

    if (data_021112e0.substruct_24.activeContext == context)
        ShutdownCurrentContext(); // function call will not return

    AddContextSwitchLock();
    UnlockAllMutexesLockedByContext(context);
    CancelContextSleepAlarm(context);
    if (context->containerBlockedQueue != NULL)
        context->containerBlockedQueue->Remove(context);

    RemoveContextFromGlobalList(context);
    context->blockState = CONTEXT_STATE_INVALID;
    UnblockContexts(&context->contextsAwaitingThisCompletion);
    RemoveContextSwitchLock();
    SetIRQInterruptState(priorState);

    SwitchContextUninterrupted();
}

