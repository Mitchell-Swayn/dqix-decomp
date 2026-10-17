#include <globaldefs.h>
ARM
#include <System/VRAM.h>
extern "C" void Graphics_WriteSubDisplayModeLowBits(int);extern "C" void SubBackground1_ConfigureControlBits(int,int,int,int,int);extern "C" void Graphics_WriteSubBackgroundControlBits(int,int,int,int,int);
// Original: arm9/main @ 0x020209D0; symbol: func_020209d0; size: 0xD0.
extern "C" void Graphics_ConfigureSubDisplayForThreeBackgrounds(){DisableSubObjVRAMBanks();DisableSubBGVRAMBanks();Graphics_WriteSubDisplayModeLowBits(0);volatile unsigned* display=(volatile unsigned*)0x04001000;*display=(*display&~0x1f00)|0x1300;MapVRAMBanksToSubObj(0x100);*display=(*display&0xffcfffef)|0x10;MapVRAMBanksToSubBG(0x80);SubBackground1_ConfigureControlBits(0,0,14,0,0);Graphics_WriteSubBackgroundControlBits(0,0,15,0,0);volatile unsigned short* bg=(volatile unsigned short*)0x04001008;bg[0]=(bg[0]&~3)|1;bg[1]=bg[1]&~3;bg[2]=(bg[2]&~3)|2;bg[3]=(bg[3]&~3)|3;}
