#include <globaldefs.h>
ARM
extern "C" void *Memory_AppendFreeNodeToPool(void *);
extern "C" void *memcpy(void *, const void *, unsigned int);
// Original: arm9/ov001 @ 0x0215A608; symbol: func_ov001_0215a608; size: 0x4C.
extern "C" void Pool_AllocateTypedCoordinateRecord(void *pool, int x, int y, int z, int value) {
    void *node = Memory_AppendFreeNodeToPool(pool);
    if (node != 0) {
        if (value <= 0) *(unsigned *)node = 0x10;
        else *(unsigned *)node = 0x11;
        memcpy((unsigned char *)node + 4, &x, 0xc);
        *(int *)((unsigned char *)node + 0x10) = value;
    }
}
