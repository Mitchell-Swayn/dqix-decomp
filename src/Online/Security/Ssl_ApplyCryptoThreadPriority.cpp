#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x22496fc; symbol: data_ov031_022496fc.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 04000500ffffffff.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned SslSendClientHello_UnknownRoleInitializedBytes;
// Original data: arm9/main @ 0x2111304; symbol: data_02111304.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned OSInitThread_UnknownRoleZeroInitializedStorage_Variant2;
extern "C" int _Z18GetContextPriorityP16ProcessorContext(void*);
extern "C" void _Z21ChangeContextPriorityP16ProcessorContextj(void*, unsigned);
// Original: arm9/ov031 @ 0x02207CF0; symbol: func_ov031_02207cf0; size: 0x4C.
extern "C" int Ssl_ApplyCryptoThreadPriority(void) {
    unsigned requested = *(unsigned*)((char*)&SslSendClientHello_UnknownRoleInitializedBytes + 4);
    if (requested >= 0x20) return -1;
    void* context = *(void**)((char*)&OSInitThread_UnknownRoleZeroInitializedStorage_Variant2 + 4);
    int previous = _Z18GetContextPriorityP16ProcessorContext(context);
    _Z21ChangeContextPriorityP16ProcessorContextj(context, *(unsigned*)((char*)&SslSendClientHello_UnknownRoleInitializedBytes + 4));
    return previous;
}
