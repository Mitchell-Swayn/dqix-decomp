#include <globaldefs.h>
ARM
extern "C" void WirelessHost_SetSystemState(int);
extern "C" void WirelessHost_StoreErrorUnlessTerminal(unsigned);
// Original: arm9/ov031 @ 0x02239B64; symbol: Network_SetTransitionFromObjectValue; size: 0x34.
// Uses object halfword+2 to set transition 9 and shared word+0x54; zero selects transition 1.
extern "C" void Network_SetTransitionFromObjectValue(unsigned char* object) {
    if (*(unsigned short*)(object + 2)) {
        WirelessHost_SetSystemState(9);
        WirelessHost_StoreErrorUnlessTerminal(*(unsigned short*)(object + 2));
    } else {
        WirelessHost_SetSystemState(1);
    }
}
