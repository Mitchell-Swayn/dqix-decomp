#include <globaldefs.h>
ARM
#pragma optimize_for_size off
#pragma optimization_level 2
#pragma opt_common_subs off
extern "C" signed char data_020e8b7e[],data_020e8b7f[];
// Original: arm9/main @ 0x02085400; symbol: func_02085400; size: 0x74.
extern "C" int Object_TestMappedPositiveEntriesWithBit17(char* p){int i=0;int entry;while((entry=data_020e8b7e[i*2])!=-1){if(*(short*)(p+data_020e8b7f[i*2]*32+0x1ac)>0 && ((*(unsigned*)(p+entry*44+0x2f4)<<14)>>31))return 1;++i;}return 0;}
