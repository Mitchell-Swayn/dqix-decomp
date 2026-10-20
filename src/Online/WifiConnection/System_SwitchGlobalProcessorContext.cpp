#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e580; symbol: data_ov031_0224e580.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char *StoreReadySharedValue_UnknownRoleZeroInitializedStorage;
extern "C" void _Z25MarkContextReadyAndSwitchP16ProcessorContext(void *context);
// Original: arm9/ov031 @ 0x0220F4A0; symbol: func_ov031_0220f4a0; size: 0x1C.
extern "C" void System_SwitchGlobalProcessorContext(void) {
    _Z25MarkContextReadyAndSwitchP16ProcessorContext(StoreReadySharedValue_UnknownRoleZeroInitializedStorage + 0x34);
}
