#include <globaldefs.h>
extern "C" int WriteOutputWhenNonNull();extern "C" void(*data_020f2298)();extern "C" int MapModeToCommandSelectorOrInvalidFFFF(int,int(*)(),int*);
#pragma optimization_level 4
#pragma optimize_for_size off
// Original: arm9/main @ 0x020CE614; symbol: func_020ce614; size: 0x34.
extern "C" ARM int IPC_RunSynchronousCommandAndReturnReply(int a){int value;int result=MapModeToCommandSelectorOrInvalidFFFF(a,WriteOutputWhenNonNull,&value);if(result)return result;data_020f2298();return value;}
