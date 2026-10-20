#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2114260; symbol: data_02114260.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 96 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Entry{void(*fn)(void*);void* data;unsigned char generation;unsigned char pad[3];};extern "C" Entry SoundCommandIncrementIndexedCounter_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x020D29B0; symbol: func_020d29b0; size: 0x44.
extern "C" void SoundCommand_InvokeGenerationMatchedCallback(int handle){Entry* p=SoundCommandIncrementIndexedCounter_UnknownRoleZeroInitializedStorage+(handle&255);unsigned generation=(handle>>8)&255;if(generation!=p->generation)return;if(p->fn)p->fn(p->data);}
