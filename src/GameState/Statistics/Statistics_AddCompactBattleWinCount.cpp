#include <globaldefs.h>
ARM
struct Flags {unsigned int low:16;unsigned int high:16;};
// Original: arm9/main @ 0x020A0110; symbol: func_020a0110; size: 0x30.
extern "C" void Statistics_AddCompactBattleWinCount(unsigned char* p,unsigned int add) { Flags* f=(Flags*)(p+0x10);unsigned int value=add+f->high;if(value>0xffff)value=0xffff;f->high=value; }
