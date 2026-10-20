#include <globaldefs.h>
ARM
// Original data: arm9/ov025 @ 0x21ef988; symbol: data_ov025_021ef988.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
extern "C" void* CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage[4];
extern "C" void Combat_InitializeActionEffectDescriptor(void*);
extern "C" void Combat_QueueActionResultEffectDescriptors(void*, int, int);
// Original: arm9/ov025 @ 0x021E3048; symbol: func_ov025_021e3048; size: 0x3C.
extern "C" int Combat_InitializeAndQueueActionEffects(void* unused0, int index, void* unused2, int value) {
    char* records = (char*)CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage[3];
    void* record = records + 0x540;
    Combat_InitializeActionEffectDescriptor(record);
    *(int*)(records + 0x540) = index;
    Combat_QueueActionResultEffectDescriptors(record, index, value);
    return 1;
}
