#include "AllocatorNodes.h"

// Only the manager prefix and the two buffer slots used here are known.
struct Ov011ManagerBuffers
{
    Ov011AllocatorNode root;
    unsigned char record[0x7c];
    void* allocation;
    unsigned int allocationSize;
    int allocationId;
    unsigned int field_a8, field_ac;
    void* secondaryAllocation;
    unsigned int secondarySize;
};

typedef char Ov011BufferLayoutCheck[sizeof(Ov011ManagerBuffers) == 0xb8 ? 1 : -1];

extern "C" {
    int func_ov011_021844a4(Ov011ManagerBuffers* manager, int id, unsigned int size)
    {
        Ov011AllocatorNode* node = func_ov011_021842c8(&manager->root, id);
        if (!node) return 1;
        manager->allocation = node->allocator.Allocate(size);
        if (!manager->allocation) return 1;
        manager->allocationId = id;
        manager->allocationSize = size;
        return 0;
    }

    void* func_ov011_021844ec(Ov011ManagerBuffers* manager)
    {
        return manager->allocation;
    }

    int func_ov011_021844f4(Ov011ManagerBuffers* manager, int id, unsigned int size)
    {
        Ov011AllocatorNode* node = func_ov011_021842c8(&manager->root, id);
        if (!node) return 0;
        manager->secondaryAllocation = node->allocator.Allocate(size);
        if (!manager->secondaryAllocation) return 0;
        manager->secondarySize = size;
        return 1;
    }

    void func_ov011_02184534(Ov011ManagerBuffers* manager, void* buffer, unsigned int size)
    {
        manager->secondaryAllocation = buffer;
        manager->secondarySize = size;
    }

    void* func_ov011_02184540(Ov011ManagerBuffers* manager)
    {
        return manager->secondaryAllocation;
    }

    unsigned int func_ov011_02184548(Ov011ManagerBuffers* manager)
    {
        return manager->secondarySize;
    }
}
