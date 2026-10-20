#include <globaldefs.h>
extern "C" {
// Original data: arm9/ov031 @ 0x2290cf4; symbol: data_ov031_02290cf4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern char* WfcScrollbarDestroy_UnknownRoleZeroInitializedStorage;
}
// Original: arm9/ov031 @ 0x0223521C; symbol: func_ov031_0223521c; size: 0x18.
// Field roles remain unclassified; offsets describe the observed layout.
extern "C" ARM void WfcScrollbar_DisableTouchInput(void)
{
    WfcScrollbarDestroy_UnknownRoleZeroInitializedStorage[0x1e]=1;
}
