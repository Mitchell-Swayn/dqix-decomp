#include <globaldefs.h>
ARM
#include <std_library_functions.h>
extern "C" unsigned GetSubBG0ScreenBase();
extern "C" unsigned GetSubBG2ScreenBase();
struct BG { unsigned short priority:2,rest:14; };
// Original: arm9/ov023 @ 0x021DCC58; symbol: func_ov023_021dcc58; size: 0xC0.
extern "C" void Graphics_ConfigureSubBackgroundsForModeOne(unsigned char* self) {
 if(*(signed char*)(self+0x77c)!=1) return;
 *(volatile unsigned short*)0x04001008=(*(volatile unsigned short*)0x04001008&0x43)|0xf00;
 *(volatile unsigned short*)0x0400100a=(*(volatile unsigned short*)0x0400100a&0x43)|0xe00;
 ((volatile BG*)0x04001008)->priority=0;
 ((volatile BG*)0x0400100a)->priority=1;
 ((volatile BG*)0x0400100c)->priority=2;
 ((volatile BG*)0x0400100e)->priority=3;
 *(volatile unsigned*)0x04001010=0;
 *(volatile unsigned*)0x04001014=0;
 memset((void*)GetSubBG0ScreenBase(),0,0x800);
 memset((void*)GetSubBG2ScreenBase(),0,0x800);
 *(volatile unsigned*)0x04001000=(*(volatile unsigned*)0x04001000&~0x1f00)|0x1300;
}
