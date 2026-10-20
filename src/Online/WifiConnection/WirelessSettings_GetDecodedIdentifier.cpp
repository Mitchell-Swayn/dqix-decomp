#include <globaldefs.h>
ARM
extern "C" void System_CopyDecodedIdentifierAndPresence(unsigned int *);
// Original: arm9/ov031 @ 0x02212D20; symbol: System_GetRandomStatePair; size: 0x20.
// Calls the random-state helper with a five-word buffer and returns its first two words; callers use the pair as random seeds/tokens.
extern "C" unsigned long long WirelessSettings_GetDecodedIdentifier(void) {
    unsigned int result[5];
    System_CopyDecodedIdentifierAndPresence(result);
    return *(unsigned long long *)result;
}
