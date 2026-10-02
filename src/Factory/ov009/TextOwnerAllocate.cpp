#include "TextOwner.h"
extern "C" void func_ov003_0215efb8(void*);
extern "C" void func_ov003_0215e6d8(void*);

// Overlay entry calls share an address with other overlays and may be
// symbolized against those overlays. Retain this externally invoked entry.
#pragma force_active on
extern "C" void func_ov009_021842a0(TextOwner* owner, SafeAllocator* allocator)
{
    if (!allocator) return;
    owner->arenas[0].CreateTypeA(allocator->Allocate(0x3800), 0x3800);
    owner->arenas[1].CreateTypeA(allocator->Allocate(0x3400), 0x3400);
    owner->arenas[2].CreateTypeA(allocator->Allocate(0x1000), 0x1000);
    owner->arenas[3].CreateTypeA(allocator->Allocate(0x2b240), 0x2b240);
    owner->arenas[4].CreateTypeA(allocator->Allocate(0xc00), 0xc00);
    owner->arenas[5].CreateTypeA(allocator->Allocate(0x2000), 0x2000);
    owner->arenas[6].CreateTypeA(allocator->Allocate(0x400), 0x400);
    owner->arenas[7].CreateTypeA(allocator->Allocate(0x800), 0x800);
    owner->arenas[8].CreateTypeA(allocator->Allocate(0x1800), 0x1800);
    owner->textBuffers = (char**)allocator->Allocate(8);
    for (int i = 0; i < 2; ++i) {
        owner->textBuffers[i] = (char*)allocator->Allocate(0x48);
        memset(owner->textBuffers[i], 0, 0x48);
    }
    owner->resourceA = allocator->Allocate(0x28);
    owner->resourceB = allocator->Allocate(0x10);
    func_ov003_0215efb8(owner->resourceA);
    func_ov003_0215e6d8(owner->resourceB);
    owner->buffers[0] = allocator->Allocate(0x54);
    owner->buffers[1] = allocator->Allocate(0xf0);
    owner->buffers[2] = allocator->Allocate(8);
    owner->buffers[3] = allocator->Allocate(0x54);
    owner->buffers[4] = allocator->Allocate(0x3e8);
    owner->buffers[5] = allocator->Allocate(8);
    if (owner->mode != 0) return;
    owner->auxiliaryArena = (SafeAllocator*)allocator->Allocate(0x14);
    owner->pairArenas = (SafeAllocator*)allocator->Allocate(0x28);
    owner->auxiliaryArena->ResetAllocatorPointer();
    for (int i = 0; i < 2; ++i)
        owner->pairArenas[i].ResetAllocatorPointer();
    owner->auxiliaryArena->CreateTypeA(allocator->Allocate(0xc000), 0xc000);
    owner->pairArenas[0].CreateTypeA(allocator->Allocate(0x3000), 0x3000);
    owner->pairArenas[1].CreateTypeA(allocator->Allocate(0x1800), 0x1800);
}
