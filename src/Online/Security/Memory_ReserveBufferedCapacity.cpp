#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224c9c0; symbol: data_ov031_0224c9c0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void* SslSendClientHello_UnknownRoleZeroInitializedStorage_Variant2;
typedef void (*Callback)(void*);
// Original: arm9/ov031 @ 0x0220A66C; symbol: func_ov031_0220a66c; size: 0x50.
extern "C" void Memory_ReserveBufferedCapacity(unsigned size, void* request) {
    unsigned char* state = *(unsigned char**)((char*)request + 0xC);
    unsigned remaining = *(unsigned*)(state + 0x828) - *(unsigned*)(state + 0x82C);
    if (size < remaining) goto update;
    if (*(Callback*)(state + 0x824) != 0)
        ((Callback)SslSendClientHello_UnknownRoleZeroInitializedStorage_Variant2)(*(void**)(state + 0x824));
    *(unsigned*)(state + 0x824) = 0;
    return;
update:
    *(unsigned*)(state + 0x82C) += size;
}
