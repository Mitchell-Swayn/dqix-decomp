#include <globaldefs.h>
extern "C" {
int GameResources_GetInstance(unsigned int);
// Original: arm9/main @ 0x020DB3A8; symbol: func_020db3a8; size: 0x4C.
ARM int DisplayOverlay_UseAlternateSpritePalette(unsigned char *param_1) {
    unsigned int value = param_1[0x54];
    if (value == 1) {
        value = (*(volatile unsigned short *)0x04000304 & 0x8000) >> 15;
        if (value == 1) return 1;
    }
    int ptr = GameResources_GetInstance(value);
    unsigned int inner = *(unsigned int *)(ptr + 0x3718);
    return *(unsigned char *)(inner + 3) != 0;
}
}
