#include <globaldefs.h>
ARM
#pragma optimize_for_size off
#pragma optimization_level 2
#pragma opt_common_subs off
extern "C" signed char data_020e8b36[],data_020e8b37[];
// Original: arm9/main @ 0x0208555C; symbol: func_0208555c; size: 0x74.
extern "C" int Object_TestMappedPositiveEntriesWithBit21(char* p){int i=0;int entry;while((entry=data_020e8b36[i*2])!=-1){if(*(short*)(p+data_020e8b37[i*2]*32+0x1ac)>0 && ((*(unsigned*)(p+entry*44+0x2f4)<<10)>>31))return 1;++i;}return 0;}
