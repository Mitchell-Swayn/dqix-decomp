#include <globaldefs.h>
ARM
struct ProcessorContext;
extern "C" void _Z19ZeroInitializeMutexP5Mutex(void*);
extern "C" bool _Z17IsContextInactiveP16ProcessorContext(void*);
extern "C" void _Z25MarkContextReadyAndSwitchP16ProcessorContext(void*);
extern "C" void _Z24PopulateProcessorContextP16ProcessorContextjjjjj(void*,unsigned,unsigned,unsigned,unsigned,unsigned);
extern "C" void NasAuth_RunRetryWorker(void*);
// Original data: arm9/ov031 @ 0x224e5e8; symbol: data_ov031_0224e5e8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char * volatile NasAuthDestroySession_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov031 @ 0x224e5f0; symbol: data_ov031_0224e5f0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char SystemInitializeAndStartGuardedProcessorContext_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x022168EC; symbol: func_ov031_022168ec; size: 0xB4.
extern "C" void System_InitializeAndStartGuardedProcessorContext() {
    _Z19ZeroInitializeMutexP5Mutex(NasAuthDestroySession_UnknownRoleZeroInitializedStorage[2] + 0x13d8);
    *(unsigned*)(NasAuthDestroySession_UnknownRoleZeroInitializedStorage[2] + 0x13f0) = 0;
    char *context = NasAuthDestroySession_UnknownRoleZeroInitializedStorage[2];
    if (*(int*)(context + 0x1384)) {
        if (!_Z17IsContextInactiveP16ProcessorContext(context + 0x1318)) return;
    }
    char *base = NasAuthDestroySession_UnknownRoleZeroInitializedStorage[2];
    _Z24PopulateProcessorContextP16ProcessorContextjjjjj(base + 0x1318,(unsigned)NasAuth_RunRetryWorker,(unsigned)SystemInitializeAndStartGuardedProcessorContext_UnknownRoleZeroInitializedStorage,(unsigned)(base + 0x1000),0x1000,16);
    _Z25MarkContextReadyAndSwitchP16ProcessorContext(NasAuthDestroySession_UnknownRoleZeroInitializedStorage[2] + 0x1318);
}
