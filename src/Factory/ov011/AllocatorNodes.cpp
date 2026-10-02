#include "AllocatorNodes.h"

#pragma dont_inline on

// Initialize the shared allocator-node prefix without clearing allocator state
// that ResetAllocatorPointer deliberately leaves untouched.
void func_ov011_021842a0(Ov011AllocatorNode* node)
{
    node->id = 0;
    node->allocator.ResetAllocatorPointer();
    node->nextSibling = 0;
    node->firstChild = 0;
}

Ov011AllocatorNode* func_ov011_021842c8(Ov011AllocatorNode* node, int id)
{
    if (node->id == id) return node;
    Ov011AllocatorNode* found = 0;
    if (node->nextSibling) found = func_ov011_021842c8(node->nextSibling, id);
    if (found) return found;
    if (node->firstChild) found = func_ov011_021842c8(node->firstChild, id);
    return found;
}

void func_ov011_02184324(Ov011AllocatorNode* node, Ov011AllocatorNode* sibling)
{
    Ov011AllocatorNode* last = node->nextSibling;
    if (last)
    {
        while (last->nextSibling) last = last->nextSibling;
        last->nextSibling = sibling;
    }
    else node->nextSibling = sibling;
}

void func_ov011_02184354(Ov011AllocatorNode* node, Ov011AllocatorNode* child)
{
    if (!node->firstChild)
    {
        node->firstChild = child;
        return;
    }
    func_ov011_02184324(node->firstChild, child);
}
