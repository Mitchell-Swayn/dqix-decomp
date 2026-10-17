#include <globaldefs.h>
ARM
#pragma optimize_for_size off
#pragma optimization_level 4
extern "C" int IPC_TemporarilyReplaceWaitHandlerAndSendCommandFourteen(void(*)(),int*);extern "C" void WriteOutputWhenNonNull();extern "C" void IPC_PollPendingReplyWhenInterruptsUnavailable();extern "C" void WaitForPendingArm7CommandAndServiceIRQMode();extern "C" void (*data_020f2298)();
// Original: arm9/main @ 0x020CE758; symbol: func_020ce758; size: 0x4C.
extern "C" int PowerManagement_RunSynchronousOperationWithTemporaryCallback(){int out;int result=IPC_TemporarilyReplaceWaitHandlerAndSendCommandFourteen(WriteOutputWhenNonNull,&out);if(result)return result;void (*callback)()=(void(*)())IPC_PollPendingReplyWhenInterruptsUnavailable;data_020f2298=callback;callback();data_020f2298=WaitForPendingArm7CommandAndServiceIRQMode;return out;}
