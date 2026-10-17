#include <globaldefs.h>
ARM
typedef void(*Handler)();extern "C" Handler data_020f2298;extern "C" void IPC_WaitForPendingCommandCompletion();extern "C" void IPC_WaitForPendingCommandsAndRetryWithDelays();extern "C" void IPC_SendTwoWordCommandAndStoreCallbackState(int,int,int,void*,void*);
// Original: arm9/main @ 0x020CE704; symbol: func_020ce704; size: 0x54.
extern "C" void IPC_TemporarilyReplaceWaitHandlerAndSendCommandFourteen(void* a,void* b){Handler saved=data_020f2298;data_020f2298=IPC_WaitForPendingCommandCompletion;IPC_WaitForPendingCommandsAndRetryWithDelays();data_020f2298=saved;IPC_SendTwoWordCommandAndStoreCallbackState(14,0,0,a,b);}
