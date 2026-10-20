#include <globaldefs.h>
ARM
extern "C" int WMi_CheckIdle();extern "C" void WMi_SetCallbackTable(int,void*);extern "C" int WMi_SendCommand(int,int,...);
// Original: arm9/main @ 0x020D6A84; symbol: func_020d6a84; size: 0x50.
extern "C" int WM_SetBeaconIndication(void* p,int n){int result=WMi_CheckIdle();if(result)return result;if(n!=0&&n!=1)return 6;WMi_SetCallbackTable(25,p);result=WMi_SendCommand(25,1,n);if(!result)return 2;return result;}
