#include <globaldefs.h>
#pragma optimization_level 4
// Original: arm9/main @ 0x020DFBC0; symbol: func_020dfbc0; size: 0x14.
extern "C" ARM unsigned WordPair_ComputeEightTimesComponentSum(const unsigned short *p) { int a=p[1],b=p[0]; return (unsigned)(b*8)+(unsigned)(a*8); }
