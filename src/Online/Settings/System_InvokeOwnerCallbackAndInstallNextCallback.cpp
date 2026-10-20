#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2250c00; symbol: data_ov031_02250c00.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcNumberPadDestroy_UnknownRoleZeroInitializedStorage[];
extern "C" void Network_UnlinkNodeAndReleaseRecords(void *);
extern "C" void WfcUtility_SetTaskCallback(void *, unsigned);
extern "C" void WfcNumberPad_SlideCommandButtonsOut(void);
// Original: arm9/ov031 @ 0x02225BF0; symbol: System_InvokeOwnerCallbackAndInstallNextCallback; size: 0x34.
// Invokes the callback stored at global owner +0x58, then writes the next callback address into the callback slot at +0x5c.
extern "C" void System_InvokeOwnerCallbackAndInstallNextCallback(void) {
    unsigned char *object = *(unsigned char **)WfcNumberPadDestroy_UnknownRoleZeroInitializedStorage;
    Network_UnlinkNodeAndReleaseRecords(*(void **)(object + 0x58));
    object = *(unsigned char **)WfcNumberPadDestroy_UnknownRoleZeroInitializedStorage;
    WfcUtility_SetTaskCallback(*(void **)(object + 0x5c), (unsigned)WfcNumberPad_SlideCommandButtonsOut);
}
