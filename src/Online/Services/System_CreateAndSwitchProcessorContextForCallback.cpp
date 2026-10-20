#include <globaldefs.h>
ARM
extern "C" void _Z24PopulateProcessorContextP16ProcessorContextjjjjj(void *, unsigned, unsigned, unsigned, unsigned, unsigned);
extern "C" void _Z25MarkContextReadyAndSwitchP16ProcessorContext(void *);
// Original data: arm9/ov031 @ 0x2290fe0; symbol: data_ov031_02290fe0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 2240 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char SystemCreateAndSwitchProcessorContextForCallback_UnknownRoleZeroInitializedStorage[];
extern "C" void System_RunDeferredCallback(void);
// Original data: arm9/ov031 @ 0x22918a0; symbol: data_ov031_022918a0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char SystemCreateAndSwitchProcessorContextForCallback_UnknownRoleZeroInitializedStorage_Variant2[];
// Original: arm9/ov031 @ 0x0223FD9C; symbol: func_ov031_0223fd9c; size: 0x48.
extern "C" void System_CreateAndSwitchProcessorContextForCallback(unsigned value) {
    _Z24PopulateProcessorContextP16ProcessorContextjjjjj(SystemCreateAndSwitchProcessorContextForCallback_UnknownRoleZeroInitializedStorage, (unsigned)System_RunDeferredCallback, value, (unsigned)SystemCreateAndSwitchProcessorContextForCallback_UnknownRoleZeroInitializedStorage_Variant2, 0x800, 0x10);
    _Z25MarkContextReadyAndSwitchP16ProcessorContext(SystemCreateAndSwitchProcessorContextForCallback_UnknownRoleZeroInitializedStorage);
}
