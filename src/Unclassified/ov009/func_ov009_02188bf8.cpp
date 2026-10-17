#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov009_0218aa70[];
// Original: arm9/ov009 @ 0x02188BF8; symbol: func_ov009_02188bf8; size: 0x34.
extern "C" void func_ov009_02188bf8(void *a, int index, short *outA, short *outB) {
    unsigned char row = *(unsigned char *)((char *)a + 0xDA3);
    char *entry = (char *)data_ov009_0218aa70 + row * 0x14;
    *outA = *(short *)(entry + index * 4);
    *outB = *(short *)(entry + index * 4 + 2);
}
