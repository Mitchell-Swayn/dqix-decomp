#include <globaldefs.h>
#pragma optimization_level 4
#pragma optimize_for_size off
extern "C" int ReadSignedByteValueForNonnegativeHalfwordKey(void*,int);extern "C" int Object_FindValueInSelectedOrAllKeyGroups(void*,int,int);
// Original: arm9/main @ 0x02086BF4; symbol: func_02086bf4; size: 0x58.
extern "C" ARM int Object_SumKeyValuesAcrossThreeContainers(unsigned char* p,int id){if(id<0)return 0;short a=0;a+=ReadSignedByteValueForNonnegativeHalfwordKey(p,id);short sum=Object_FindValueInSelectedOrAllKeyGroups(p+0x1d4,id,9)+a;return (short)(ReadSignedByteValueForNonnegativeHalfwordKey(p+0xe04,id)+sum);}
