#include <globaldefs.h>
extern "C" void Party_BuildStatComparison(unsigned,unsigned,unsigned,int);extern "C" void Party_ReadStatComparisonPair(unsigned,unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x020DDAF4; symbol: func_020ddaf4; size: 0x2C.
extern "C" ARM void Party_BuildAndReadStatComparison(unsigned a,unsigned b,unsigned c,unsigned d,unsigned e,unsigned f){Party_BuildStatComparison(a,b,c,0);Party_ReadStatComparisonPair(a,d,e,f);}
