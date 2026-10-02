#pragma once

#include "Memory/SafeAllocator.h"

// The manager and its descendants share this prefix. The links form a
// sibling chain at 0x18 and a child chain at 0x1c; search visits siblings
// before children. Callers allocate the records from the parent allocator.
struct Ov011AllocatorNode
{
    int id;
    SafeAllocator allocator;
    Ov011AllocatorNode* nextSibling;
    Ov011AllocatorNode* firstChild;
};

typedef char Ov011AllocatorNodeSizeCheck[sizeof(Ov011AllocatorNode) == 0x20 ? 1 : -1];

extern "C" {
    void func_ov011_021842a0(Ov011AllocatorNode* node);
    Ov011AllocatorNode* func_ov011_021842c8(Ov011AllocatorNode* node, int id);
    void func_ov011_02184324(Ov011AllocatorNode* node, Ov011AllocatorNode* sibling);
    void func_ov011_02184354(Ov011AllocatorNode* node, Ov011AllocatorNode* child);
    void func_ov011_021845c8(Ov011AllocatorNode* node, void* buffer, unsigned int size);
}
