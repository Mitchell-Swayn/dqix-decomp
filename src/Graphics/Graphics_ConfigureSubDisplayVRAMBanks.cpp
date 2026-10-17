#include <globaldefs.h>
ARM
#include <System/VRAM.h>
extern "C" char* ReadGlobalValueAt020FB3F0();extern "C" void Graphics_WriteSubDisplayModeLowBits(int),SubBackground1_ConfigureControlBits(int,int,int,int,int),Graphics_WriteSubBackgroundControlBits(int,int,int,int,int);
struct Mode {unsigned char mode:4,rest:4;};
// Original: arm9/main @ 0x02020838; symbol: func_02020838; size: 0x130.
extern "C" void Graphics_ConfigureSubDisplayVRAMBanks(){
 char* state=*(char**)(ReadGlobalValueAt020FB3F0()+8);DisableSubBGVRAMBanks();DisableSubObjVRAMBanks();Graphics_WriteSubDisplayModeLowBits(0);MapVRAMBanksToSubBG(128);volatile unsigned* display=(volatile unsigned*)0x04001000;
 if(!((Mode*)(state+12))->mode){*display=(*display&0xffffe0ff)|0x1100;SubBackground1_ConfigureControlBits(0,0,15,0,0);Graphics_WriteSubBackgroundControlBits(0,0,16,0,0);}else{*display=(*display&0xffffe0ff)|0x1300;SubBackground1_ConfigureControlBits(1,0,14,0,0);Graphics_WriteSubBackgroundControlBits(0,0,13,0,0);}MapVRAMBanksToSubObj(256);*display=(*display&0xffcfffef)|16;
 volatile unsigned short* bg=(volatile unsigned short*)display;bg[4]=(bg[4]&~3)|1;bg[5]=(bg[5]&~3)|2;bg[6]&=~3;bg[7]=(bg[7]&~3)|3;
}
