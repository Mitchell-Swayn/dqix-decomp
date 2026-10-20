#include <globaldefs.h>
#pragma optimize_for_size off
extern "C" int WirelessCommand_InitializeAndClearSharedHalfword16(int, int);
extern "C" void WMi_SetCallbackTable(int, int);
extern "C" int *WMi_GetSystemWork(void);
extern "C" int WMi_SendCommand(int, int, int, int, int, int);

// Original: arm9/main @ 0x020D4FA4; symbol: func_020d4fa4; size: 0x60.
extern "C" int WirelessCommand_InitializeWithMode(int first, int second, int third, int fourth) {
    int result = WirelessCommand_InitializeAndClearSharedHalfword16(first, third);
    if (result != 0) {
        return result;
    }
    WMi_SetCallbackTable(0, second);
    int *context = WMi_GetSystemWork();
    result = WMi_SendCommand(0, 4, context[0], context[1], context[4], fourth);
    if (result == 0) {
        result = 2;
    }
    return result;
}
