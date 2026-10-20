#include <globaldefs.h>
ARM
extern "C" void WirelessHost_StoreErrorUnlessTerminal(unsigned value);
extern "C" void WirelessHost_SetSystemState(int value);
// Original: arm9/ov031 @ 0x02239B10; symbol: func_ov031_02239b10; size: 0x24.
extern "C" void System_SetStateFromHalfword2(void *object) {
    unsigned short value = *(unsigned short *)((char *)object + 2);
    if (value)
        WirelessHost_StoreErrorUnlessTerminal(value);
    else
        WirelessHost_SetSystemState(1);
}
