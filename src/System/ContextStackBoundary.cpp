#include "System/ProcessorContext.h"

#pragma dont_inline on
#pragma optimize_for_size off

// Original: arm9/main @ 0x020C7A74; symbol: _Z34MarkContextStackTopUnknownSubspaceP16ProcessorContextj; size: 0x1C.
void MarkContextStackTopUnknownSubspace(ProcessorContext *context, unsigned int size)
{
    context->stackUnknownTopSubspaceSize = size;
    if (size != 0)
    {
        *(int*)(context->stackTop + size) = STACK_UNKNOWN_SECTION_MAGIC;
    }
}

