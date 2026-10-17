#include <globaldefs.h>
ARM
#pragma optimize_for_size off
extern "C" char data_020f10f8[];
extern "C" char data_020f1118[];
extern "C" char data_020f1108[];
extern "C" void InitializeFiveAnimationRangesAndPairs(char*);
// Original: arm9/main @ 0x0208B508; symbol: func_0208b508; size: 0x40.
extern "C" char* Object_InitializeFiveStringFieldsAndState(char* p){
    *(char**)(p+4)=data_020f10f8;
    *(char**)(p+0x24)=data_020f1118;
    *(char**)(p+0x40)=data_020f1118;
    *(char**)(p+0x5c)=data_020f1108;
    *(char**)(p+0x78)=data_020f1118;
    InitializeFiveAnimationRangesAndPairs(p);
    return p;
}
