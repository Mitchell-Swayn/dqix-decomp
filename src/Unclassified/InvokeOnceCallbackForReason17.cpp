#include <globaldefs.h>
#pragma optimize_for_size off
extern "C" {
ARM extern unsigned char data_02112160[]; void DisableInterruptsAndHaltForever(); void System_DispatchModeTwoAndTerminate(); struct State { char pad[12]; int done; char gap[8]; int (*callback)(int); };
// Original: arm9/main @ 0x020D18D0; symbol: func_020d18d0; size: 0x5C.
 void InvokeOnceCallbackForReason17(void*,unsigned int reason) { if((reason&63)==17) { if(((State*)data_02112160)->done)return; int result=0; int(*callback)(int)=((State*)data_02112160)->callback; if(callback)result=callback(0); if(result)System_DispatchModeTwoAndTerminate(); ((State*)data_02112160)->done=1; } else DisableInterruptsAndHaltForever(); }
}
