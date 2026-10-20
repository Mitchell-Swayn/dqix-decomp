#include <globaldefs.h>
// Original data: arm9/ov027 @ 0x21e33e0; symbol: data_ov027_021e33e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov027.md.
extern "C" unsigned char MBEnd_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov027 @ 0x021dd024; symbol: func_ov027_021dd024; size: 0x14.
extern "C" unsigned MBi_GetGgid() {
    unsigned char* first = *(unsigned char**)(MBEnd_UnknownRoleZeroInitializedStorage + 8);
    return *(unsigned*)(first + 8);
}
