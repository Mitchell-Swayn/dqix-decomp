#include <globaldefs.h>
#include <System/IPC.h>
extern "C" {
// Original data: arm9/main @ 0x2111668; symbol: data_02111668.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern unsigned char SystemHandleResetHandshakeReply_UnknownRoleZeroInitializedStorage[];
    void System_HandleResetHandshakeReply(unsigned int,unsigned int,unsigned int);
// Original: arm9/main @ 0x020C983C; symbol: func_020c983c; size: 0x54.
    void IPC_InitializeChannelTwelveHandler(){
        if(*(unsigned short *)(SystemHandleResetHandshakeReply_UnknownRoleZeroInitializedStorage+2))return;
        *(unsigned short *)(SystemHandleResetHandshakeReply_UnknownRoleZeroInitializedStorage+2)=1;
        InitializeInterProcessorCommunication();
        while(!IsIPCCommandHandlerRegistered(12,IPCSide_Arm7)){
        }SetArm9IPCCommandHandler(12,System_HandleResetHandshakeReply);
    }
}
