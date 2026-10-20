#include <globaldefs.h>
ARM
extern "C" int _Z20DisableIRQInterruptsv();extern "C" void _Z20SetIRQInterruptStatei(int);extern "C" int WirelessCommand_ReadInitializedStatus();extern "C" unsigned char* WMi_GetSystemWork();
// Original: arm9/main @ 0x020D472C; symbol: func_020d472c; size: 0x44.
extern "C" int WM_SetIndCallback(unsigned value){int state=_Z20DisableIRQInterruptsv();int result=WirelessCommand_ReadInitializedStatus();if(result){_Z20SetIRQInterruptStatei(state);return result;}*(unsigned*)(WMi_GetSystemWork()+200)=value;_Z20SetIRQInterruptStatei(state);return 0;}
