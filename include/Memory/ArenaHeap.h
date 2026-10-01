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

// Descriptor layout corroborated by the matched ARM7 heap initializer
// (0x037fd254): descriptor count, aligned arena bounds, then descriptor array.
struct ArenaHeapInfo
{
    int currentHeap;
    int heapCount;
    void* arenaStart;
    void* arenaEnd;
    ArenaHeap* heaps;
};

void* AllocateArenaHeap(int arenaId, int heapId, unsigned int len);
void FreeArenaHeap(int arenaId, int heapId, void* data);

extern ArenaHeapInfo* g_arenaHeapInfo[9];
