#include <globaldefs.h>
#include <System/IPC.h>
extern "C" {
    extern unsigned int data_02112140[];
    void IPC_HandleCommandSeventeenOnceAndInvokeCallback(unsigned int,unsigned int,unsigned int);
// Original: arm9/main @ 0x020D1118; symbol: func_020d1118; size: 0x2C.
    void InitializeIPCAndRegisterCommand14(){
        InitializeInterProcessorCommunication();
        SetArm9IPCCommandHandler(14,IPC_HandleCommandSeventeenOnceAndInvokeCallback);
        data_02112140[1]=0;
    }
}
