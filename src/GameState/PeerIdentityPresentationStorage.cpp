#include "GameState/PeerIdentityTransfer.h"
#include "System/Memory.h"

#if defined(usa)

typedef char PeerPresentationAllocatorsOffsetCheck[
    offsetof(PeerIdentityPresentation, allocators_) == 0x200 ? 1 : -1];
typedef char PeerPresentationAllocatorExtentCheck[
    sizeof(((PeerIdentityPresentation*)0)->allocators_) == 0x78 ? 1 : -1];
typedef char PeerPresentationAllocationSizeCheck[
    sizeof(PeerIdentityPresentation) == 0xecc ? 1 : -1];

extern "C" void func_ov008_02189228(GameStateStoredIdentity* record)
{
    VectorizedMemset(record->identity_.bytes_, 0, 6);
    memset(record->unknown_06_, 0, 11);
    record->counter_ = 0;
    record->partialTicks_ = 0;
    record->active_ = 0;
    VectorizedMemset(record->payload_, 0, 24);
}

extern "C" void func_ov008_02189284(PeerIdentityPresentation* presentation,
                                     SafeAllocator* allocator)
{
    presentation->allocators_[0].CreateTypeA(allocator->Allocate(0xa000), 0xa000);
    presentation->allocators_[1].CreateTypeA(allocator->Allocate(0xc00), 0xc00);
    presentation->allocators_[2].CreateTypeA(allocator->Allocate(0x5c00), 0x5c00);
    presentation->allocators_[3].CreateTypeA(allocator->Allocate(0x800), 0x800);
    presentation->allocators_[4].CreateTypeA(allocator->Allocate(0x2400), 0x2400);
    presentation->allocators_[5].CreateTypeA(allocator->Allocate(0x5400), 0x5400);
    presentation->unknown_1f8_ = allocator->Allocate(0x140);
    presentation->unknown_1f4_ = allocator->Allocate(0x54);
    presentation->unknown_1fc_ = allocator->Allocate(8);
}

#endif
