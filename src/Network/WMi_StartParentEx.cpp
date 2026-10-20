#include <globaldefs.h>
ARM
extern "C" int TestCurrentStatusAgainstVariadicAllowedValues(int,int);extern "C" char* WMi_GetSystemWork();extern "C" void WMi_SetCallbackTable(int,int);extern "C" int WMi_SendCommand(int,int,int);
// Original: arm9/main @ 0x020D51A8; symbol: func_020d51a8; size: 0x5C.
extern "C" int WMi_StartParentEx(int a,int b){int n=TestCurrentStatusAgainstVariadicAllowedValues(1,2);if(n)return n;char* p=WMi_GetSystemWork();*(unsigned short*)(p+0x150)=0;*(int*)(p+0x14c)=0;WMi_SetCallbackTable(8,a);n=WMi_SendCommand(8,1,b);if(!n)n=2;return n;}
