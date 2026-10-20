#include <globaldefs.h>
ARM
extern "C" void WirelessHost_StoreErrorUnlessTerminal(unsigned int);
extern "C" void WirelessHost_SetSystemState(int);
extern "C" int WM_SetIndCallback(unsigned int);
extern "C" int WirelessHost_HaltOnFifoIndicationError();
// Original: arm9/ov031 @ 0x0223A0AC; symbol: func_ov031_0223a0ac; size: 0x50.
extern "C" void WirelessHost_HandleInitializationAndInstallIndicationCallback(void *p) {
    unsigned int value = *(unsigned short *)((char *)p + 2);
    if (value != 0) {
        WirelessHost_StoreErrorUnlessTerminal(value);
        WirelessHost_SetSystemState(10);
        return;
    }
    value = WM_SetIndCallback((unsigned int)WirelessHost_HaltOnFifoIndicationError);
    if (value != 0) {
        WirelessHost_StoreErrorUnlessTerminal(value);
        WirelessHost_SetSystemState(10);
    } else {
        WirelessHost_SetSystemState(1);
    }
}
