#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" int InitializeRequestAndDispatchCommandZero(void*,unsigned,void*,void*);
// Original: arm9/main @ 0x020D4F7C; symbol: func_020d4f7c; size: 0x10.
extern "C" int WirelessCommand_InvokeFourArgumentRequestWithZeroMode(void* context,unsigned value,void* input){return InitializeRequestAndDispatchCommandZero(context,value,input,0);}
