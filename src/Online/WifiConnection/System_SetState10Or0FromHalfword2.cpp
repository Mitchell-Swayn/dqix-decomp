#include <globaldefs.h>
ARM
extern "C" void WirelessHost_SetSystemState(int value);
// Original: arm9/ov031 @ 0x02239B98; symbol: func_ov031_02239b98; size: 0x28.
extern "C" void System_SetState10Or0FromHalfword2(void *object) {
    if (*(unsigned short *)((char *)object + 2))
        WirelessHost_SetSystemState(10);
    else
        WirelessHost_SetSystemState(0);
}
