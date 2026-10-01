#include "Memory/ArenaHeap.h"
#include "System/Interrupts.h"

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

// Arena initialization and the storage backing this table remain undecompiled.
extern ArenaHeapInfo* data_02111564[];

// USA: 0x020c8854
void* AllocateArenaHeap(int arenaId, int heapId, unsigned int len)
{
    // Declaration order preserves the original compiler's register allocation.
    ArenaHeapInfo* info;
    ArenaHeap* heap;
    ArenaHeapBlock* block;
    int interruptState;

    interruptState = DisableIRQInterrupts();
    info = data_02111564[arenaId];
    if (info == 0)
    {
        SetIRQInterruptState(interruptState);
        return 0;
    }
    if (heapId < 0)
        heapId = info->currentHeap;
    heap = &info->heaps[heapId];
    block = heap->freeBlocks;
    len = (len + 0x3f) & ~0x1f;
    if (block != 0)
    {
        do
        {
            if ((int)len <= block->size)
                break;
            block = block->next;
        } while (block != 0);
    }
    if (block == 0)
    {
        SetIRQInterruptState(interruptState);
        return 0;
    }
    unsigned int remaining = block->size - len;
    if (remaining < 0x40)
        heap->freeBlocks = RemoveArenaHeapBlock(heap->freeBlocks, block);
    else
    {
        block->size = len;
        ArenaHeapBlock* rest = (ArenaHeapBlock*)((char*)block + len);
        rest->size = remaining;
        rest->previous = block->previous;
        rest->next = block->next;
        if (rest->next != 0)
            rest->next->previous = rest;
        if (rest->previous != 0)
            rest->previous->next = rest;
        else
            heap->freeBlocks = rest;
    }
    heap->usedBlocks = PrependArenaHeapBlock(heap->usedBlocks, block);
    SetIRQInterruptState(interruptState);
    return (char*)block + 0x20;
}

// USA: 0x020c895c
void FreeArenaHeap(int arenaId, int heapId, void* data)
{
    // Declaration order preserves the original compiler's register allocation.
    ArenaHeapInfo* info;
    ArenaHeap* heap;
    int interruptState;
    ArenaHeapBlock* block;

    interruptState = DisableIRQInterrupts();
    info = data_02111564[arenaId];
    if (heapId < 0)
        heapId = info->currentHeap;
    heap = &info->heaps[heapId];
    block = (ArenaHeapBlock*)((char*)data - 0x20);
    heap->usedBlocks = RemoveArenaHeapBlock(heap->usedBlocks, block);
    heap->freeBlocks = InsertFreeArenaHeapBlock(heap->freeBlocks, block);
    SetIRQInterruptState(interruptState);
}
