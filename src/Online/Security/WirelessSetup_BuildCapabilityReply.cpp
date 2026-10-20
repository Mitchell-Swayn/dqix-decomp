#include <globaldefs.h>
THUMB
extern "C" char* WirelessSetup_AppendAlignedTaggedField(char*,int,void*,int);
extern "C" void WirelessSetup_BuildChecksummedMessage(void*,int,void*,int,int);
// Original data: arm9/ov031 @ 0x22460e0; symbol: data_ov031_022460e0.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0600010203040500.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WirelessSetupBuildCapabilityReply_UnknownRoleInitializedBytes[];
// Original data: arm9/ov031 @ 0x224b114; symbol: data_ov031_0224b114.
// Contains original relocated data addresses. Referenced targets and raw storage values are recorded; semantic role and record layout remain unresolved.
// Initial values: hex acfb24020100000000080000ffffffff40000000.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char* Ov031UpdateModeFromStatus_UnknownRoleDataReferences;
// Original data: arm9/ov031 @ 0x224f670; symbol: data_ov031_0224f670.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 80 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov031 @ 0x224fb18; symbol: data_ov031_0224fb18.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x224fba4; symbol: data_ov031_0224fba4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WirelessSetupBuildCapabilityReply_UnknownRoleZeroInitializedStorage[],WirelessSetupBuildCapabilityReply_UnknownRoleZeroInitializedStorage_Variant2[];
// Original: arm9/ov031 @ 0x0222053C; symbol: BuildAndSubmitContextTaggedFields; size: 0x9c.
// Builds tagged fields1/2/3 and conditional5/4 then submits buffer extent.
extern "C" void WirelessSetup_BuildCapabilityReply(void* p){
 struct Local{unsigned short value;unsigned char bytes[7];} local;local.value=256;
 struct Bytes {unsigned char value[7];};*(Bytes*)local.bytes=*(Bytes*)WirelessSetupBuildCapabilityReply_UnknownRoleInitializedBytes;
 char* end=WirelessSetup_AppendAlignedTaggedField(Ov031UpdateModeFromStatus_UnknownRoleDataReferences,1,&local.value,2);end=WirelessSetup_AppendAlignedTaggedField(end,2,&local.value,2);
 if(WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage[20])end=WirelessSetup_AppendAlignedTaggedField(end,5,&local.value,2);
 end=WirelessSetup_AppendAlignedTaggedField(end,3,local.bytes,7);
 if(WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage[20])end=WirelessSetup_AppendAlignedTaggedField(end,4,WirelessSetupBuildCapabilityReply_UnknownRoleZeroInitializedStorage,6);
 WirelessSetup_BuildChecksummedMessage(p,2,WirelessSetupBuildCapabilityReply_UnknownRoleZeroInitializedStorage_Variant2,end-Ov031UpdateModeFromStatus_UnknownRoleDataReferences+8,0);
}
