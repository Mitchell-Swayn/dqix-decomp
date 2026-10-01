#pragma once

#include "AllocatorBase.h"
#include "UnusedSignedAllocator.h"
#include "HMRFAllocator.h"
#include "HPXEAllocator.h"

// The order of functions in the binary is the reverse of that of
// the vtables, so any ordering is a bit silly. Here they're ordered by
// address of vtable, as that way type A is the much simpler one.

// Never used.
// vtable stored at 020e9160.
// That is, the allocation function is at 020afe04 and the
// free function is at 020afe24.
// This allocator appeals to an externally held UnusedSignedAllocator, which
// just has a linked list of equal-sized blocks and allocates by removing one.
struct AllocatorTypeUnused : public AllocatorBase // nonvirtual inheritance!
{
    UnusedSignedAllocator* pSignedAllocator;

    // Static to minimise function pointer messiness
    static void* Allocate(AllocatorBase* base, unsigned int len);
    static void Free(AllocatorBase* base, void* data);

    static const VTable s_vtable;
};

// vtable stored at 020e9168.
// That is, the allocation function is at 020afdec, and the 
// free function is at 020afe00.
// This allocator appeals to an externally held HMRFAllocator, which
// implements two-sided arena allocation on a big block.
struct AllocatorTypeA : public AllocatorBase // nonvirtual inheritance!
{
    HMRFAllocator* pHMRFAllocator; // type will be determined later
    // If this is positive, the allocation will go forwards, and if negative
    // it will go backwards. The absolute value is a power of 2 indicating
    // the alignment of each allocated item. (In practice, this always seems
    // to be +4).
    int alignmentAndDir;
    int unknown;

    // Static to minimise function pointer messiness
    static void* Allocate(AllocatorBase* base, unsigned int len);
    static void Free(AllocatorBase* base, void* data);

    static const VTable s_vtable;
};

// vtable stored at 020e9170.
// That is, the allocation function is at 020afdc8, and the 
// free function is at 020afddc.
// This allocator appeals to an externally held HPXEAllocator, which
// implements allocation by holding a linked list of free blocks and a
// linked list of used blocks and coalescing adjacent free blocks.
struct AllocatorTypeB : public AllocatorBase // nonvirtual inheritance
{
    HPXEAllocator* pHPXEAllocator;
    int alignmentAndDir;
    int unknown;

    // Static to minimise function pointer messiness
    static void* Allocate(AllocatorBase* base, unsigned int len);
    static void Free(AllocatorBase* base, void* data);

    static const VTable s_vtable;
};

// Adapter to the SDK arena/heap allocator. The heap selector is signed:
// a negative value selects the current heap in the specified arena.
// USA vtable: 0x020e9178. Underlying SDK routines remain undecompiled.
struct AllocatorTypeHeap : public AllocatorBase
{
    int heapId;
    int arenaId;

    static void* Allocate(AllocatorBase* base, unsigned int len);
    static void Free(AllocatorBase* base, void* data);
    static const VTable s_vtable;
};
