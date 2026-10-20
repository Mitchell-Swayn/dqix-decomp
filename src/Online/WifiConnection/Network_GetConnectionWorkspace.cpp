#include <globaldefs.h>
extern "C" {
// Original data: arm9/ov031 @ 0x224e5c4; symbol: data_ov031_0224e5c4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern int NetworkGetConnectionPhase_UnknownRoleZeroInitializedStorage[];
}
// Original: arm9/ov031 @ 0x022133F8; symbol: func_ov031_022133f8; size: 0x58.
// Field roles remain unclassified; offsets describe the observed layout.
extern "C" ARM int Network_GetConnectionWorkspace(unsigned mask)
{
    if(mask&1) return NetworkGetConnectionPhase_UnknownRoleZeroInitializedStorage[3];
    if(mask&2) return NetworkGetConnectionPhase_UnknownRoleZeroInitializedStorage[0];
    if(mask&4) return NetworkGetConnectionPhase_UnknownRoleZeroInitializedStorage[1];
    if(mask&8) return NetworkGetConnectionPhase_UnknownRoleZeroInitializedStorage[2];
    if(mask&16) return NetworkGetConnectionPhase_UnknownRoleZeroInitializedStorage[4];
    return 0;
}
