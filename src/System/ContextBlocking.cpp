#include "System/ProcessorContext.h"
#include "System/Interrupts.h"

#pragma dont_inline on
#pragma optimize_for_size off

// Original: arm9/main @ 0x020C783C; symbol: _Z23CancelContextSleepAlarmP16ProcessorContext; size: 0x18.
void CancelContextSleepAlarm(ProcessorContext *context)
{
    if (context->sleepAlarm == NULL)
        return;

    CancelAlarm(context->sleepAlarm);
}

// Original: arm9/main @ 0x020C7854; symbol: _Z22AwaitContextCompletionP16ProcessorContext; size: 0x30.
void AwaitContextCompletion(ProcessorContext *context) 
{
    int priorState = DisableIRQInterrupts();
    if (context->blockState != CONTEXT_STATE_INVALID)
        BlockCurrentContext(&context->contextsAwaitingThisCompletion);
    SetIRQInterruptState(priorState);
}

// Original: arm9/main @ 0x020C7884; symbol: _Z17IsContextInactiveP16ProcessorContext; size: 0x14.
bool IsContextInactive(ProcessorContext* context)
{
    return context->blockState == CONTEXT_STATE_INVALID;
}

// Original: arm9/main @ 0x020C7898; symbol: _Z19BlockCurrentContextP18BlockedContextList; size: 0x50.
void BlockCurrentContext(BlockedContextList* blockQueue)
{
    int priorState = DisableIRQInterrupts();

    ProcessorContext* current = *OSInitThread_UnknownRoleZeroInitializedStorage.ppActiveContext;
    if (blockQueue != NULL)
    {
        current->containerBlockedQueue = blockQueue;
        blockQueue->Insert(current);
    }
    current->blockState = CONTEXT_STATE_BLOCKED;
    SwitchContext();
    SetIRQInterruptState(priorState);
}

// Original: arm9/main @ 0x020C78E8; symbol: _Z15UnblockContextsP18BlockedContextList; size: 0x68.
void UnblockContexts(BlockedContextList* blockQueue)
{
    int priorState = DisableIRQInterrupts();
    if (blockQueue->first != NULL)
    {
        // Preserve the repeated empty-list check observed in the original.
        if (blockQueue->first != NULL)
        {
            do
            {
                ProcessorContext* context = blockQueue->PopFront();
                context->blockState = CONTEXT_STATE_READY;
                context->containerBlockedQueue = NULL;
                context->pNextBlocked = NULL;
                context->pPrevBlocked = NULL;
            } while (blockQueue->first != NULL);
        }
        blockQueue->last = NULL;
        blockQueue->first = NULL;
        SwitchContext();
    }
    SetIRQInterruptState(priorState);
}

// Original: arm9/main @ 0x020C7950; symbol: _Z25MarkContextReadyAndSwitchP16ProcessorContext; size: 0x28.
void MarkContextReadyAndSwitch(ProcessorContext* context)
{
    int priorState = DisableIRQInterrupts();
    context->blockState = CONTEXT_STATE_READY;
    SwitchContext();
    SetIRQInterruptState(priorState);
}

// Original: arm9/main @ 0x020C7978; symbol: _Z20GetFirstReadyContextv; size: 0x28.
ProcessorContext* GetFirstReadyContext()
{
    ProcessorContext* context = OSInitThread_UnknownRoleZeroInitializedStorage.substruct_24.firstContext;
    while (context != NULL && context->blockState != CONTEXT_STATE_READY)
    {
        context = context->pNext;
    }
    return context;
}

// Original: arm9/main @ 0x020C79A0; symbol: _Z26SwitchContextUninterruptedv; size: 0x1C.
void SwitchContextUninterrupted()
{
    int priorState = DisableIRQInterrupts();
    SwitchContext();
    SetIRQInterruptState(priorState);
}

