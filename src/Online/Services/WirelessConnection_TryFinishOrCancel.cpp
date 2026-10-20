#include <globaldefs.h>
ARM
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
struct Nibble{unsigned char lower:4,upper:4;};
extern "C" unsigned WirelessBeaconScan_ReleaseSelectionWorkspaces(...);
extern "C" unsigned System_AdvanceSharedSequenceOrDispatchPriorityState(...);
extern "C" unsigned WirelessBeaconScan_PollBestCandidateSelection(...);
extern "C" unsigned WirelessBeaconScan_RequestStopCollecting(...);
// Original data: arm9/ov031 @ 0x224e5b4; symbol: data_ov031_0224e5b4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WirelessConnectionPollStatus_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031:02212184
extern "C" int WirelessConnection_TryFinishOrCancel(){char* p=(char*)U(WirelessConnectionPollStatus_UnknownRoleZeroInitializedStorage,4);if(!p)return 1;if(H(p,4)==8)return 1;if(H(p,4)==1){if(U(p,16)==1){WirelessBeaconScan_RequestStopCollecting();U((char*)U(WirelessConnectionPollStatus_UnknownRoleZeroInitializedStorage,4),16)=5;return 0;}if(U(p,16)==5){unsigned state=WirelessBeaconScan_PollBestCandidateSelection();if(state==1)return 0;if((unsigned)(state-2)<=2)WirelessBeaconScan_ReleaseSelectionWorkspaces();}U(WirelessConnectionPollStatus_UnknownRoleZeroInitializedStorage,4)=0;return 1;}H(p,4)=5;if(!System_AdvanceSharedSequenceOrDispatchPriorityState())return 0;U(WirelessConnectionPollStatus_UnknownRoleZeroInitializedStorage,4)=0;return 1;}
