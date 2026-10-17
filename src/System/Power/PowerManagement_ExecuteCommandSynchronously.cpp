#include <globaldefs.h>
extern "C" int WriteOutputWhenNonNull();extern "C" int IPC_SendTwoWordCommandAndStoreCallbackState(int,int,int,int(*)(),int*);extern "C" void (*data_020f2298)();
#pragma optimization_level 4
#pragma optimize_for_size off
// Original: arm9/main @ 0x020CE56C; symbol: func_020ce56c; size: 0x44.
extern "C" ARM int PowerManagement_ExecuteCommandSynchronously(int a,int b,int c){int result;int status=IPC_SendTwoWordCommandAndStoreCallbackState(a,b,c,WriteOutputWhenNonNull,&result);if(status==0){data_020f2298();return result;}return status;}
