#include <globaldefs.h>
extern "C" int TestCurrentStatusAgainstVariadicAllowedValues(int,int); extern "C" void WMi_SetCallbackTable(int,void*); extern "C" int WMi_SendCommand(int,int);
// Original: arm9/main @ 0x020D4EBC; symbol: func_020d4ebc; size: 0x40.
extern "C" int WirelessCommand_SubmitOpcodeFourAfterModeValidation(void* input) { int result=TestCurrentStatusAgainstVariadicAllowedValues(1,1); if(result)return result; WMi_SetCallbackTable(4,input); result=WMi_SendCommand(4,0); if(!result)result=2; return result; }
