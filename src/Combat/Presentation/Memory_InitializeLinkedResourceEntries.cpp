#include <globaldefs.h>
ARM
extern "C" void *memset(void *, int, unsigned int);
// Original: arm9/ov025 @ 0x021EED58; symbol: func_ov025_021eed58; size: 0x58.
extern "C" void Memory_InitializeLinkedResourceEntries(unsigned char *p) {
    memset(p, 0, 0xe0);
    *(unsigned int *)(p + 0xe0) = 0;
    *(unsigned int *)(p + 0xe4) = 0;
    for (int i = 0; i < 7; i++)
        *(unsigned char **)(p + i * 0x1c + 0x18) = p + (i + 1) * 0x1c;
    *(unsigned char **)(p + 0xe4) = p;
    *(unsigned int *)(p + 0xdc) = 0;
}
