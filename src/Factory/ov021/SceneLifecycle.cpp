#include "Overlay21Context.h"
#include "Resource/Brightness.h"

extern "C" {
    extern AllocatorUnion data_02114e20;
    void func_02012da4(AllocatorUnion* allocator, void* allocation);
}

// Main calls these addresses through ambiguous overlay relocations. They are
// runtime entrypoints even when no relocation names the ov021 symbols directly.
#pragma force_active on

extern "C" void func_ov021_0218b5a0(Overlay21Context* context)
{
    // InitializeBrightnessState accesses only the shared brightness prefix.
    InitializeBrightnessState(reinterpret_cast<GameResources*>(context));
    context->sceneAllocator.ResetAllocatorPointer();
    context->scene = 0;
    context->exitRequested = 0;
}

extern "C" void func_ov021_0218b5c4(Overlay21Context* context)
{
    SignedAllocatorHeader* allocation = context->sceneAllocator.GetSignedAllocator();
    context->sceneAllocator.Destroy();
    func_02012da4(&data_02114e20, allocation);
    context->scene = 0;
}

#pragma force_active reset
