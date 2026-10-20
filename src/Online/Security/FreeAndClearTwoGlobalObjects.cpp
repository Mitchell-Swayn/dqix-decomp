#include <globaldefs.h>
THUMB
// Original data: arm9/ov031 @ 0x224e6e0; symbol: data_ov031_0224e6e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char AossRunSetupNegotiation_UnknownRoleZeroInitializedStorage[];
extern "C" void Aoss_FreeBuffer(int argument);
// Original: arm9/ov031 @ 0x0221CFDC; symbol: func_ov031_0221cfdc; size: 0x2C.
extern "C" void FreeAndClearTwoGlobalObjects(void) {
    if (*(unsigned int *)(AossRunSetupNegotiation_UnknownRoleZeroInitializedStorage + 0xc)) {
        Aoss_FreeBuffer(*(unsigned int *)(AossRunSetupNegotiation_UnknownRoleZeroInitializedStorage + 0xc));
        *(unsigned int *)(AossRunSetupNegotiation_UnknownRoleZeroInitializedStorage + 0xc) = 0;
    }
    if (*(unsigned int *)(AossRunSetupNegotiation_UnknownRoleZeroInitializedStorage + 4)) {
        Aoss_FreeBuffer(*(unsigned int *)(AossRunSetupNegotiation_UnknownRoleZeroInitializedStorage + 4));
        *(unsigned int *)(AossRunSetupNegotiation_UnknownRoleZeroInitializedStorage + 4) = 0;
    }
}
