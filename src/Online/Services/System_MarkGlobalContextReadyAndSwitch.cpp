#include <globaldefs.h>
ARM
extern "C" void _Z25MarkContextReadyAndSwitchP16ProcessorContext(void*);
// Original data: arm9/ov031 @ 0x224e588; symbol: data_ov031_0224e588.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void* YssdClientRunWorker_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x022101C4; symbol: func_ov031_022101c4; size: 0x1C.
extern "C" void System_MarkGlobalContextReadyAndSwitch(void) { _Z25MarkContextReadyAndSwitchP16ProcessorContext((char*)YssdClientRunWorker_UnknownRoleZeroInitializedStorage + 0xa10); }
