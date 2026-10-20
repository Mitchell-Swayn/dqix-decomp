#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e22c; symbol: data_ov031_0224e22c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char NetworkRegisterActiveSocket_UnknownRoleZeroInitializedStorage[];
extern "C" void UnlinkNodeFromChain(void *, void *);
// Original: arm9/ov031 @ 0x02207108; symbol: func_ov031_02207108; size: 0x18.
extern "C" void System_AppendCallbackToGlobalList(void *callback) {
    UnlinkNodeFromChain((void *)NetworkRegisterActiveSocket_UnknownRoleZeroInitializedStorage, callback);
}
