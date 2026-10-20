#include <globaldefs.h>
ARM
extern "C" void *memcpy(void *, const void *, unsigned int);
// Original: arm9/ov001 @ 0x02157964; symbol: func_ov001_02157964; size: 0x48.
extern "C" int Memory_AppendTwelveByteEntry(unsigned char *pool, unsigned int a, unsigned int b, unsigned int c) {
    int count = *(int *)(pool + 0xC4);
    if (count >= 16) {
        return 1;
    }
    memcpy(pool + count * 0xC, &a, 0xC);
    int next = *(int *)(pool + 0xC4) + 1;
    *(int *)(pool + 0xC4) = next;
    return 0;
}
