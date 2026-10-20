#include <globaldefs.h>
ARM

extern "C" unsigned Network_GetConnectionPhase(void);
extern "C" unsigned Network_GetConnectionWorkspace(unsigned);
extern "C" unsigned WirelessConnection_PrepareChosenAccessPoint(void);
extern "C" unsigned Network_RetrySelectedWirelessRequest(void);

// Original: arm9/ov031 @ 0x02213C9C; symbol: func_ov031_02213c9c; size: 0x44.
extern "C" unsigned System_SelectStateHandlerByOptionalByte(void) {
    unsigned value = Network_GetConnectionPhase();
    Network_GetConnectionWorkspace(0x10);
    switch (value) {
    case 7:
        value = WirelessConnection_PrepareChosenAccessPoint();
        break;
    case 8:
        value = Network_RetrySelectedWirelessRequest();
        break;
    default:
        break;
    }
    return value;
}
