#include <globaldefs.h>
#include <System/ProcessorContext.h>
ARM
// Original data: arm9/ov031 @ 0x2249680; symbol: data_ov031_02249680.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 10000000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int SystemSetProcessorContextPriorities_UnknownRoleInitializedBytes;
// Original data: arm9/ov031 @ 0x224cbe8; symbol: data_ov031_0224cbe8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 192 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char NetworkStopWorkersAndResetStack_UnknownRoleZeroInitializedStorage;
// Original data: arm9/ov031 @ 0x224cb28; symbol: data_ov031_0224cb28.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 192 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char SystemPollContextAndDrainQueue_UnknownRoleZeroInitializedStorage;

// Original: arm9/ov031 @ 0x0220057C; symbol: func_ov031_0220057c; size: 0x38.
extern "C" void System_SetProcessorContextPriorities(unsigned int priority) {
    SystemSetProcessorContextPriorities_UnknownRoleInitializedBytes = priority;
    ChangeContextPriority((ProcessorContext *)&NetworkStopWorkersAndResetStack_UnknownRoleZeroInitializedStorage, priority);
    ChangeContextPriority((ProcessorContext *)&SystemPollContextAndDrainQueue_UnknownRoleZeroInitializedStorage, priority);
}
