unsigned DisableSpecificInterrupts(unsigned);
void EnableSpecificInterrupts(unsigned);
struct HPXEAllocator {
    void Free(void*);
};
extern "C" HPXEAllocator* data_ov031_02290d3c;
// Original: arm9/ov031 @ 0x0223CF70; symbol: func_ov031_0223cf70; size: 0x44.
extern "C" void FreeSharedAllocationAndClearFlagWithInterruptMask(void** p) {
    unsigned state=DisableSpecificInterrupts(1);
    void* allocation=*p;
    if(!allocation)return;
    data_ov031_02290d3c->Free(allocation);
    EnableSpecificInterrupts(state);
    *p=0;
}
