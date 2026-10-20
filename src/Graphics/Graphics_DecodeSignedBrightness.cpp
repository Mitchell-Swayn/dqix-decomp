#include <globaldefs.h>
#pragma optimization_level 4
#pragma optimize_for_size off
ARM
// Original: arm9/main @ 0x020C39C8; symbol: func_020c39c8; size: 0x44.
extern "C" int Graphics_DecodeSignedBrightness(volatile unsigned short* value) {
 unsigned short type=*value&0xc000;
 if(type==0)return 0;
 if(type==0x4000)return *value&31;
 if(type==0x8000)return -(*value&31);
 return 0;
}
