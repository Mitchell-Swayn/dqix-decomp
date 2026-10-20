#include <globaldefs.h>
ARM
extern "C" void WirelessHost_SetSystemState(int value);
extern "C" void DisableInterruptsAndHaltForever(void);
// Original: arm9/ov031 @ 0x0223A040; symbol: func_ov031_0223a040; size: 0x20.
extern "C" void WirelessHost_HaltOnFifoIndicationError(void *object) {
    if (*(unsigned short *)((char *)object + 2) == 8) {
        WirelessHost_SetSystemState(9);
        DisableInterruptsAndHaltForever();
    }
}
