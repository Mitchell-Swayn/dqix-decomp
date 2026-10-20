#include <globaldefs.h>
ARM
extern "C" void Inn_ReleaseStayDialogResources(unsigned int);
extern "C" void Overlay_DestroyAllocatorAndFreeSignedAllocation(void *);
// Original: arm9/ov017 @ 0x021BAEB0; symbol: Memory_DestroyOptionalAllocationAndSetFlag1; size: 0x2C.
// Destroys the optional allocation at +0x20 when present, runs allocator cleanup, and sets byte +1 to one.
extern "C" void Memory_DestroyOptionalAllocationAndSetFlag1(void *obj) {
    unsigned int allocation = *(unsigned int *)((char *)obj + 0x20);
    if (allocation) Inn_ReleaseStayDialogResources(allocation);
    Overlay_DestroyAllocatorAndFreeSignedAllocation(obj);
    *((unsigned char *)obj + 1) = 1;
}
