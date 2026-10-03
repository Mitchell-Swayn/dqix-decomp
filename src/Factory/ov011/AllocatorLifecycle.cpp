#include "AllocatorNodes.h"

#pragma dont_inline on
extern "C" {
    void func_ov023_021f6844(void*, int);
    void func_ov011_02184374(void*);
    void func_0207df50(void*);
    void func_0207dfc8(void*, void*);

    Ov011AllocatorNode* func_ov011_021845f4(Ov011AllocatorNode* manager)
    {
        return manager;
    }

    Ov011AllocatorNode* func_ov011_021845f8(Ov011AllocatorNode* manager, int id)
    {
        return func_ov011_021842c8(manager, id);
    }

    // Visit siblings before children, then release the subsystem's ID entry
    // and destroy the embedded allocator. Node storage belongs to its parent.
    void func_ov011_02184604(void* manager, Ov011AllocatorNode* node)
    {
        if (!node) return;
        func_ov011_02184604(manager, node->nextSibling);
        func_ov011_02184604(manager, node->firstChild);
        func_ov023_021f6844((unsigned char*)manager + 0x118, node->id);
        node->allocator.Destroy();
    }

    void func_ov011_02184640(void* manager, void* resource)
    {
        func_ov011_02184374((unsigned char*)manager + 0x20);
        func_0207df50(resource);
        func_0207dfc8(resource, (unsigned char*)manager + 0x24);
    }
}