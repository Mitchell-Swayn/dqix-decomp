#include "AllocatorNodes.h"
#include "AllocatorScript.h"
#include "Resource/GameResources.h"

extern "C" {
    Ov011AllocatorNode* func_ov017_021b2164();
    Ov011AllocatorNode* func_ov011_021845f4(Ov011AllocatorNode* manager);
    int func_ov011_02184c30(Ov011ScriptArgument* argument);
    int func_ov011_02184de4(Ov011ScriptArgument* arguments, int count);
}

// Create a sibling allocator using all remaining space in one of the three
// GameResources allocator slots selected by the first argument.
int func_ov011_02184de4(Ov011ScriptArgument* arguments, int count)
{
    Ov011AllocatorNode* node;
    unsigned int size;
    void* buffer;
    GameResources* resources = func_ov017_0218b5b0();
    Ov011AllocatorNode* root = func_ov011_021845f4(func_ov017_021b2164());
    SafeAllocator* allocator;
    int selector = func_ov011_02184c30(arguments);
    int id = func_ov011_02184c30(arguments + 1);
    if (func_ov011_021842c8(root, id)) return 0;

    allocator = 0;
    switch (selector)
    {
    case 0: allocator = &resources->allocator_array_38[0]; break;
    case 1: allocator = &resources->allocator_array_38[7]; break;
    case 2: allocator = &resources->allocator_array_38[5]; break;
    }
    if (!allocator) return 0;
    node = (Ov011AllocatorNode*)allocator->Allocate(sizeof(Ov011AllocatorNode));
    if (!node) return 0;
    func_ov011_021842a0(node);
    node->id = id;
    size = allocator->GetMaxPossibleAllocation();
    buffer = allocator->Allocate(size);
    if (!buffer) return 0;
    node->allocator.CreateTypeB(buffer, size, 4);
    func_ov011_02184324(root, node);
    return 1;
}

