#include <globaldefs.h>
ARM
extern "C" int ProcessorContext_IsPrimaryContextInitialized(void);
extern "C" void OS_InitMessageQueue(const void*, const void*, int);
extern "C" void _Z24PopulateProcessorContextP16ProcessorContextjjjjj(void*, const void*, unsigned, void*, unsigned, void*);
extern "C" void _Z25MarkContextReadyAndSwitchP16ProcessorContext(void*);
// Original data: arm9/ov031 @ 0x22918bc; symbol: data_ov031_022918bc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char HttpWaitForRequestQueueMessage_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov031 @ 0x22918a0; symbol: data_ov031_022918a0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char SystemCreateAndSwitchProcessorContextForCallback_UnknownRoleZeroInitializedStorage_Variant2[];
// Original data: arm9/ov031 @ 0x22918dc; symbol: data_ov031_022918dc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 192 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char SystemRunCallbackAndAwaitContextCompletion_UnknownRoleZeroInitializedStorage[];
extern "C" unsigned char Http_RunQueuedRequestWorker[];
// Original: arm9/ov031 @ 0x02240338; symbol: System_InitializeAndSwitchPrimaryProcessorContext; size: 0x78.
// When the setup flag is set, initializes queue state, populates a processor context from fixed tables and stack memory, then marks it ready and switches.
extern "C" int System_InitializeAndSwitchPrimaryProcessorContext(void* stackContext, void* suppliedContext) {
    if (!ProcessorContext_IsPrimaryContextInitialized()) return 0;
    OS_InitMessageQueue(HttpWaitForRequestQueueMessage_UnknownRoleZeroInitializedStorage,SystemCreateAndSwitchProcessorContextForCallback_UnknownRoleZeroInitializedStorage_Variant2,1);
    _Z24PopulateProcessorContextP16ProcessorContextjjjjj(SystemRunCallbackAndAwaitContextCompletion_UnknownRoleZeroInitializedStorage,Http_RunQueuedRequestWorker,0,(char*)suppliedContext+0x2000,0x2000,stackContext);
    _Z25MarkContextReadyAndSwitchP16ProcessorContext(SystemRunCallbackAndAwaitContextCompletion_UnknownRoleZeroInitializedStorage);
    return 1;
}
