#include <globaldefs.h>
ARM
#pragma opt_lifetimes off
#pragma optimize_for_size off
#pragma optimization_level 2
#pragma opt_common_subs off
#include <Memory/SafeAllocator.h>
struct Pair { unsigned first, second; };
struct Array { unsigned char pad, count; unsigned char unused[6]; Pair* pairs; };
// Original: arm9/main @ 0x02028754; symbol: func_02028754; size: 0x60.
extern "C" void AllocateAndClearPairArray(Array* array, SafeAllocator* allocator, unsigned char count)
{
    array->pairs=(Pair*)allocator->Allocate(count*8);
    if (!array->pairs) { array->count=0; return; }
    array->count=count;
    for (int i=0; i<array->count; ++i) {
        Pair* entry=&array->pairs[i];
        entry->second=0;
        entry->first=0;
    }
}
