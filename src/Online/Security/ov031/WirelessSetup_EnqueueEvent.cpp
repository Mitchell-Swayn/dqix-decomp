#include <globaldefs.h>
THUMB
#pragma optimize_for_size off
extern "C" unsigned char WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage[];
extern "C" unsigned WirelessSetupPopEvent_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x0221FA58; symbol: WirelessSetup_EnqueueEvent; size: 0x30.
// Adds one value unless advancing the four-slot ring would collide with its tail.
extern "C" void WirelessSetup_EnqueueEvent(unsigned value) {
 int* state=(int*)WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage;
 int head=state[26];
 int tail=state[27];
 int next=head+1;
 if(next!=tail && head!=tail+3) {
  WirelessSetupPopEvent_UnknownRoleZeroInitializedStorage[head]=value;
  state[26]=next;
  if(next>=4)state[26]=0;
 }
}
