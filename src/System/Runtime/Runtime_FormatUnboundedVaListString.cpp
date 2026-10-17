#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" int Text_FormatBoundedOutputWithArgumentList(char*,unsigned,const char*,void*);
// Original: arm9/main @ 0x020C7158; symbol: func_020c7158; size: 0x18.
extern "C" int Runtime_FormatUnboundedVaListString(char* output,const char* format,void* arguments){return Text_FormatBoundedOutputWithArgumentList(output,0x7fffffff,format,arguments);}
