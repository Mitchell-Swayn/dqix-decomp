#include <globaldefs.h>
ARM
extern "C" void Graphics_ResetSharedBuffersAndReleaseStateAllocator(void *object, unsigned value);
// Original: arm9/ov017 @ 0x021ACA00; symbol: func_ov017_021aca00; size: 0x14.
extern "C" void FieldBookshelf_CancelReadAndReleaseResources(void *object) {
    *(unsigned char *)((char *)object + 1) = 1;
    Graphics_ResetSharedBuffersAndReleaseStateAllocator(object, 1);
}
