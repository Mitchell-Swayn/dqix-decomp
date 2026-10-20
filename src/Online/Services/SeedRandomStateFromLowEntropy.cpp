#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x229199c; symbol: data_ov031_0229199c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned long SeedRandomStateFromLowEntropy_UnknownRoleZeroInitializedStorage[];
extern "C" void OS_GetLowEntropyData(unsigned long *data);
extern "C" void Crypto_HashInputWithStaticSeed(void *data, unsigned int size);
// Original: arm9/ov031 @ 0x02241318; symbol: func_ov031_02241318; size: 0x20.
extern "C" void SeedRandomStateFromLowEntropy(void) {
    OS_GetLowEntropyData(SeedRandomStateFromLowEntropy_UnknownRoleZeroInitializedStorage);
    Crypto_HashInputWithStaticSeed(SeedRandomStateFromLowEntropy_UnknownRoleZeroInitializedStorage, 0x20);
}
