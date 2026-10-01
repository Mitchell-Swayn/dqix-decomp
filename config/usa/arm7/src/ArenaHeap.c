/* Blocks reserve a 0x20-byte header; size includes that header. Only the first
 * three header words participate in these list operations. */
typedef struct ArenaHeapBlock {
    struct ArenaHeapBlock *previous;
    struct ArenaHeapBlock *next;
    int size;
} ArenaHeapBlock;

typedef struct ArenaHeap {
    int size;
    ArenaHeapBlock *freeBlocks;
    ArenaHeapBlock *usedBlocks;
} ArenaHeap;

typedef struct ArenaHeapInfo {
    int currentHeap;
    int heapCount;
    void *arenaStart;
    void *arenaEnd;
    ArenaHeap *heaps;
} ArenaHeapInfo;
extern int ARM7_DisableIRQInterrupts(void);
extern void ARM7_SetIRQInterruptState(int state);
// USA: 0x037fcfd4
ArenaHeapBlock* ARM7_RemoveArenaHeapBlock(ArenaHeapBlock* head, ArenaHeapBlock* block)
{
    if (block->next != 0)
        block->next->previous = block->previous;
    if (block->previous == 0)
        head = block->next;
    else
        block->previous->next = block->next;
    return head;
}

// USA: 0x037fcffc
// Free blocks are address-ordered; merge adjacent blocks on both sides.
ArenaHeapBlock* ARM7_InsertFreeArenaHeapBlock(ArenaHeapBlock* head, ArenaHeapBlock* block)
{
    ArenaHeapBlock* previous = 0;
    ArenaHeapBlock* next = head;
    while (next != 0)
    {
        if (block <= next) break;
        previous = next;
        next = next->next;
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

// Existing ARM7 descriptor table remains a binary dependency.
extern ArenaHeapInfo* ARM7_g_arenaHeapInfo[9];

// USA: 0x037fd0a4
void* ARM7_AllocateArenaHeap(int arenaId, int heapId, unsigned int len)
{
    // Declaration order preserves the original compiler's register allocation.
    ArenaHeapInfo* info;
    ArenaHeap* heap;
    ArenaHeapBlock* block;
    int interruptState;
    unsigned int remaining;

    interruptState = ARM7_DisableIRQInterrupts();
    info = ARM7_g_arenaHeapInfo[arenaId];
    if (info == 0)
    {
        ARM7_SetIRQInterruptState(interruptState);
        return 0;
    }
    if (heapId < 0)
        heapId = info->currentHeap;
    heap = &info->heaps[heapId];
    block = heap->freeBlocks;
    len = (len + 0x3f) & ~0x1f;
    while (block != 0)
    {
        if ((int)len <= block->size) break;
        block = block->next;
    }
    if (block == 0)
    {
        ARM7_SetIRQInterruptState(interruptState);
        return 0;
    }
    remaining = block->size - len;
    if (remaining < 0x40)
        heap->freeBlocks = ARM7_RemoveArenaHeapBlock(heap->freeBlocks, block);
    else
    {
        ArenaHeapBlock* rest;
        block->size = len;
        rest = (ArenaHeapBlock*)((char*)block + len);
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
    {
        ArenaHeapBlock *head = heap->usedBlocks;
        block->next = head;
        block->previous = 0;
        if (head != 0) head->previous = block;
        heap->usedBlocks = block;
    }
    ARM7_SetIRQInterruptState(interruptState);
    return (char*)block + 0x20;
}

// USA: 0x037fd1b4
void ARM7_FreeArenaHeap(int arenaId, int heapId, void* data)
{
    // Declaration order preserves the original compiler's register allocation.
    ArenaHeapInfo* info;
    ArenaHeap* heap;
    int interruptState;
    ArenaHeapBlock* block;

    interruptState = ARM7_DisableIRQInterrupts();
    info = ARM7_g_arenaHeapInfo[arenaId];
    if (heapId < 0)
        heapId = info->currentHeap;
    heap = &info->heaps[heapId];
    block = (ArenaHeapBlock*)((char*)data - 0x20);
    heap->usedBlocks = ARM7_RemoveArenaHeapBlock(heap->usedBlocks, block);
    heap->freeBlocks = ARM7_InsertFreeArenaHeapBlock(heap->freeBlocks, block);
    ARM7_SetIRQInterruptState(interruptState);
}
int ARM7_SetCurrentHeap(int arena, int heapId) {
    ArenaHeapInfo *info;
    int oldHeap;
    int state = ARM7_DisableIRQInterrupts();
    info = ARM7_g_arenaHeapInfo[arena];
    oldHeap = info->currentHeap;
    info->currentHeap = heapId;
    ARM7_SetIRQInterruptState(state);
    return oldHeap;
}

void *ARM7_InitializeHeapArena(int arena, void *start, void *end, int maxHeaps) {
    ArenaHeapInfo *info = (ArenaHeapInfo *)start;
    int state = ARM7_DisableIRQInterrupts();
    int tableBytes;
    int index;
    ARM7_g_arenaHeapInfo[arena] = info;
    info->heaps = (ArenaHeap *)(info + 1);
    tableBytes = maxHeaps * sizeof(ArenaHeap);
    info->heapCount = maxHeaps;
    for (index = 0; index < info->heapCount; index++) {
        ArenaHeap *heap = &info->heaps[index];
        heap->size = -1;
        heap->usedBlocks = 0;
        heap->freeBlocks = 0;
    }
    info->currentHeap = -1;
    info->arenaStart = (void *)(((unsigned int)info->heaps + tableBytes + 31) & ~31);
    info->arenaEnd = (void *)((unsigned int)end & ~31);
    ARM7_SetIRQInterruptState(state);
    return info->arenaStart;
}

int ARM7_CreateHeap(int arena, void *start, void *end) {
    ArenaHeapInfo *info;
    int count;
    int heapId;
    int state = ARM7_DisableIRQInterrupts();
    info = ARM7_g_arenaHeapInfo[arena];
    start = (void *)(((unsigned int)start + 31) & ~31);
    count = info->heapCount;
    end = (void *)((unsigned int)end & ~31);
    for (heapId = 0; heapId < count; heapId++) {
        ArenaHeap *heap = &info->heaps[heapId];
        if (heap->size < 0) {
            ArenaHeapBlock *block = (ArenaHeapBlock *)start;
            heap->size = (char *)end - (char *)start;
            block->previous = 0;
            block->next = 0;
            block->size = heap->size;
            heap->freeBlocks = block;
            heap->usedBlocks = 0;
            ARM7_SetIRQInterruptState(state);
            return heapId;
        }
    }
    ARM7_SetIRQInterruptState(state);
    return -1;
}
