#include <globaldefs.h>
#pragma optimization_level 4
#pragma optimize_for_size off
// Original: arm9/main @ 0x020C54A4; symbol: func_020c54a4; size: 0x58.
extern "C" ARM void Graphics_WriteHalfwordRegister35CAndDisplayControl(int enabled,int mode,int offset,unsigned short color){volatile unsigned short* blend=(volatile unsigned short*)0x0400035c;if(enabled!=0){*blend=color;volatile unsigned short* display=(volatile unsigned short*)0x04000060;unsigned value=(offset<<8)|(mode<<6)|0x80;*display=(*display&~0x3f40)|value;return;} {volatile unsigned short* display=(volatile unsigned short*)0x04000060;*display=*display&0xcf7f;}}
