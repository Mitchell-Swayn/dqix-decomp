#include <globaldefs.h>
ARM
extern "C" int TestCurrentStatusAgainstVariadicAllowedValues(int,int);extern "C" void WMi_SetCallbackTable(int,void*);extern "C" int WMi_SendCommand(int,int);
// Original: arm9/main @ 0x020D5490; symbol: func_020d5490; size: 0x40.
extern "C" int WM_EndScan(void* p){int r=TestCurrentStatusAgainstVariadicAllowedValues(1,5);if(r)return r;WMi_SetCallbackTable(11,p);r=WMi_SendCommand(11,0);if(!r)r=2;return r;}
