#include <globaldefs.h>
ARM
 
// Original: arm9/ov000 @ 0x0217FBF4; symbol: func_ov000_0217fbf4; size: 0xd0.
// Enables the requested party panel, or all eligible panels while clearing dead members commands.
extern "C" void BattleMenu_EnablePartyCommandInput(unsigned char* menu,int member) {
 if(member<0) {
  for(int i=0;i<4;i++) {
   unsigned char* panel=menu+0x958+(((signed char*)menu)+i)[0x6c]*0x448;
   if(*(int*)(panel+0x4c)>=0) {
    panel[0x24]|=1;
    if(*(short*)(panel+0xc)==0) {
     (panel+((signed char*)panel)[0x18])[0x10]=0x64;
     panel[0x24]&=~4;
     panel[0x24]&=~1;
    }
   }
  }
 }else {
  for(int j=0;j<4;j++) {
   unsigned char* panel=menu+0x958+(((signed char*)menu)+j)[0x6c]*0x448;
   if(member==*(int*)(panel+0x4c)){panel[0x24]|=1;return;}
  }
 }
}
