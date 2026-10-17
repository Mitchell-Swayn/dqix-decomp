#include <globaldefs.h>
ARM
extern "C" void* memcpy(void*, const void*, unsigned);
extern "C" void* func_ov001_02158dcc(void* queue);
// Original: arm9/ov001 @ 0x02158EFC; symbol: func_ov001_02158efc; size: 0x34.
extern "C" void System_QueueAndCopyThreeWords(void* queue, unsigned first, unsigned second, unsigned third) {
    unsigned* entry = (unsigned*)func_ov001_02158dcc(queue);
    if (entry == 0) return;
    entry[0] = 1;
    memcpy(entry + 1, &first, 12);
}
