#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e590; symbol: data_ov031_0224e590.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void * volatile YssdSessionTryDestroy_UnknownRoleZeroInitializedStorage;
extern "C" void YssdClient_SetError(int, int);
// Original: arm9/ov031 @ 0x02211440; symbol: func_ov031_02211440; size: 0x44.
extern "C" void SetPendingInputAndInvokeHandler(void *value) {
    void *state = YssdSessionTryDestroy_UnknownRoleZeroInitializedStorage;
    if (state == 0) return;
    *(void **)((unsigned char *)state + 4) = value;
    void (*handler)(void *) = *(void (**)(void *))((unsigned char *)YssdSessionTryDestroy_UnknownRoleZeroInitializedStorage + 0x3c);
    if (handler != 0) handler(value);
    else YssdClient_SetError(9, -2);
}
