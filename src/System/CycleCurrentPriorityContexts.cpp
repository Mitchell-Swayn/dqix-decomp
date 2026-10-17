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
    ProcessorContext* active = data_021112e0.substruct_24.activeContext;
    priorState = DisableIRQInterrupts();
    ProcessorContext* loopPrevContext = NULL;
    ProcessorContext* loopContext = data_021112e0.substruct_24.firstContext;
    if (data_021112e0.substruct_24.firstContext != NULL)
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
        data_021112e0.substruct_24.firstContext = active->pNext;
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
