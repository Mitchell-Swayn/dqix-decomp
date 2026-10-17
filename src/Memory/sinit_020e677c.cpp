#include <Memory/SafeAllocator.h>

#pragma define_section init ".init" RX

extern "C" SafeAllocator* Allocator_ResetPointerAndReturnSelf(SafeAllocator* p);
extern "C" char data_0214e4c8[];

// Global constructor thunk for the allocator object at data_0214e4c8.
// Original: arm9/main @ 0x020E677C; symbol: __sinit_020e677c; size: 0x14.
extern "C" __declspec(section "init") void __sinit_020e677c()
{
    Allocator_ResetPointerAndReturnSelf((SafeAllocator*)data_0214e4c8);
}
