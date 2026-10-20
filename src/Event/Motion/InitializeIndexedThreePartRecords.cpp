#include <globaldefs.h>
ARM
#pragma optimization_level 1
// Original: arm9/ov001 @ 0x02156BA0; symbol: InitializeIndexedThreePartRecords; size: 0x74.
extern "C" void InitializeIndexedThreePartRecords(void *context) {
    int i = 0;
    while (i < 16) {
        *(int *)((char *)context + i * 56) = 0;
        char *record = (char *)context + i * 56;
        int j = 0;
        *(int *)(record + 4) = 0;
        while (j < 3) {
            *(int *)((char *)context + i * 56 + j * 4 + 8) = 0;
            *(int *)((char *)context + i * 56 + j * 4 + 20) = 0;
            *(int *)((char *)context + i * 56 + j * 4 + 32) = 0;
            *(int *)((char *)context + i * 56 + j * 4 + 44) = 0;
            ++j;
        }
        ++i;
    }
    *(int *)((char *)context + 0x380) = 0;
    *(int *)((char *)context + 0x384) = 0;
    *(int *)((char *)context + 0x388) = 0;
    *(int *)((char *)context + 0x398) = 0;
}
