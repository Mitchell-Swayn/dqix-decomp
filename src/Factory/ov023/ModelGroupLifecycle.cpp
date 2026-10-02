#include "ModelGroup.h"

#pragma dont_inline on
extern "C" void func_ov023_021e61a0(Ov23ModelGroup* group);

// Backing allocation sizes for the ten per-model type-A allocators.
extern "C" const unsigned int data_ov023_021fd6d4[10] = {
    0x5400, 0x2000, 0x1400, 0x1c00, 0x0c00,
    0x1c00, 0x1c00, 0x23e8, 0x1b58, 0x1400
};

extern "C" void func_ov023_021e4e8c(Ov23ModelGroup* group)
{
    group->flag_c11 = 0;
    for (int i = 0; i < 10; ++i) {
        group->objects[i].Initialize();
        group->allocators[i].ResetAllocatorPointer();
    }
    group->auxiliaryAllocator.ResetAllocatorPointer();
    group->unknown_c10 = 0;
    for (int i = 0; i < 12; ++i)
        group->taskIDs[i] = -1;
    group->loading_c12 = 0;
    group->flag_c15 = 0;
    group->unknown_c18 = 0;
    group->enabled_c14 = 1;
}

extern "C" void func_ov023_021e4f18(Ov23ModelGroup* group)
{
    func_ov023_021e61a0(group);
    for (int i = 0; i < 10; ++i) {
        group->objects[i].Initialize();
        group->allocators[i].Destroy();
    }
    group->auxiliaryAllocator.Destroy();
}

extern "C" void func_ov023_021e4f64(Ov23ModelGroup* group, SafeAllocator* parent)
{
    for (int i = 0; i < 10; ++i) {
        unsigned int size = data_ov023_021fd6d4[i];
        void* buffer = parent->Allocate(size);
        group->allocators[i].CreateTypeA(buffer, size);
    }
    void* buffer = parent->Allocate(0x1000);
    group->auxiliaryAllocator.CreateTypeA(buffer, 0x1000);
}
