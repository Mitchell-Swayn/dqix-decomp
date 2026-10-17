#include <globaldefs.h>
#pragma optimize_for_size off

extern unsigned int data_02112140[];
extern "C" void DisableInterruptsAndHaltForever(void);
extern "C" void ResetDMAAndProcessSharedHardwareStatus(void);

// Original: arm9/main @ 0x020D1144; symbol: func_020d1144; size: 0x54.
extern "C" void IPC_HandleCommandSeventeenOnceAndInvokeCallback(unsigned int, unsigned int command, unsigned int)
{
    if ((command & 0x3f) == 0x11) {
    if (data_02112140[0] != 0) return;
    data_02112140[0] = 1;
    int result = 1;
    if (data_02112140[1] != 0) {
        result = ((int (*)())data_02112140[1])();
    }
    if (result != 0) ResetDMAAndProcessSharedHardwareStatus();
    } else {
        DisableInterruptsAndHaltForever();
    }
}
