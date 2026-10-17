#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void RunUpdateForRequestedOrCurrentTickCount(void*,int);
// Original: arm9/main @ 0x0204359C; symbol: func_0204359c; size: 0xC.
extern "C" void Object_ConfigureTextCountThroughEmbeddedHandler(void* object,int count){RunUpdateForRequestedOrCurrentTickCount(object,count);}
