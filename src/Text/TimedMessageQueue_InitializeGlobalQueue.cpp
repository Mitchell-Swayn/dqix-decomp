#include <globaldefs.h>
extern "C" {
// Original data: arm9/main @ 0x214e34c; symbol: data_0214e34c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 340 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned char ScriptReadGlobalExecutionValue_UnknownRoleZeroInitializedStorage[];
void TimedMessageQueue_Initialize(void*);
}
#pragma define_section init ".init" RX
// Original: arm9/main @ 0x020E66FC; symbol: __sinit_020e66fc; size: 0x14.
extern "C" __declspec(section "init") void __sinit_020e66fc()
{
    TimedMessageQueue_Initialize(ScriptReadGlobalExecutionValue_UnknownRoleZeroInitializedStorage);
}
