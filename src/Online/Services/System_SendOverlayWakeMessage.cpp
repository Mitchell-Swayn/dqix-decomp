#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2291f80; symbol: data_ov031_02291f80.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 192 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char SystemSendOverlayWakeMessage_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov031 @ 0x2291f24; symbol: data_ov031_02291f24.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WirelessRunConnectionWorker_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov031 @ 0x2291f60; symbol: data_ov031_02291f60.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WirelessRunConnectionWorker_UnknownRoleZeroInitializedStorage_Variant2[];
extern "C" int _Z17IsContextInactiveP16ProcessorContext(void* context);
extern "C" int OS_SendMessage(void* queue, void* message, int flags);
// Original: arm9/ov031 @ 0x02245938; symbol: func_ov031_02245938; size: 0x54.
extern "C" void System_SendOverlayWakeMessage(void) {
    if (*(void**)(SystemSendOverlayWakeMessage_UnknownRoleZeroInitializedStorage + 0x6C) == 0) return;
    if (_Z17IsContextInactiveP16ProcessorContext(SystemSendOverlayWakeMessage_UnknownRoleZeroInitializedStorage) != 0) return;
    if (*(void**)(WirelessRunConnectionWorker_UnknownRoleZeroInitializedStorage + 4) != 0) return;
    *(unsigned*)(WirelessRunConnectionWorker_UnknownRoleZeroInitializedStorage + 4) = 1;
    OS_SendMessage(WirelessRunConnectionWorker_UnknownRoleZeroInitializedStorage_Variant2, 0, 0);
}
