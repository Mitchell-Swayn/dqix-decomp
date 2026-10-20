#include <globaldefs.h>
extern "C" int TestCurrentStatusAgainstVariadicAllowedValues(int,int);extern "C" void WMi_SetCallbackTable(int,unsigned);extern "C" int WMi_SendCommand(int,int);
// Original: arm9/main @ 0x020D5214; symbol: func_020d5214; size: 0x40.
extern "C" ARM int WirelessCommand_SubmitOpcodeNineAfterStateValidation(unsigned value){int r=TestCurrentStatusAgainstVariadicAllowedValues(1,7);if(r)return r;WMi_SetCallbackTable(9,value);r=WMi_SendCommand(9,0);if(!r)r=2;return r;}
