#include <globaldefs.h>
ARM
extern "C" void Graphics_DestroyPanelResourcesAndAllocators(void *);
extern "C" void Memory_DestroySignedSafeAllocator(void *);
// Original: arm9/ov017 @ 0x021C1238; symbol: Memory_ReleaseOptionalField1CAndSetFlag1; size: 0x2C.
// Calls the handler for a nonzero pointer at +0x1C, destroys the signed safe allocator, and sets byte +1 to one.
extern "C" void RecordsScreen_DestroyPanelSession(unsigned char *p) {
    void *value = *(void **)(p + 0x1c);
    if (value != 0) Graphics_DestroyPanelResourcesAndAllocators(value);
    Memory_DestroySignedSafeAllocator(p);
    p[1] = 1;
}
