#include <globaldefs.h>
#pragma optimize_for_size off
#pragma optimization_level 4
extern "C" int TestCurrentStatusAgainstVariadicAllowedValues(int, int);
extern "C" void WMi_SetCallbackTable(int, int);
extern "C" int WMi_GetSystemWork(void);
extern "C" int WMi_SendCommandDirect(unsigned short*, int);
// Original: arm9/main @ 0x020D6B34; symbol: func_020d6b34; size: 0x78.
extern "C" int WM_MeasureChannel(int a, unsigned short b, unsigned short c, unsigned short d, unsigned short e) {
    WMi_GetSystemWork();
    int result=TestCurrentStatusAgainstVariadicAllowedValues(1,2);
    if(result!=0) return result;
    WMi_SetCallbackTable(0x1e,a);
    unsigned short payload[5]; payload[0]=0x1e; payload[1]=b; payload[2]=c; payload[3]=d; payload[4]=e;
    result=WMi_SendCommandDirect(payload,10);
    if(result==0) result=2;
    return result;
}
