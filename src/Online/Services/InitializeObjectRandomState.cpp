#include <globaldefs.h>
ARM
extern "C" unsigned long long WirelessSettings_GetDecodedIdentifier(void);
extern "C" void SwcaRecord_InitializeTokenWithEntropy(void *state, unsigned int seedLow, unsigned int seedHigh);
extern "C" void SwcaRecord_MarkChecksumDirty(unsigned int *object);
// Original: arm9/ov031 @ 0x022115D8; symbol: func_ov031_022115d8; size: 0x30.
extern "C" void InitializeObjectRandomState(void *object, unsigned int value) {
    unsigned long long seed = WirelessSettings_GetDecodedIdentifier();
    SwcaRecord_InitializeTokenWithEntropy((unsigned char *)object + 0x10, (unsigned int)seed, (unsigned int)(seed >> 32));
    *(unsigned int *)((unsigned char *)object + 0x1c) = value;
    SwcaRecord_MarkChecksumDirty((unsigned int *)object);
}
