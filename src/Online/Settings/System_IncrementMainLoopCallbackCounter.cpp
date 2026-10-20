#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290cb4; symbol: data_ov031_02290cb4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char Ov031InitializeTransitionSequence_UnknownRoleZeroInitializedStorage;
extern "C" void ConfigureThirdContextEffects(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
// Original: arm9/ov031 @ 0x02231B5C; symbol: func_ov031_02231b5c; size: 0x34.
extern "C" void System_IncrementMainLoopCallbackCounter(void) {
    unsigned int count = Ov031InitializeTransitionSequence_UnknownRoleZeroInitializedStorage;
    unsigned int next = count + 1;
    unsigned int wrapped = next & 0xFF;
    Ov031InitializeTransitionSequence_UnknownRoleZeroInitializedStorage = next;
    if (wrapped >= 0x78) WfcUtility_SetMainLoopCallback(ConfigureThirdContextEffects);
}
