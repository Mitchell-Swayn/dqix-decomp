#include <globaldefs.h>
ARM
extern "C" void Graphics_ResetOwnerResourcesAndDestroyAllocators(unsigned char *);
extern "C" void Field_ReleaseChurchServiceMenu(void *);
// Original: arm9/ov017 @ 0x021BABF8; symbol: Graphics_ResetOwnerResourcesAndSetFlag1; size: 0x2C.
// If owner field +0x1C is nonzero, resets owner resources; then runs allocator cleanup and sets byte +1 to one.
extern "C" int Graphics_ResetOwnerResourcesAndSetFlag1(unsigned char *p) {
    unsigned char *resources = *(unsigned char **)(p + 0x1c);
    if (resources) Graphics_ResetOwnerResourcesAndDestroyAllocators(resources);
    Field_ReleaseChurchServiceMenu(p);
    p[1] = 1;
    return 1;
}
