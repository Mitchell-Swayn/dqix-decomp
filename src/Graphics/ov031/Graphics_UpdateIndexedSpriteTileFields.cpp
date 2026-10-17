#include <globaldefs.h>
ARM
extern "C" char * volatile data_ov031_02290c8c[];
// Original: arm9/ov031 @ 0x0222C5D4; symbol: func_ov031_0222c5d4; size: 0x8C.
extern "C" void Graphics_UpdateIndexedSpriteTileFields(int index, int slot) {
    char *state = data_ov031_02290c8c[1];
    if (index >= *(unsigned char*)(state + 0x51)) return;
    int offset = index * 42;
    unsigned short *first = *(unsigned short**)(state + 0x10 + slot * 4);
    char *record = *(char**)state + offset;
    first[2] = (first[2] & ~0x3ff) | *(unsigned short*)(state + 0x42 + *(unsigned char*)(record + 0x28) * 2);
    state = data_ov031_02290c8c[1];
    record = *(char**)state + offset;
    unsigned short *second = *(unsigned short**)(state + 0x24 + slot * 4);
    second[2] = (second[2] & ~0x3ff) | *(unsigned short*)(state + 0x48 + *(unsigned short*)(record + 0x26) * 2);
}
