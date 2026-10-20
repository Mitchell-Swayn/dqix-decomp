#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
// Original data: arm9/ov031 @ 0x224e5b4; symbol: data_ov031_0224e5b4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" {int WirelessBeaconScan_PollBestCandidateSelection();void WirelessBeaconScan_ReleaseSelectionWorkspaces();int WirelessConnection_StartProfileAfterFallback(void*,unsigned,unsigned,unsigned,unsigned);int Network_ProcessAccessPointConnection();unsigned Network_GetWirelessLifecycleState();extern unsigned char WirelessConnectionPollStatus_UnknownRoleZeroInitializedStorage[];}
// Original: arm9/ov031 @0x02211e08; symbol:Network_AdvanceOptionalTransferContextState; size:0x11c.
// Advances optional transfer context through processor callbacks and completion states, including guarded mode reset.
extern "C" void WirelessConnection_AdvanceFallback(){unsigned char* state=P(WirelessConnectionPollStatus_UnknownRoleZeroInitializedStorage,4);if(!state)return;switch(W(state,16)){case 1:W(state,0)=0;W(P(WirelessConnectionPollStatus_UnknownRoleZeroInitializedStorage,4),16)=WirelessBeaconScan_PollBestCandidateSelection();return;case 2:WirelessBeaconScan_ReleaseSelectionWorkspaces();state=P(WirelessConnectionPollStatus_UnknownRoleZeroInitializedStorage,4);WirelessConnection_StartProfileAfterFallback(state+20,(unsigned)(state+52),W(state,84),(unsigned)(state+88),8);W(P(WirelessConnectionPollStatus_UnknownRoleZeroInitializedStorage,4),16)=0;return;case 3:WirelessBeaconScan_ReleaseSelectionWorkspaces();W(P(WirelessConnectionPollStatus_UnknownRoleZeroInitializedStorage,4),0)=-1;P(WirelessConnectionPollStatus_UnknownRoleZeroInitializedStorage,4)[12]=1;return;case 4:case 5:return;default:if(U(state,4)==2){W(P(WirelessConnectionPollStatus_UnknownRoleZeroInitializedStorage,4),0)=Network_ProcessAccessPointConnection();return;}if(U(state,4)==4&&U(state,6)&&Network_GetWirelessLifecycleState()!=9){U(P(WirelessConnectionPollStatus_UnknownRoleZeroInitializedStorage,4),6)=0;U(P(WirelessConnectionPollStatus_UnknownRoleZeroInitializedStorage,4),4)=6;}return;}}
