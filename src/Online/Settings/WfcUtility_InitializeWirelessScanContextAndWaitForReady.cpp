#include <globaldefs.h>
ARM
extern "C" void Network_HandleType26ScanReply();
extern "C" int WM_GetDispersionScanPeriod(...);
extern "C" int GameState_IsCallbackStateReady(...);
extern "C" int MIi_CpuClear16(...);
extern "C" int WirelessCommand_CopyValidatedSharedTwoThousandByteBlock(...);
extern "C" int WirelessCommand_InvokeFourArgumentRequestWithZeroMode(...);
extern "C" int GameState_IsCallbackStateReady(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);
// Original data: arm9/ov031 @ 0x2249204; symbol: data_ov031_02249204.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 000000000004ff3f0000ffffffffffff000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 ...; full span in module reference.
// Observed span: 68 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char WfcUtilityInitializeWirelessScanContextAndWaitForReady_UnknownRoleInitializedBytes[];
// Original data: arm9/ov031 @ 0x2290cf8; symbol: data_ov031_02290cf8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char WfcUtilityFreeWirelessScanBufferWhenInactive_UnknownRoleZeroInitializedStorage[];

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov031 @ 0x022357E8; symbol: InitializeWirelessContextAndWaitForSharedStateTwo.
extern "C" int WfcUtility_InitializeWirelessScanContextAndWaitForReady(void){
MIi_CpuClear16(0,P(WfcUtilityFreeWirelessScanBufferWhenInactive_UnknownRoleZeroInitializedStorage,0)+0x1300,0x348);if(WirelessCommand_InvokeFourArgumentRequestWithZeroMode(P(WfcUtilityFreeWirelessScanBufferWhenInactive_UnknownRoleZeroInitializedStorage,0),Network_HandleType26ScanReply,3)!=2)return 0;do{WirelessCommand_CopyValidatedSharedTwoThousandByteBlock(P(WfcUtilityFreeWirelessScanBufferWhenInactive_UnknownRoleZeroInitializedStorage,0)+0x168c);}while(H(P(WfcUtilityFreeWirelessScanBufferWhenInactive_UnknownRoleZeroInitializedStorage,0),0x168c)!=2);char* context=P(WfcUtilityFreeWirelessScanBufferWhenInactive_UnknownRoleZeroInitializedStorage,0);struct Template{unsigned words[17];};*(Template*)(context+0x1648)=*(Template*)WfcUtilityInitializeWirelessScanContextAndWaitForReady_UnknownRoleInitializedBytes;P(context,0x1648)=context+0xf00;H(P(WfcUtilityFreeWirelessScanBufferWhenInactive_UnknownRoleZeroInitializedStorage,0),0x1650)=WM_GetDispersionScanPeriod();return GameState_IsCallbackStateReady()!=0;
}
