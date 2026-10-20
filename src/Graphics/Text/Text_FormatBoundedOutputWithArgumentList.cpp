#include <globaldefs.h>
ARM
#pragma optimization_level 4
// Formatting tail veneer preserves all four arguments.
extern "C" int StringWriter_FormatVarArgs(char*,int,const char*,void*);
// Original: arm9/main @ 0x020C7198; symbol: func_020c7198; size: 0xC.
extern "C" int Text_FormatBoundedOutputWithArgumentList(char* out,int capacity,const char* format,void* args){return StringWriter_FormatVarArgs(out,capacity,format,args);}
