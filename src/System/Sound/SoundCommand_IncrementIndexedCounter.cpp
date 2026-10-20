#include <globaldefs.h>
extern "C" {
// Original data: arm9/main @ 0x2114260; symbol: data_02114260.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 96 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct E{char pad[8];unsigned char count;char pad2[3];};extern E SoundCommandIncrementIndexedCounter_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x020D2960; symbol: func_020d2960; size: 0x20.
void SoundCommand_IncrementIndexedCounter(int i){E *p=SoundCommandIncrementIndexedCounter_UnknownRoleZeroInitializedStorage+i;p->count++;}
}
