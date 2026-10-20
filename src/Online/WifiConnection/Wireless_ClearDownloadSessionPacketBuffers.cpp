#include <globaldefs.h>
ARM
extern "C" void VectorizedMemset(void*, int, unsigned int);
// Original data: arm9/ov031 @ 0x2290d20; symbol: data_ov031_02290d20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x0223B07C; symbol: func_ov031_0223b07c; size: 0x44.
extern "C" void Wireless_ClearDownloadSessionPacketBuffers(void) {
    VectorizedMemset(*(char**)&Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage + 0x100, 0, 0x100);
    VectorizedMemset(*(char**)&Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage, 0, 0x100);
    *(char**)(*(char**)&Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage + 0xab0) = *(char**)&Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage;
}
