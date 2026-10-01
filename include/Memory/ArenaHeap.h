#pragma once

// Header of a block managed by the arena heap allocator. Allocations reserve
// 0x20 bytes for the header; size includes that header and is aligned to 0x20.
struct ArenaHeapBlock
{
    ArenaHeapBlock* previous;
    ArenaHeapBlock* next;
    int size;
};

ArenaHeapBlock* PrependArenaHeapBlock(ArenaHeapBlock* head, ArenaHeapBlock* block);
ArenaHeapBlock* RemoveArenaHeapBlock(ArenaHeapBlock* head, ArenaHeapBlock* block);
ArenaHeapBlock* InsertFreeArenaHeapBlock(ArenaHeapBlock* head, ArenaHeapBlock* block);

struct ArenaHeap
{
    int size;
    ArenaHeapBlock* freeBlocks;
    ArenaHeapBlock* usedBlocks;
};

struct ArenaHeapInfo
{
    int currentHeap;
    int unknown_4;
    void* unknown_8;
    void* unknown_c;
    ArenaHeap* heaps;
};

void* AllocateArenaHeap(int arenaId, int heapId, unsigned int len);
void FreeArenaHeap(int arenaId, int heapId, void* data);
