#include <globaldefs.h>
ARM
extern "C" void _Z20AddContextSwitchLockv(void);
extern "C" void _Z23RemoveContextSwitchLockv(void);
extern "C" int _Z17IsContextInactiveP16ProcessorContext(void*);
extern "C" void _Z25MarkContextReadyAndSwitchP16ProcessorContext(void*);
// Original data: arm9/ov031 @ 0x224e580; symbol: data_ov031_0224e580.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void* StoreReadySharedValue_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x0220F558; symbol: func_ov031_0220f558; size: 0x5C.
extern "C" unsigned System_UnlockAndSwitchReadyContext(void) {
    volatile unsigned short* ime = (volatile unsigned short*)0x04000208;
    unsigned short previous = *ime;
    *ime = 0;
    _Z20AddContextSwitchLockv();
    if (!_Z17IsContextInactiveP16ProcessorContext((char*)StoreReadySharedValue_UnknownRoleZeroInitializedStorage + 0x34))
        _Z25MarkContextReadyAndSwitchP16ProcessorContext((char*)StoreReadySharedValue_UnknownRoleZeroInitializedStorage + 0x34);
    _Z23RemoveContextSwitchLockv();
    unsigned current = *ime;
    *ime = previous;
    return current;
}
