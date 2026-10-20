#include <globaldefs.h>
extern "C" int TestCurrentStatusAgainstVariadicAllowedValues(int, int);
extern "C" void WMi_SetCallbackTable(int, int);
extern "C" int WMi_SendCommand(int, int);
// Original: arm9/main @ 0x020D4F3C; symbol: func_020d4f3c; size: 0x40.
extern "C" int WM_PowerOff(int arg) {
    int result = TestCurrentStatusAgainstVariadicAllowedValues(1, 2);
    if (result != 0) return result;
    WMi_SetCallbackTable(6, arg);
    result = WMi_SendCommand(6, 0);
    if (result == 0) result = 2;
    return result;
}
