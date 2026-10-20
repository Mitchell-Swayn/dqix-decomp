#include <globaldefs.h>
ARM
extern "C" void _Z19ZeroInitializeMutexP5Mutex(void*);
extern "C" bool _Z17IsContextInactiveP16ProcessorContext(void*);
extern "C" void _Z25MarkContextReadyAndSwitchP16ProcessorContext(void*);
extern "C" void _Z24PopulateProcessorContextP16ProcessorContextjjjjj(void*,unsigned,unsigned,unsigned,unsigned,unsigned);
// Original data: arm9/ov031 @ 0x224e608; symbol: data_ov031_0224e608.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned SystemInitializeDualMutexWorkerContext_UnknownRoleZeroInitializedStorage;
extern "C" void HttpDownload_RunRequestTransfer(void*);
// Original: arm9/ov031 @ 0x02217DB4; symbol: func_ov031_02217db4; size: 0xBC.
extern "C" void System_InitializeDualMutexWorkerContext(char *self, unsigned priority) {
    *(unsigned*)(self + 0x1c10) = 0;
    _Z19ZeroInitializeMutexP5Mutex(self + 0x1bf8);
    _Z19ZeroInitializeMutexP5Mutex(self + 0x1a18);
    if (*(unsigned*)(self + 0x1018) == 1) SystemInitializeDualMutexWorkerContext_UnknownRoleZeroInitializedStorage = 1;
    else SystemInitializeDualMutexWorkerContext_UnknownRoleZeroInitializedStorage = 0;
    if (*(unsigned*)(self + 0x1ba4)) {
        if (!_Z17IsContextInactiveP16ProcessorContext(self + 0x1b38)) return;
    }
    _Z24PopulateProcessorContextP16ProcessorContextjjjjj(self + 0x1b38,(unsigned)HttpDownload_RunRequestTransfer,(unsigned)self,(unsigned)(self + 0x1000),0x1000,priority);
    _Z25MarkContextReadyAndSwitchP16ProcessorContext(self + 0x1b38);
}
