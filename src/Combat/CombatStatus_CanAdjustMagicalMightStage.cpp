#include <globaldefs.h>
ARM
struct Flags {signed int low:12;signed int mode:3;signed int high:17;};
// Original: arm9/main @ 0x02087B3C; symbol: func_02087b3c; size: 0x54.
extern "C" int CombatStatus_CanAdjustMagicalMightStage(unsigned char* p,int flag) { if(*(unsigned int*)(p+20)&1)return 0;if(flag==0) { if(((Flags*)(p+88))->mode<2)return 1; }else if(-2<((Flags*)(p+88))->mode)return 1;return 0; }
