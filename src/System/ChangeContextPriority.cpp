#include "System/ProcessorContext.h"
#include "System/Interrupts.h"
#include <globaldefs.h>
#include <asmhacks.h>

#pragma dont_inline on
#pragma optimize_for_size off

// Original: arm9/main @ 0x020C7A90; symbol: _Z21ChangeContextPriorityP16ProcessorContextj; size: 0xA8.
bool ChangeContextPriority(ProcessorContext* context, unsigned int newPriority)
{
    ProcessorContext* loopContext = data_021112e0.substruct_24.firstContext;
    ProcessorContext* previousContext = NULL;
    int priorState = DisableIRQInterrupts();

    for (; loopContext != NULL && loopContext != context; loopContext = loopContext->pNext)
        previousContext = loopContext;

    if (loopContext == NULL || loopContext == &data_02111314) {
        SetIRQInterruptState(priorState);
        return false;
    }

    if (loopContext->priority != newPriority) {
        if (previousContext != NULL)
            previousContext->pNext = context->pNext;
        else {
            DECLARE_ASM_NOP();
            data_021112e0.substruct_24.firstContext = context->pNext;
        }
        context->priority = newPriority;
        InsertContextIntoGlobalList(context);
        SwitchContext();
    }
    SetIRQInterruptState(priorState);
    return true;
}
