#include <globaldefs.h>
extern "C" {
// Original data: arm9/main @ 0x20fdccc; symbol: data_020fdccc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern char PartyStatusMarkMemberSnapshotChanged_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x02026F20; symbol: func_02026f20; size: 0x14.
void PartyStatus_MarkMemberSnapshotChanged(int unused,int i){PartyStatusMarkMemberSnapshotChanged_UnknownRoleZeroInitializedStorage[i*32]=1;}
}
