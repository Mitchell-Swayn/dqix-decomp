#include <globaldefs.h>
ARM
int DisableIRQInterrupts();
int SetIRQInterruptState(int);
THUMB
extern "C" char WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage[];
extern "C" int WirelessSetupPopEvent_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x0221F9F8; symbol: WirelessSetup_ResetEventQueue; size: 0x28.
// Clears shared queue counters and four entries while IRQs are disabled.
extern "C" void WirelessSetup_ResetEventQueue(){
 int state=DisableIRQInterrupts();
 *(int*)(WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage+0x68)=0;*(int*)(WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage+0x6c)=0;
 int* entry=WirelessSetupPopEvent_UnknownRoleZeroInitializedStorage;
 int i=0;do{++i;*entry++=0;}while(i<4);
 SetIRQInterruptState(state);
}
