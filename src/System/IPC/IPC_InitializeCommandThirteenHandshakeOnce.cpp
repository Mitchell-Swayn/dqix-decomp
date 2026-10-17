#include <globaldefs.h>
#include "System/IPC.h"
#include "System/ProcessorContext.h"
extern "C" unsigned data_02112160[];
extern "C" ProcessorContext data_02112240;
extern "C" void ClearGlobalWordAndGenerateLockOwnerId();
extern "C" void IPC_HandleChannelThirteenCompletion(unsigned,unsigned,unsigned);
extern "C" void InvokeOnceCallbackForReason17(unsigned,unsigned,unsigned);
extern "C" void Object_ClearElement1(unsigned,unsigned,unsigned);
extern "C" void func_020d16b0();
extern "C" void InitializeGlobalProcessorContextOnce(ProcessorContext*);
extern "C" void WriteEnableAndConditionalInterruptMask(int);
// Original: arm9/main @ 0x020D15FC; symbol: func_020d15fc; size: 0xB4.
extern "C" ARM void IPC_InitializeCommandThirteenHandshakeOnce()
{
    if(data_02112160[2])return;
    data_02112160[2]=1;
    ClearGlobalWordAndGenerateLockOwnerId();
    data_02112160[3]=0;
    InitializeInterProcessorCommunication();
    while(!IsIPCCommandHandlerRegistered(13,IPCSide_Arm7))
    {
    }SetArm9IPCCommandHandler(13,IPC_HandleChannelThirteenCompletion);
    func_020d16b0();
    SetArm9IPCCommandHandler(13,0);
    SetArm9IPCCommandHandler(13,InvokeOnceCallbackForReason17);
    data_02112160[6]=0;
    InitializeGlobalProcessorContextOnce(&data_02112240);
    SetArm9IPCCommandHandler(17,Object_ClearElement1);
    WriteEnableAndConditionalInterruptMask(0);
}
