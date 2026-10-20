#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290d38; symbol: data_ov031_02290d38.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int WfcUtilityDestroyTextCanvasServices_UnknownRoleZeroInitializedStorage;
extern "C" unsigned int WfcUtility_DestroyBackgroundTextCanvas(void *);
// Original: arm9/ov031 @ 0x0223C7C4; symbol: Graphics_ClearIndexedMainBackgroundCharacterData; size: 0x24.
// Computes a 0x30-byte owner record by index and passes it to ClearMainBackgroundCharacterDataForOwner.
extern "C" unsigned int Graphics_ClearIndexedMainBackgroundCharacterData(unsigned int index) {
    unsigned char *base = (unsigned char *)(*(unsigned int *)&WfcUtilityDestroyTextCanvasServices_UnknownRoleZeroInitializedStorage) + 0x610;
    return WfcUtility_DestroyBackgroundTextCanvas(base + 0x30 * index);
}
