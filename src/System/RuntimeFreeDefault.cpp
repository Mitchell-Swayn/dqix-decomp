#include "Memory/ArenaHeap.h"

#pragma optimize_for_size off

extern "C" void func_0200ab10(void* pointer)
{
    FreeArenaHeap(0, -1, pointer);
}
