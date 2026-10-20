#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e598; symbol: data_ov031_0224e598.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int YssdClientSetError_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x02211864; symbol: System_SetGlobalPairUnlessStateNine; size: 0x28.
// Adjusts the second input by -10000 when it is greater than -10000, then stores both inputs to the global pair unless its first word is 9.
extern "C" void YssdClient_SetError(unsigned int first, int value) {
    if (value > -10000) value += -10000;
    if (YssdClientSetError_UnknownRoleZeroInitializedStorage[0] != 9) {
        YssdClientSetError_UnknownRoleZeroInitializedStorage[0] = first;
        YssdClientSetError_UnknownRoleZeroInitializedStorage[1] = value;
    }
}
