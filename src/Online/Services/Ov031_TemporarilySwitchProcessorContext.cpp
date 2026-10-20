#include <globaldefs.h>
ARM
extern "C" void _Z20AddContextSwitchLockv(void);
extern "C" void _Z23RemoveContextSwitchLockv(void);
extern "C" int _Z17IsContextInactiveP16ProcessorContext(void *);
extern "C" void _Z25MarkContextReadyAndSwitchP16ProcessorContext(void *);
// Original data: arm9/ov031 @ 0x224e588; symbol: data_ov031_0224e588.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char *YssdClientRunWorker_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x02210618; symbol: func_ov031_02210618; size: 0x5C.
extern "C" unsigned short Ov031_TemporarilySwitchProcessorContext(void) {
    volatile unsigned short *ime = (volatile unsigned short *)0x04000208;
    unsigned short previous = *ime;
    *ime = 0;
    _Z20AddContextSwitchLockv();
    if (!_Z17IsContextInactiveP16ProcessorContext(YssdClientRunWorker_UnknownRoleZeroInitializedStorage + 0xa10)) {
        _Z25MarkContextReadyAndSwitchP16ProcessorContext(YssdClientRunWorker_UnknownRoleZeroInitializedStorage + 0xa10);
    }
    _Z23RemoveContextSwitchLockv();
    unsigned short current = *ime;
    *ime = previous;
    return current;
}
