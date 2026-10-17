#include <globaldefs.h>
extern "C" unsigned int data_02105254;
extern "C" void Graphics_UpdateSelectedBackgroundTileBuffer(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
ARM
#pragma optimize_for_size off
// Original: arm9/main @ 0x0203BCB8; symbol: func_0203bcb8; size: 0x50.
extern "C" void Graphics_SubmitObjectBackgroundParameters(unsigned char *p, unsigned int a, unsigned int b) {
    Graphics_UpdateSelectedBackgroundTileBuffer((unsigned int)&data_02105254,*(unsigned short *)(p+0x16),*(unsigned short *)(p+0x18),a,b,*(unsigned int *)(p+8),p[0],p[1],*(unsigned short *)(p+0x14));
}
