#pragma optimize_for_size off
#include <globaldefs.h>
extern "C" int WMi_CheckIdle(void*);extern "C" void WMi_SetCallbackTable(int,void*);extern "C" int WMi_SendCommand(int,int,unsigned,unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x020D6AD4; symbol: func_020d6ad4; size: 0x60.
extern "C" int WirelessCommand_SubmitOpcodeTwentyNineWithFourArguments(void* input,unsigned a,unsigned b,unsigned c,unsigned short d) { int result=WMi_CheckIdle(input);if(result)return result;WMi_SetCallbackTable(29,input);result=WMi_SendCommand(29,4,a,b,c,d);if(!result)result=2;return result; }
