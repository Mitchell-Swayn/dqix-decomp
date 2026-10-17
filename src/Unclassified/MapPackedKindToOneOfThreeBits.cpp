#include <globaldefs.h>
ARM
struct Flags{unsigned low:14;unsigned value:2;unsigned high:16;};
// Original: arm9/main @ 0x020DD768; symbol: func_020dd768; size: 0x44.
extern "C" unsigned MapPackedKindToOneOfThreeBits(unsigned char* p){if(!p)return 0;unsigned value=((Flags*)(p+8))->value;unsigned result=0;switch(value){case 0:result|=4;break;case 1:result|=1;break;case 2:result|=2;break;}return result;}
