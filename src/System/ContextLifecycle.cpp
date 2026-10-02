#include "System/ProcessorContext.h"
#include "System/Mutex.h"
#include "System/Timing.h"
#include "System/Interrupts.h"
#include <globaldefs.h>

#pragma dont_inline on
#pragma optimize_for_size off

#if defined(jpn)
#define func_020c9bf0 func_020cb6bc
#define func_020c9be0 func_020cb6ac
#define func_020ca3ec func_020cbeb8
#endif

extern "C"
{
    // wait for an interrupt
    void func_020c9bf0();

    // something like abort()
    void func_020c9be0();

    // memset with silly signature and assuming alignment
    void func_020ca3ec(int value, void* dst, unsigned len);
}

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

    func_020ca3ec(0, (void*)(stackBottom - stackSize + 4), stackSize - 8);
    context->blockingMutex = NULL;
    context->lockedMutexes.pFirst = NULL;
    context->lockedMutexes.pLast = NULL;
    SetContextEndProc(context, NULL);

    context->containerBlockedQueue = NULL;
    context->pNextBlocked = NULL;
    context->pPrevBlocked = NULL;
    func_020ca3ec(0, &context->unknown_A4, 12);
    context->sleepAlarm = NULL;

    SetIRQInterruptState(priorState);
}

void ContextExecutionReturnProc()
{
    DisableIRQInterrupts();
    ExitContext(data_021112e0.substruct_24.activeContext, 0);
}

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
    func_020c9be0();
}

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

