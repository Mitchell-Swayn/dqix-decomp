#include "Memory/ArenaHeap.h"

#pragma optimize_for_size off

// Original: arm9/main @ 0x0200AB10; symbol: func_0200ab10; size: 0x18.
extern "C" void RuntimeFreeDefault_FreeDefaultArenaHeapBlock(void* pointer)
{
    FreeArenaHeap(0, -1, pointer);
}
