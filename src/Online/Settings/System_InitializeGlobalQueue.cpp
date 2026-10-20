#include <globaldefs.h>
ARM
extern "C" void *Memory_AllocateZeroedBlock(int count, int elementSize);
// Original: arm9/ov031 @ 0x0223D858; symbol: func_ov031_0223d858; size: 0x2C.
extern "C" void System_InitializeGlobalQueue(void) {
    unsigned *queue = (unsigned *)Memory_AllocateZeroedBlock(0x10, 4);
    queue[0] = 0;
    queue[1] = (unsigned)(queue + 2);
    queue[2] = (unsigned)queue;
    queue[3] = 0;
}
