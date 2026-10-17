#include <globaldefs.h>
ARM
extern "C" unsigned long data_ov031_0229199c[];
extern "C" void OS_GetLowEntropyData(unsigned long *data);
extern "C" void Crypto_HashInputWithStaticSeed(void *data, unsigned int size);
// Original: arm9/ov031 @ 0x02241318; symbol: func_ov031_02241318; size: 0x20.
extern "C" void SeedRandomStateFromLowEntropy(void) {
    OS_GetLowEntropyData(data_ov031_0229199c);
    Crypto_HashInputWithStaticSeed(data_ov031_0229199c, 0x20);
}
