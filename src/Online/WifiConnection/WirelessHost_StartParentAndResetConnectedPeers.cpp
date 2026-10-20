#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290d18; symbol: data_ov031_02290d18.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned* WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage[2];
extern "C" int DispatchRequestWithModeOne(unsigned);
extern "C" void WirelessHost_StoreErrorUnlessTerminal(unsigned);
// Address-only callback use; original handler reads one incoming record pointer.
extern "C" void WirelessHost_HandleParentConnectionEvent(void*);
// Original: arm9/ov031 @ 0x02239550; symbol: func_ov031_02239550; size: 0x64.
// Accepts phases4..6 immediately; otherwise submits its callback and initializes the ready halfwords on result2.
extern "C" int WirelessHost_StartParentAndResetConnectedPeers()
{
 if(WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage[1][16]-4<=2)return 1;
 int result=DispatchRequestWithModeOne((unsigned)WirelessHost_HandleParentConnectionEvent);
 if(result!=2){WirelessHost_StoreErrorUnlessTerminal(result);return 0;}
 *(unsigned short*)((char*)WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage[1]+0x50)=0;
 *(unsigned short*)((char*)WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage[1]+0x52)=1;
 return 1;
}
