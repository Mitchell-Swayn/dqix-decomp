#include <globaldefs.h>
#include <System/ProcessorContext.h>
ARM
// Pinned NitroWiFi CPS_Cleanup: libraries/cps/src/network.c.
// Partial contiguous CPS global-data view; not a separate logical allocation.
struct CpsGlobalTailView {unsigned char unknown[0x54];ProcessorContext* receiver;void* wlanBuffer;unsigned wlanBufferLength;};
extern "C" {
 int System_PollContextAndDrainQueue();
 void Network_ResetAddressStateAndWakeSocketWaiters(int);
 extern ProcessorContext SystemPollContextAndDrainQueue_UnknownRoleZeroInitializedStorage;
 extern ProcessorContext NetworkStopWorkersAndResetStack_UnknownRoleZeroInitializedStorage;
 extern CpsGlobalTailView NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage;
}
// Original: arm9/ov031 @ 0x02200534; symbol: func_ov031_02200534; size: 0x48.
extern "C" void Network_StopWorkersAndResetStack() {
 System_PollContextAndDrainQueue();
 AwaitContextCompletion(&SystemPollContextAndDrainQueue_UnknownRoleZeroInitializedStorage);
 ShutdownContext(&NetworkStopWorkersAndResetStack_UnknownRoleZeroInitializedStorage);
 NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.receiver=0;
 Network_ResetAddressStateAndWakeSocketWaiters(0);
 NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.wlanBuffer=0;
 NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.wlanBufferLength=0;
}
