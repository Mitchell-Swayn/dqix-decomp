#include <globaldefs.h>
ARM
extern "C" void *memset(void *, int, unsigned int);
// Original: arm9/ov025 @ 0x021DCD98; symbol: func_ov025_021dcd98; size: 0x50.
extern "C" void Object_ResetFieldsAndFillEightBytes(unsigned char *object) {
    int zero = 0;
    object[0x6F00] = 0;
    object[0x6EFF] = 0;
    memset(object + 0x6FBA, zero - 1, 8);
    *(unsigned short *)(object + 0x6FC2) = 0;
    *(unsigned int *)(object + 0x6FC4) = 0;
    *(unsigned int *)(object + 0x6FC8) = 0;
    *(unsigned int *)(object + 0x6FCC) = 0;
    *(unsigned int *)(object + 0x6FD0) = 0;
}
