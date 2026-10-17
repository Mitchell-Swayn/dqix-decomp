#include <globaldefs.h>
THUMB
extern "C" void Overlay_FillThreeGlobalWords(void *);
extern "C" unsigned int data_ov031_0224f670[];

// Original: arm9/ov031 @ 0x02222AF0; symbol: func_ov031_02222af0; size: 0x1C.
extern "C" void func_ov031_02222af0(void) {
    unsigned char buffer[0x0c];
    Overlay_FillThreeGlobalWords(buffer);
    ((void (*)(void *))data_ov031_0224f670[0x7c / 4])(buffer);
}
