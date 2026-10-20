#include <globaldefs.h>
// Original data: arm9/main @ 0x2114260; symbol: data_02114260.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 96 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Record { unsigned a,b; unsigned char flag,pad[3]; }; extern "C" Record SoundCommandIncrementIndexedCounter_UnknownRoleZeroInitializedStorage[8];
// Original: arm9/main @ 0x020D2930; symbol: func_020d2930; size: 0x30.
 extern "C" ARM void SoundCommand_ClearCompletionCallbacks() { int i=0;Record* p=SoundCommandIncrementIndexedCounter_UnknownRoleZeroInitializedStorage;do{p->a=0;p->b=0;++i;p->flag=0;++p;}while(i<8); }
