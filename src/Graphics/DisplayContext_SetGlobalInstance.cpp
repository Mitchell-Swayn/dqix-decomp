#include <globaldefs.h>
extern "C" {
// Original data: arm9/main @ 0x2109400; symbol: data_02109400.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned int DisplayContextGetGlobalInstance_UnknownRoleZeroInitializedStorage;
// Original: arm9/main @ 0x02094A10; symbol: func_02094a10; size: 0x10.
void DisplayContext_SetGlobalInstance(unsigned int v){DisplayContextGetGlobalInstance_UnknownRoleZeroInitializedStorage=v;}
}
