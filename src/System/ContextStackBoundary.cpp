#include "System/ProcessorContext.h"

#pragma dont_inline on
#pragma optimize_for_size off

void MarkContextStackTopUnknownSubspace(ProcessorContext *context, unsigned int size)
{
    context->stackUnknownTopSubspaceSize = size;
    if (size != 0)
    {
        *(int*)(context->stackTop + size) = STACK_UNKNOWN_SECTION_MAGIC;
    }
}

