#include <globaldefs.h>
extern "C" int LoadFlagSelectedResourceStagesAndReturnStatus(unsigned,int,unsigned,int,int);
// Original: arm9/main @ 0x020BDC98; symbol: func_020bdc98; size: 0x2C.
extern "C" ARM bool TestResourceLoadWithAllByteFlagsAndModeOne(unsigned a,unsigned b){return LoadFlagSelectedResourceStagesAndReturnStatus(a,255,b,1,0)==0;}
