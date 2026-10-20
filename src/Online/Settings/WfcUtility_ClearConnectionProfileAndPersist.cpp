#include <globaldefs.h>
extern "C" void VectorizedMemset(void *, int, unsigned);
extern "C" void WfcUtility_UpdateProfileAvailabilityChecksumsAndPersist(unsigned);
// Original data: arm9/ov031 @ 0x2290cfc; symbol: data_ov031_02290cfc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char NetworkSetEncodedKey_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x02236484; symbol: func_ov031_02236484; size: 0x3C.
extern "C" void WfcUtility_ClearConnectionProfileAndPersist(unsigned index) {
    unsigned char *context = *(unsigned char **)NetworkSetEncodedKey_UnknownRoleZeroInitializedStorage + index * 0x100;
    VectorizedMemset(context, 0, 0xef);
    context[0xe7] = 0xff;
    WfcUtility_UpdateProfileAvailabilityChecksumsAndPersist(index);
}
