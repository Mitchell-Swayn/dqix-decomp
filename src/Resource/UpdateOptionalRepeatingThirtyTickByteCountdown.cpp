#include <globaldefs.h>
#include <Resource/Script.h>
ARM
// Original: arm9/main @ 0x020658AC; symbol: func_020658ac; size: 0x74.
extern "C" void UpdateOptionalRepeatingThirtyTickByteCountdown(unsigned char* p,unsigned amount){if(p[0x19c1]&&!p[0x19c0]){p[0x19c0]=1;p[0x195d]=30;}if(!p[0x19c0])return;unsigned old=p[0x195d];if(old<=amount){if(p[0x19c1])p[0x195d]=old+(30-amount);else{p[0x195d]=0;p[0x19c0]=0;}return;}p[0x195d]=old-amount;}
