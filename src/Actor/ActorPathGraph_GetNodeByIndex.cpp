#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x02028430; symbol: func_02028430; size: 0x30.
extern "C" unsigned char* ActorPathGraph_GetNodeByIndex(unsigned char* p,int i) { if(i<0 || p[2]<=i)return 0;unsigned char* base=*(unsigned char**)(p+4);return base ? base+i*16 : 0; }
