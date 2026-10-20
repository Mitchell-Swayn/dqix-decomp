#include <globaldefs.h>

extern "C" void IPC_SendChannelThirteenCommandUntilAccepted(int);
extern "C" void DisableInterruptsAndHaltForever();

// Original: arm9/main @ 0x020D192C; symbol: func_020d192c; size: 0x14.
extern "C" ARM void System_DispatchModeTwoAndTerminate() {
    IPC_SendChannelThirteenCommandUntilAccepted(2);
    DisableInterruptsAndHaltForever();
}
