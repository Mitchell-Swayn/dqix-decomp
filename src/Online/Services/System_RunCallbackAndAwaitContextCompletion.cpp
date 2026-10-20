#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290fd0; symbol: data_ov031_02290fd0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int HttpRunQueuedRequestWorker_UnknownRoleZeroInitializedStorage_Variant2;
// Original data: arm9/ov031 @ 0x22918dc; symbol: data_ov031_022918dc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 192 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char SystemRunCallbackAndAwaitContextCompletion_UnknownRoleZeroInitializedStorage;
extern "C" void Network_SendZeroMessageToContextQueue(void);
extern "C" void _Z22AwaitContextCompletionP16ProcessorContext(void *);
// Original: arm9/ov031 @ 0x022403B0; symbol: func_ov031_022403b0; size: 0x28.
extern "C" void System_RunCallbackAndAwaitContextCompletion(void) {
    HttpRunQueuedRequestWorker_UnknownRoleZeroInitializedStorage_Variant2 = 1;
    Network_SendZeroMessageToContextQueue();
    _Z22AwaitContextCompletionP16ProcessorContext(&SystemRunCallbackAndAwaitContextCompletion_UnknownRoleZeroInitializedStorage);
}
