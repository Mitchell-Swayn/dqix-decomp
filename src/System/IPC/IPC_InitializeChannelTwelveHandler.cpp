#include <globaldefs.h>
#include <System/IPC.h>
extern "C" {
    extern unsigned char data_02111668[];
    void AcceptIPCCommand10OrPanic(unsigned int,unsigned int,unsigned int);
// Original: arm9/main @ 0x020C983C; symbol: func_020c983c; size: 0x54.
    void IPC_InitializeChannelTwelveHandler(){
        if(*(unsigned short *)(data_02111668+2))return;
        *(unsigned short *)(data_02111668+2)=1;
        InitializeInterProcessorCommunication();
        while(!IsIPCCommandHandlerRegistered(12,IPCSide_Arm7)){
        }SetArm9IPCCommandHandler(12,AcceptIPCCommand10OrPanic);
    }
}
