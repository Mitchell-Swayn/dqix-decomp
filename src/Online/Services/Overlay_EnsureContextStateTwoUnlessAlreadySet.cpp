#include <globaldefs.h>
ARM
extern "C" void YssdClient_SetError(unsigned int, int);
extern "C" void System_SetSharedStateUnlessTwoUnderMutex(int);
// Original data: arm9/ov031 @ 0x224e588; symbol: data_ov031_0224e588.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int YssdClientRunWorker_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x02210358; symbol: Overlay_EnsureContextStateTwoUnlessAlreadySet; size: 0x34.
// Leaves context state two intact; otherwise performs cleanup and selects state two.
extern "C" void Overlay_EnsureContextStateTwoUnlessAlreadySet(unsigned int first, int second) { void *context=(void*)YssdClientRunWorker_UnknownRoleZeroInitializedStorage; if (context != 0 && *(int*)((char*)context + 4) == 2) return; YssdClient_SetError(first, second); System_SetSharedStateUnlessTwoUnderMutex(2); }
