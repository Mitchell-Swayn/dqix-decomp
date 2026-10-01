#include "Memory/ArenaHeap.h"

// USA: 0x020c8768
ArenaHeapBlock* PrependArenaHeapBlock(ArenaHeapBlock* head, ArenaHeapBlock* block)
{
    block->next = head;
    block->previous = 0;
    if (head != 0)
        head->previous = block;
    return block;
}

// USA: 0x020c8784
ArenaHeapBlock* RemoveArenaHeapBlock(ArenaHeapBlock* head, ArenaHeapBlock* block)
{
    if (block->next != 0)
        block->next->previous = block->previous;
    if (block->previous == 0)
        head = block->next;
    else
        block->previous->next = block->next;
    return head;
}

// USA: 0x020c87ac
// Free blocks are address-ordered; merge adjacent blocks on both sides.
ArenaHeapBlock* InsertFreeArenaHeapBlock(ArenaHeapBlock* head, ArenaHeapBlock* block)
{
    ArenaHeapBlock* previous = 0;
    ArenaHeapBlock* next = head;
    if (next != 0)
    {
        do
        {
            if (block <= next)
                break;
            previous = next;
            next = next->next;
        } while (next != 0);
    }
    block->previous = previous;
    block->next = next;
    if (next != 0)
    {
        next->previous = block;
        if ((char*)block + block->size == (char*)next)
        {
            block->size += next->size;
            next = next->next;
            block->next = next;
            if (next != 0)
                next->previous = block;
        }
    }
    if (previous != 0)
    {
        previous->next = block;
        if ((char*)previous + previous->size == (char*)block)
        {
            previous->size += block->size;
            previous->next = next;
            if (next != 0)
                next->previous = previous;
        }
    }
    else
        head = block;
    return head;
}
