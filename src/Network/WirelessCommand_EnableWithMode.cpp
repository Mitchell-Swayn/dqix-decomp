#include <globaldefs.h>
#pragma optimize_for_size off
extern "C" int TestCurrentStatusAgainstVariadicAllowedValues(int, int);
extern "C" void WMi_SetCallbackTable(int, int);
extern "C" int* WMi_GetSystemWork(void);
extern "C" int WMi_SendCommand(int, ...);
// Original: arm9/main @ 0x020D4E58; symbol: func_020d4e58; size: 0x64.
extern "C" int WirelessCommand_EnableWithMode(int a, int b) {
    int result=TestCurrentStatusAgainstVariadicAllowedValues(1,0);
    if(result==0) {
        WMi_SetCallbackTable(3,a);
        int* state=WMi_GetSystemWork();
        result=WMi_SendCommand(3,4,state[0],state[1],state[4],b);
        if(result==0) result=2;
    }
    return result;
}
