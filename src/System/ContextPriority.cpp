#include "System/ProcessorContext.h"

// Original: arm9/main @ 0x020C7B38; symbol: _Z18GetContextPriorityP16ProcessorContext; size: 0x8.
unsigned int GetContextPriority(ProcessorContext* context)
{
    return context->priority;
}

