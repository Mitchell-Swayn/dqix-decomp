#include <globaldefs.h>
ARM

extern "C" unsigned char data_ov031_02290d40[];

// Original: arm9/ov031 @ 0x0223D3D4; symbol: func_ov031_0223d3d4; size: 0x40.
extern "C" int Unclassified_HasRequestedStateFlags(unsigned int mask) {
    int blocked = *(volatile unsigned short *)0x027fffa8 & 0x8000;
    if ((blocked >> 15) != 0) {
        return 0;
    }
    void *state = *(void **)(data_ov031_02290d40 + 4);
    unsigned short flags = *(unsigned short *)((char *)state + 0x36);
    return (mask & flags) == mask;
}
