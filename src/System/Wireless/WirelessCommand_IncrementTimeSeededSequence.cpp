#include <globaldefs.h>
ARM
#pragma opt_propagation off
extern "C" unsigned data_020f2304;
extern "C" void RealTimeClock_InitializeIPCHandler();
extern "C" int StoreOperationResultAndFinalizeSuccess(void*);
// Original: arm9/main @ 0x020D4DD4; symbol: func_020d4dd4; size: 0x74.
extern "C" unsigned short WirelessCommand_IncrementTimeSeededSequence() {
    unsigned words[3];
    if(data_020f2304==65536) {
        RealTimeClock_InitializeIPCHandler();
        if(!StoreOperationResultAndFinalizeSuccess(words)) data_020f2304=(unsigned short)(words[2]+words[1]*256);
    }
    return data_020f2304=(unsigned short)(data_020f2304+1);
}
