#include <globaldefs.h>
ARM
extern "C" void Memory_ReleaseAllocatorAndSignedAllocation(void *object);
// Original: arm9/ov017 @ 0x021C031C; symbol: func_ov017_021c031c; size: 0x18.
extern "C" void Ov017_InitializeAndSetFlagByte1(void *object) {
    Memory_ReleaseAllocatorAndSignedAllocation(object);
    *((unsigned char *)object + 1) = 1;
}
