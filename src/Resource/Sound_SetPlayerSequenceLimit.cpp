#include <globaldefs.h>
extern "C" {
// Original data: arm9/main @ 0x210f83c; symbol: data_0210f83c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct E{unsigned int value;char pad[32];};extern E SoundSetPlayerSequenceLimit_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x020BBF4C; symbol: func_020bbf4c; size: 0x20.
void Sound_SetPlayerSequenceLimit(int i,unsigned int v){SoundSetPlayerSequenceLimit_UnknownRoleZeroInitializedStorage[i].value=(unsigned short)v;}
}
