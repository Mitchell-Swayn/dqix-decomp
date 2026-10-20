#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2114260; symbol: data_02114260.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 96 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Entry{unsigned x,y;unsigned char serial;unsigned char pad[3];};extern "C" Entry SoundCommandIncrementIndexedCounter_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x020D2980; symbol: func_020d2980; size: 0x30.
extern "C" unsigned SoundCommand_RegisterCompletionCallback(unsigned index,unsigned x,unsigned y){Entry* p=SoundCommandIncrementIndexedCounter_UnknownRoleZeroInitializedStorage+index;p->x=x;p->y=y;return ++p->serial;}
