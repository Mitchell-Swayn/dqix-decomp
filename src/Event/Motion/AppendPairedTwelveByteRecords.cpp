#include <globaldefs.h>
ARM
extern "C" void *memcpy(void *, const void *, unsigned int);
// Original: arm9/ov001 @ 0x0215758C; symbol: func_ov001_0215758c; size: 0x60.
extern "C" int AppendPairedTwelveByteRecords(void *self, int a0, int a1, int a2, int b0, int b1, int b2) {
    if (*(int *)((unsigned char *)self + 0x180) >= 0x10) return 1;
    memcpy((unsigned char *)self + *(int *)((unsigned char *)self + 0x180) * 0xc, &a0, 0xc);
    memcpy((unsigned char *)self + 0xc0 + *(int *)((unsigned char *)self + 0x180) * 0xc, &b0, 0xc);
    *(int *)((unsigned char *)self + 0x180) += 1;
    return 0;
}
