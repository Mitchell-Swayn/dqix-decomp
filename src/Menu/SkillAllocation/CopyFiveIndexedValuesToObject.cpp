#include <globaldefs.h>
ARM
extern "C" unsigned char *GameObject_GetLinkedIndexedState(void *);
// Original: arm9/ov013 @ 0x02184C8C; symbol: func_ov013_02184c8c; size: 0x64.
extern "C" void CopyFiveIndexedValuesToObject(void *self, void *object) {
    if (object == 0 || *((unsigned char *)self + 0x664) == 0) return;
    unsigned char *output = GameObject_GetLinkedIndexedState(object);
    *(unsigned short *)(output + 0x564) = *(unsigned *)((unsigned char *)self + 0x66c);
    for (int i = 0; i < 5; ++i) {
        unsigned char index = *((unsigned char *)self + 0x6a9 + i);
        unsigned value = *(unsigned *)((unsigned char *)self + 0x674 + i * 4) +
                         *(unsigned *)((unsigned char *)self + 0x688 + i * 4);
        unsigned char *slot = output + index;
        slot[0x464] = (unsigned char)value;
    }
}
