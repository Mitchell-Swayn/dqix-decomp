#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e588; symbol: data_ov031_0224e588.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void* volatile YssdClientRunWorker_UnknownRoleZeroInitializedStorage;
extern "C" void System_SetSharedStateUnlessTwoUnderMutex(unsigned);
extern "C" int _Z17IsContextInactiveP16ProcessorContext(void*);
extern "C" void _Z15UnblockContextsP18BlockedContextList(void*);
extern "C" void Ov031_TemporarilySwitchProcessorContext(void);
// Original: arm9/ov031 @ 0x022101E0; symbol: func_ov031_022101e0; size: 0x70.
extern "C" int YssdClient_TryStopWorker(void) {
    if (YssdClientRunWorker_UnknownRoleZeroInitializedStorage == 0) return 1;
    System_SetSharedStateUnlessTwoUnderMutex(2);
    if (!_Z17IsContextInactiveP16ProcessorContext((char*)YssdClientRunWorker_UnknownRoleZeroInitializedStorage + 0xa10)) {
        Ov031_TemporarilySwitchProcessorContext();
        return 0;
    }
    _Z15UnblockContextsP18BlockedContextList((char*)YssdClientRunWorker_UnknownRoleZeroInitializedStorage + 0xa04);
    YssdClientRunWorker_UnknownRoleZeroInitializedStorage = 0;
    return 1;
}
