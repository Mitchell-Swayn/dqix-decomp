#include <globaldefs.h>
ARM
extern "C" void MI_CpuCopy8(const void*,void*,unsigned);
extern "C" unsigned short WirelessCommand_IncrementTimeSeededSequence();
extern "C" void WirelessHost_SetParentGroupIdentifier(void*);
// Original data: arm9/ov031 @ 0x2290d20; symbol: data_ov031_02290d20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char* Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x0223A698; symbol: func_ov031_0223a698; size: 0x80.
extern "C" void Network_ResetAndSeedCommandState() {
WirelessHost_SetParentGroupIdentifier(*(void**)(Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage+0xac8));
Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage[0xa90]=1;
*(unsigned short*)(Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage+0x648)=WirelessCommand_IncrementTimeSeededSequence();
MI_CpuCopy8(*(void**)(Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage+0xaa4),Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage+0xa50,0x40);
Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage[0xa93]=0;
*(int*)(Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage+0x204)=0;
++*(unsigned short*)(Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage+0x648);
}
