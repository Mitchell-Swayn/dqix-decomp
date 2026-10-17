#include <globaldefs.h>
extern "C" int WriteOutputWhenNonNull();extern "C" void(*data_020f2298)();extern "C" int PowerManagement_SetSelectedDeviceEnabled(int,int,int(*)(),int*);
#pragma optimization_level 4
#pragma optimize_for_size off
// Original: arm9/main @ 0x020CE6D0; symbol: func_020ce6d0; size: 0x34.
extern "C" ARM int WaitForOperationAndReturnCallbackValue(int a,int b){int value;int result=PowerManagement_SetSelectedDeviceEnabled(a,b,WriteOutputWhenNonNull,&value);if(result)return result;data_020f2298();return value;}
