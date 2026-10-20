#include <globaldefs.h>

extern "C" void OS_SpinWait(int delay);
extern "C" int PowerManagement_IsLcdPowerEnabled();
extern "C" int PowerManagement_SetDeviceEnabledSynchronously(int kind, int value);
extern "C" int IPC_SendNormalizedBooleanModeCommand(int value);

// Original: arm9/main @ 0x020CEF94; symbol: func_020cef94; size: 0x8C.
extern "C" void IPC_WaitForPendingCommandsAndRetryWithDelays()
{
    OS_SpinWait(0x360000);
    if (PowerManagement_IsLcdPowerEnabled() == 1) {
        return;
    }

    int pending = PowerManagement_SetDeviceEnabledSynchronously(2, 0);
    if (pending == 0) goto no_pending;
    const unsigned int delay = 0xa3a47;
loop_pending:
    OS_SpinWait(delay);
    pending = PowerManagement_SetDeviceEnabledSynchronously(2, 0);
    if (pending != 0) goto loop_pending;
no_pending:

    if (IPC_SendNormalizedBooleanModeCommand(1) != 0) {
        return;
    }
    do {
        OS_SpinWait(10);
        pending = IPC_SendNormalizedBooleanModeCommand(1);
    } while (pending == 0);
}
