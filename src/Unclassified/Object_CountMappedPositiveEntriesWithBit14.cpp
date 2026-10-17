#include <globaldefs.h>
ARM
#pragma optimize_for_size off
#pragma optimization_level 2
#pragma opt_common_subs off
extern "C" signed char data_020e8b48[],data_020e8b49[];
// Original: arm9/main @ 0x020852A4; symbol: func_020852a4; size: 0x74.
extern "C" int Object_CountMappedPositiveEntriesWithBit14(char* p){int count;int i=0;count=0;int entry;while((entry=data_020e8b48[i*2])!=-1){if(*(short*)(p+data_020e8b49[i*2]*32+0x1ac)>0 && ((*(unsigned*)(p+entry*44+0x2f4)<<17)>>31))++count;++i;}return count;}
