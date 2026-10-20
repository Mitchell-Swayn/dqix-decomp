#include <globaldefs.h>
ARM
// Original data: arm9/ov001 @ 0x21658b8; symbol: data_ov001_021658b8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern unsigned char EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov001 @ 0x21659a8; symbol: data_ov001_021659a8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 784 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern unsigned int EventResetScriptResourceState_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov001 @ 0x2165958; symbol: data_ov001_02165958.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 80 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern unsigned char UtilFindEmptySlotInTable16_UnknownRoleZeroInitializedStorage[];
extern "C" void ResourceHandle_InitializeSequenceHandle(void*);
// Original: arm9/ov001 @ 0x0215A79C; symbol: func_ov001_0215a79c; size: 0x7C.
extern "C" void Event_ResetScriptResourceState(void) {
    *(unsigned int*)(EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage + 0xe8) = 0;
    *(unsigned int*)(EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage + 0xec) = 0;
    *(unsigned int*)(EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage + 0xe0) = 0;
    for (int i = 0; i < 0xe9; i++) EventResetScriptResourceState_UnknownRoleZeroInitializedStorage[i] = 0;
    *(unsigned int*)(EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage + 0xe4) = 0;
    for (int i = 0; i < 0x10; i++) ResourceHandle_InitializeSequenceHandle(UtilFindEmptySlotInTable16_UnknownRoleZeroInitializedStorage + i * 4);
    *(unsigned int*)(EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage + 0x4b4) = 0;
    *(unsigned int*)(EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage + 0x4b8) = 0;
}
