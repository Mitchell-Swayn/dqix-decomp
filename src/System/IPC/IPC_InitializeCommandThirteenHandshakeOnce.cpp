#include <globaldefs.h>
#include "System/IPC.h"
#include "System/ProcessorContext.h"
// Original data: arm9/main @ 0x2112160; symbol: data_02112160.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned CartridgeHandleRemovalNotification_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x2112240; symbol: data_02112240.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 232 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" ProcessorContext IPCInitializeCommandThirteenHandshakeOnce_UnknownRoleZeroInitializedStorage;
extern "C" void ClearGlobalWordAndGenerateLockOwnerId();
extern "C" void IPC_HandleChannelThirteenCompletion(unsigned,unsigned,unsigned);
extern "C" void Cartridge_HandleRemovalNotification(unsigned,unsigned,unsigned);
extern "C" void Cartridge_ClearPendingCommandOnReply(unsigned,unsigned,unsigned);
extern "C" void Cartridge_InitializeModuleInfoAndNotifyArm7();
extern "C" void InitializeGlobalProcessorContextOnce(ProcessorContext*);
extern "C" void WriteEnableAndConditionalInterruptMask(int);
// Original: arm9/main @ 0x020D15FC; symbol: func_020d15fc; size: 0xB4.
extern "C" ARM void IPC_InitializeCommandThirteenHandshakeOnce()
{
    if(CartridgeHandleRemovalNotification_UnknownRoleZeroInitializedStorage[2])return;
    CartridgeHandleRemovalNotification_UnknownRoleZeroInitializedStorage[2]=1;
    ClearGlobalWordAndGenerateLockOwnerId();
    CartridgeHandleRemovalNotification_UnknownRoleZeroInitializedStorage[3]=0;
    InitializeInterProcessorCommunication();
    while(!IsIPCCommandHandlerRegistered(13,IPCSide_Arm7))
    {
    }SetArm9IPCCommandHandler(13,IPC_HandleChannelThirteenCompletion);
    Cartridge_InitializeModuleInfoAndNotifyArm7();
    SetArm9IPCCommandHandler(13,0);
    SetArm9IPCCommandHandler(13,Cartridge_HandleRemovalNotification);
    CartridgeHandleRemovalNotification_UnknownRoleZeroInitializedStorage[6]=0;
    InitializeGlobalProcessorContextOnce(&IPCInitializeCommandThirteenHandshakeOnce_UnknownRoleZeroInitializedStorage);
    SetArm9IPCCommandHandler(17,Cartridge_ClearPendingCommandOnReply);
    WriteEnableAndConditionalInterruptMask(0);
}
