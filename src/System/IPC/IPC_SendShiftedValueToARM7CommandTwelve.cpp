#pragma optimization_level 4
#include <globaldefs.h>
#include <System/IPC.h>
extern "C" {
// Original: arm9/main @ 0x020C98C4; symbol: func_020c98c4; size: 0x2C.
    void IPC_SendShiftedValueToARM7CommandTwelve(int value){
        while(SendCommandToArm7(12,value<<8,false)!=0){
        }
    }
}
