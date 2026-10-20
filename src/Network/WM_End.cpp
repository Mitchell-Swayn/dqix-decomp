#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" int TestCurrentStatusAgainstVariadicAllowedValues(int, int);
extern "C" void WMi_SetCallbackTable(int, unsigned int);
extern "C" int WMi_SendCommand(int, int);
// Original: arm9/main @ 0x020D503C; symbol: func_020d503c; size: 0x40.
extern "C" int WM_End(unsigned int value) {
    int result = TestCurrentStatusAgainstVariadicAllowedValues(1, 2);
    if (result != 0)
        return result;
    WMi_SetCallbackTable(2, value);
    result = WMi_SendCommand(2, 0);
    if (result == 0)
        result = 2;
    return result;
}
