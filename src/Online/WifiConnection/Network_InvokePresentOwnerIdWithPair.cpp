#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290d00; symbol: data_ov031_02290d00.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcUtilityDestroySoundContextAndUpdateTask_UnknownRoleZeroInitializedStorage[];
extern "C" void NNS_SndPlayerSetTrackPitch(void *, int, int);
// Original: arm9/ov031 @ 0x022368BC; symbol: Network_InvokePresentOwnerIdWithPair; size: 0x24.
// Uses the global owner +0x94 record pointer and forwards both values to InvokePresentOwnerIdWithPair.
extern "C" void Network_InvokePresentOwnerIdWithPair(int first, int second) {
    NNS_SndPlayerSetTrackPitch((char *)*(void **)WfcUtilityDestroySoundContextAndUpdateTask_UnknownRoleZeroInitializedStorage + 0x94, first, second);
}
