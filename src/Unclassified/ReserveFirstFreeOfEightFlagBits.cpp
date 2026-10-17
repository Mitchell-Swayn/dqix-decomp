#include <globaldefs.h>
ARM
#pragma optimize_for_size off
struct State{unsigned unknown;volatile unsigned flags;};extern "C" State data_0210f3c0;
// Original: arm9/main @ 0x020BBEB0; symbol: func_020bbeb0; size: 0x48.
extern "C" int ReserveFirstFreeOfEightFlagBits(){unsigned bit=1;int i=0;unsigned used=data_0210f3c0.flags;do{if(!(used&bit)){data_0210f3c0.flags|=bit;return i;}++i;bit<<=1;}while(i<8);return -1;}
