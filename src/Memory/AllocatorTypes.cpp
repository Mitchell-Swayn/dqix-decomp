#include "Memory/AllocatorTypes.h"

// USA: data_020e9168
// JPN: data_020e9274
const AllocatorBase::VTable AllocatorTypeA::s_vtable = {
    &AllocatorTypeA::Allocate,
    &AllocatorTypeA::Free
};

// USA: data_020e9160
// JPN: data_020e926c
// Why does the compiler place these symbols out of order?
// If we put this at the top, it goes at 9168 and type A goes at 9160.
const AllocatorBase::VTable AllocatorTypeUnused::s_vtable = {
    &AllocatorTypeUnused::Allocate,
    &AllocatorTypeUnused::Free
};

// USA: data_020e9170
// JPN: data_020e927c
const AllocatorBase::VTable AllocatorTypeB::s_vtable = {
    &AllocatorTypeB::Allocate,
    &AllocatorTypeB::Free
};

// USA: func_020afdc8
// JPN: func_020b1894
void* AllocatorTypeB::Allocate(AllocatorBase* base, unsigned int len)
{
    AllocatorTypeB* self = static_cast<AllocatorTypeB*>(base);
    return self->pHPXEAllocator->Allocate(len, self->alignmentAndDir);
}

// USA: func_020afddc
// JPN: func_020b18a8
void AllocatorTypeB::Free(AllocatorBase* base, void* data)
{
    AllocatorTypeB* self = static_cast<AllocatorTypeB*>(base);
    self->pHPXEAllocator->Free(data);
}

// USA: func_020afdec
// JPN: func_020b18b8
void* AllocatorTypeA::Allocate(AllocatorBase* base, unsigned int len)
{
    AllocatorTypeA* self = static_cast<AllocatorTypeA*>(base);
    return self->pHMRFAllocator->Allocate(len, self->alignmentAndDir);
}

// USA: func_020afe00
// JPN: func_020b18cc
void AllocatorTypeA::Free(AllocatorBase* base, void* data)
{
    // Don't do anything
}

// USA: func_020afe04
// JPN: func_020b18d0
void* AllocatorTypeUnused::Allocate(AllocatorBase* base, unsigned int len)
{
    AllocatorTypeUnused* self = static_cast<AllocatorTypeUnused*>(base);
    if (len > self->pSignedAllocator->blockSize)
        return NULL;
    
    return self->pSignedAllocator->Allocate();
}

// USA: func_020afe24
// JPN: func_020b18f0
void AllocatorTypeUnused::Free(AllocatorBase* base, void* data)
{
    AllocatorTypeUnused* self = static_cast<AllocatorTypeUnused*>(base);
    self->pSignedAllocator->Free(data);
}
#ifndef jpn
extern "C"
{
    void* func_020c8854(int arenaId, int heapId, unsigned int len);
    void func_020c895c(int arenaId, int heapId, void* data);
}

const AllocatorBase::VTable AllocatorTypeHeap::s_vtable = {
    &AllocatorTypeHeap::Allocate,
    &AllocatorTypeHeap::Free
};

// USA: 0x020afe34
void* AllocatorTypeHeap::Allocate(AllocatorBase* base, unsigned int len)
{
    AllocatorTypeHeap* self = static_cast<AllocatorTypeHeap*>(base);
    return func_020c8854(self->arenaId, self->heapId, len);
}

// USA: 0x020afe50
void AllocatorTypeHeap::Free(AllocatorBase* base, void* data)
{
    AllocatorTypeHeap* self = static_cast<AllocatorTypeHeap*>(base);
    func_020c895c(self->arenaId, self->heapId, data);
}
#endif
