#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e5b4; symbol: data_ov031_0224e5b4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char WirelessConnectionPollStatus_UnknownRoleZeroInitializedStorage[];
extern "C" void WirelessBeaconScan_RequestStopCollecting();extern "C" unsigned WirelessBeaconScan_PollBestCandidateSelection();extern "C" void WirelessBeaconScan_ReleaseSelectionWorkspaces();
extern "C" int System_AdvanceSharedSequenceOrDispatchPriorityState();extern "C" void _Z19SleepCurrentContextj(unsigned);
// Original: arm9/ov031 @ 0x022120F8; symbol: WaitForPendingContextAndClearOwner; size: 0x8C.
// Waits for pending-context status and clears the shared owner pointer.
extern "C" void WaitForPendingContextAndClearOwner() {
char* owner=*(char**)(WirelessConnectionPollStatus_UnknownRoleZeroInitializedStorage+4);if(!owner)return;
if(*(unsigned short*)(owner+4)==1){if(*(unsigned*)(owner+0x10)==1){WirelessBeaconScan_RequestStopCollecting();while((unsigned)(WirelessBeaconScan_PollBestCandidateSelection()-2)>2){}WirelessBeaconScan_ReleaseSelectionWorkspaces();}*(void**)(WirelessConnectionPollStatus_UnknownRoleZeroInitializedStorage+4)=0;}
else {if(!System_AdvanceSharedSequenceOrDispatchPriorityState()){do{_Z19SleepCurrentContextj(10);}while(!System_AdvanceSharedSequenceOrDispatchPriorityState());}*(void**)(WirelessConnectionPollStatus_UnknownRoleZeroInitializedStorage+4)=0;}
}