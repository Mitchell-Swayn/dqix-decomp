/* Original diagnostic text, ordered as it appears in the cartridge.
 * Each member's length includes NUL and the observed zero alignment padding.
 * The aggregate preserves string order; every byte is verified after linking. */
typedef struct {
    char heapArray[48];
    char heapIndex[68];
    char heapSize[44];
    char allocatedHead[84];
    char cellRange[84];
    char cellAlignment[60];
    char cellLinks[76];
    char minimumSize[56];
    char sizeAlignment[64];
    char runningTotal[60];
    char freeHead[72];
    char freeOrder[100];
    char finalTotal[48];
} HeapDiagnostics;

const HeapDiagnostics ARM7_HeapDiagnostics = {
    "OS_CheckHeap: Failed heapInfo->heapArray in %d\n",
    "OS_CheckHeap: Failed 0 <= heap && heap < heapInfo->numHeaps in %d\n",
    "OS_CheckHeap: Failed 0 <= hd->size in %d\n",
    "OS_CheckHeap: Failed hd->allocated == NULL || hd->allocated->prev == NULL in %d\n",
    "OS_CheckHeap: Failed InRange(cell, heapInfo->arenaStart, heapInfo->arenaEnd) in %d\n",
    "OS_CheckHeap: Failed OFFSET(cell, ALIGNMENT) == 0 in %d\n",
    "OS_CheckHeap: Failed cell->next == NULL || cell->next->prev == cell in %d\n",
    "OS_CheckHeap: Failed MINOBJSIZE <= cell->size in %d\n",
    "OS_CheckHeap: Failed OFFSET(cell->size, ALIGNMENT) == 0 in %d\n",
    "OS_CheckHeap: Failed 0 < total && total <= hd->size in %d\n",
    "OS_CheckHeap: Failed hd->free == NULL || hd->free->prev == NULL in %d\n",
    "OS_CheckHeap: Failed cell->next == NULL || (char *)cell + cell->size < (char *)cell->next in %d\n",
    "OS_CheckHeap: Failed total == hd->size in %d\n"
};
