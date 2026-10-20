#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290fc8; symbol: data_ov031_02290fc8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void (* volatile HttpDestroyRequest_UnknownRoleZeroInitializedStorage)(void*);
// Original: arm9/ov031 @ 0x02241720; symbol: func_ov031_02241720; size: 0x3C.
extern "C" void Util_InvokeObjectCallbacks(void* object) {
    if (object == 0)
        return;
    void* value = *(void**)((char*)object + 0x800);
    if (value != 0)
        HttpDestroyRequest_UnknownRoleZeroInitializedStorage(value);
    HttpDestroyRequest_UnknownRoleZeroInitializedStorage(object);
}
