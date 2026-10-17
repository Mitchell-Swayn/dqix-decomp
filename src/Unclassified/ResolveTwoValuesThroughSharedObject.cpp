#include <globaldefs.h>
ARM
extern "C" unsigned ResolveEncodedOffsetOrFallback(unsigned,unsigned,int);
// Original: arm9/main @ 0x020E5204; symbol: func_020e5204; size: 0x38.
extern "C" int ResolveTwoValuesThroughSharedObject(unsigned object,unsigned* values){values[0]=ResolveEncodedOffsetOrFallback(object,values[0],0);values[1]=ResolveEncodedOffsetOrFallback(object,values[1],0);return 1;}
