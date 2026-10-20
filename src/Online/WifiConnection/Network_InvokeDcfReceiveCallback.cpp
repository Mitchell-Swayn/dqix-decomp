#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e540; symbol: data_ov031_0224e540.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char SystemHandleType12Message_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x0220EF9C; symbol: func_ov031_0220ef9c; size: 0x34.
extern "C" void Network_InvokeDcfReceiveCallback(void *obj) {
    unsigned int callback = *(unsigned int *)(SystemHandleType12Message_UnknownRoleZeroInitializedStorage + 0x28);
    if (callback != 0) {
        ((void (*)(void *, void *, void *, int))callback)((char *)obj + 0x1e, (char *)obj + 0x18, (char *)obj + 0x2c, *(unsigned short *)((char *)obj + 6));
    }
}
