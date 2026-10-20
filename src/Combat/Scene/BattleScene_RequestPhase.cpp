#include <globaldefs.h>
// Original data: arm9/ov000 @ 0x2184220; symbol: data_ov000_02184220.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" unsigned int BattleSceneUpdate_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov000 @ 0x02160D80; symbol: func_ov000_02160d80; size: 0x20.
// Layout projection only; broader object ownership remains unclassified.
extern "C" ARM void BattleScene_RequestPhase(unsigned char* p,unsigned int value) {
 *(unsigned int*)(p+0xea8)=value; *(unsigned int*)(p+0xeac)=0; BattleSceneUpdate_UnknownRoleZeroInitializedStorage=1;
}
