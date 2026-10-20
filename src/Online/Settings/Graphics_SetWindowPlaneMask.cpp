#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x0223CD30; symbol: func_ov031_0223cd30; size: 0x16C.
extern "C" void Graphics_SetWindowPlaneMask(int engine,unsigned window,unsigned mask,int effect) {
 switch(window) {
 case 0:
  if(engine==1) { unsigned v=(*(volatile unsigned short*)0x4001048 & ~0x3f)|mask; if(effect) v|=0x20; *(volatile unsigned short*)0x4001048=v; }
  else { unsigned v=(*(volatile unsigned short*)0x4000048 & ~0x3f)|mask; if(effect) v|=0x20; *(volatile unsigned short*)0x4000048=v; }
  break;
 case 1:
  if(engine==1) { unsigned v=(*(volatile unsigned short*)0x4001048 & ~0x3f00)|(mask<<8); if(effect) v|=0x2000; *(volatile unsigned short*)0x4001048=v; }
  else { unsigned v=(*(volatile unsigned short*)0x4000048 & ~0x3f00)|(mask<<8); if(effect) v|=0x2000; *(volatile unsigned short*)0x4000048=v; }
  break;
 case 2:
  if(engine==1) { unsigned v=(*(volatile unsigned short*)0x400104a & ~0x3f00)|(mask<<8); if(effect) v|=0x2000; *(volatile unsigned short*)0x400104a=v; }
  else { unsigned v=(*(volatile unsigned short*)0x400004a & ~0x3f00)|(mask<<8); if(effect) v|=0x2000; *(volatile unsigned short*)0x400004a=v; }
  break;
 case 3:
  if(engine==1) { unsigned v=(*(volatile unsigned short*)0x400104a & ~0x3f)|mask; if(effect) v|=0x20; *(volatile unsigned short*)0x400104a=v; }
  else { unsigned v=(*(volatile unsigned short*)0x400004a & ~0x3f)|mask; if(effect) v|=0x20; *(volatile unsigned short*)0x400004a=v; }
  break;
 }
}
