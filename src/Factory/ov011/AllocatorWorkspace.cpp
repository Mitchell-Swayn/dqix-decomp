#include "AllocatorNodes.h"

// Only offsets used by these lifecycle functions are described here.
struct Ov011LifecycleManager
{
    Ov011AllocatorNode root;
    unsigned char record[0x7c];
    unsigned char bufferSlots[0xc];
    unsigned int workspaceId, workspaceParameter;
    unsigned char secondaryBuffer[8];
    unsigned char workspace[0x60];
    unsigned char subsystem[0x74];
};

typedef char Ov011LifecycleLayoutCheck[sizeof(Ov011LifecycleManager) == 0x18c ? 1 : -1];

#pragma dont_inline on
extern "C" {
    void func_020c9be0();
    void func_ov017_021d4c04(void*, unsigned int, void*, unsigned int, void*, unsigned int);
    void func_ov011_021888ec(void*);

    void func_ov011_02184550(Ov011LifecycleManager* manager, SafeAllocator* allocator,
                            unsigned int id, unsigned int parameter)
    {
        manager->workspaceId = id;
        manager->workspaceParameter = parameter;
        void* entries = allocator->Allocate(0x400);
        void* storage = allocator->Allocate(0x1800);
        if (!entries || !storage) func_020c9be0();
        func_ov017_021d4c04(manager->workspace, manager->workspaceId, entries, 0x80, storage, 0x200);
        func_ov011_021888ec(manager->workspace);
    }
}