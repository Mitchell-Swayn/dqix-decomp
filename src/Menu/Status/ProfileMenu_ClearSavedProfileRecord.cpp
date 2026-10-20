#include <globaldefs.h>
ARM
extern "C" void VectorizedMemset(void *, int, unsigned int);
extern "C" void *memset(void *, int, unsigned int);
// Original: arm9/ov004 @ 0x021695FC; symbol: ClearObjectBuffersAndFlag4000; size: 0x5C.
// Zeros object header/data regions, resets byte +0x11, clears halfword bit 0x4000 at +0x12, and clears the trailing block.
extern "C" void ProfileMenu_ClearSavedProfileRecord(void *obj) {
    VectorizedMemset(obj, 0, 6);
    memset((char *)obj + 6, 0, 0xb);
    unsigned int mask = 0x4000;
    mask = 0 - mask;
    *(unsigned short *)((char *)obj + 0x12) = *(unsigned short *)((char *)obj + 0x12) & mask;
    *(unsigned char *)((char *)obj + 0x11) = 0;
    *(unsigned short *)((char *)obj + 0x12) &= ~0x4000;
    VectorizedMemset((char *)obj + 0x14, 0, 0x18);
}
