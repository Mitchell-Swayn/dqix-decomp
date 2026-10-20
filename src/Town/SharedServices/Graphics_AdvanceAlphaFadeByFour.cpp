#include <globaldefs.h>
ARM
#include <System/ColorEffects.h>
struct GameResources;
extern "C" GameResources* GameResources_GetInstance();
extern "C" void GameResources_ClearSecondaryFlags(int self, unsigned int mask);
// Original: arm9/ov003 @ 0x0216FBA0; symbol: func_ov003_0216fba0; size: 0xB8.
extern "C" void Graphics_AdvanceAlphaFadeByFour(unsigned char *self) {
    GameResources_ClearSecondaryFlags((int)GameResources_GetInstance(),0xc8e);
    volatile unsigned short *background = (volatile unsigned short *)0x04000008;
    background[0] = (background[0] & ~3) | 3;
    background[1] = background[1] & ~3;
    background[2] = (background[2] & ~3) | 1;
    background[3] = (background[3] & ~3) | 2;
    ColorEffect_ConfigureAlphaBlend(0x04000050,24,1,self[0x3b],16-self[0x3b]);
    *(volatile unsigned *)0x04000000 = (*(volatile unsigned *)0x04000000 & ~0x1f00) | 0xf00;
    self[0x3b] -= 4;
    if (self[0x3b] == 0) { self[1] = 7; self[2] = 0; }
}
