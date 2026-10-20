#include "System/ProcessorContext.h"
#include "System/Interrupts.h"
#include "System/BiosData.h"
#pragma optimize_for_size off
// Original: arm9/main @ 0x020C79BC; symbol: _Z28CycleCurrentPriorityContextsv; size: 0xB8.
void CycleCurrentPriorityContexts()
{
    ProcessorContext* contextBeforeActive = NULL;
    ProcessorContext* lastEqualPriorityContext = NULL;
    int numEqualPriorityContexts = 0;
    int priorState;
    ProcessorContext* active = OSInitThread_UnknownRoleZeroInitializedStorage.substruct_24.activeContext;
    priorState = DisableIRQInterrupts();
    ProcessorContext* loopPrevContext = NULL;
    ProcessorContext* loopContext = OSInitThread_UnknownRoleZeroInitializedStorage.substruct_24.firstContext;
    if (OSInitThread_UnknownRoleZeroInitializedStorage.substruct_24.firstContext != NULL)
    {
        unsigned int targetPriority = active->priority;
        do {
            if (loopContext == active)
                contextBeforeActive = loopPrevContext;
            if (targetPriority == loopContext->priority)
            {
                lastEqualPriorityContext = loopContext;
                numEqualPriorityContexts++;
            }
            loopPrevContext = loopContext;
            loopContext = loopContext->pNext;
        } while (loopContext != NULL);
    }
    if (numEqualPriorityContexts <= 1 || lastEqualPriorityContext == active)
    {
        SetIRQInterruptState(priorState);
        return;
    }
    if (contextBeforeActive == NULL)
    {
        OSInitThread_UnknownRoleZeroInitializedStorage.substruct_24.firstContext = active->pNext;
    }
    else
    {
        contextBeforeActive->pNext = active->pNext;
    }
    active->pNext = lastEqualPriorityContext->pNext;
    lastEqualPriorityContext->pNext = active;
    SwitchContext();
    SetIRQInterruptState(priorState);
}
