#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
ARM
// Preserve the target signed-halfword multiply of the count and entry stride.
#pragma opt_propagation off
#pragma opt_foldconstants off
struct EntryArray { void* entries; int count; };
// Original: arm9/ov025 @ 0x021E20EC; symbol: func_ov025_021e20ec; size: 0x28.
// Stores an 81-entry count and allocates twelve bytes per entry.
extern "C" void BattleGrid_AllocatePathSearchNodes(EntryArray* array,SafeAllocator* allocator)
{
 short count=81;
 short stride=12;
 array->count=count;
 array->entries=allocator->Allocate(count*stride);
}
