unsigned DisableSpecificInterrupts(unsigned);
void EnableSpecificInterrupts(unsigned);
struct HPXEAllocator {
    void Free(void*);
};
// Original data: arm9/ov031 @ 0x2290d3c; symbol: data_ov031_02290d3c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" HPXEAllocator* MemoryAllocateSharedHeapOrHalt_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x0223CF70; symbol: func_ov031_0223cf70; size: 0x44.
extern "C" void WfcUtility_FreeAllocationAndClearPointer(void** p) {
    unsigned state=DisableSpecificInterrupts(1);
    void* allocation=*p;
    if(!allocation)return;
    MemoryAllocateSharedHeapOrHalt_UnknownRoleZeroInitializedStorage->Free(allocation);
    EnableSpecificInterrupts(state);
    *p=0;
}
