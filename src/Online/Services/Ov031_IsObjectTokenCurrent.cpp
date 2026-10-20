#include <globaldefs.h>
extern "C" unsigned long long SwcaRecord_GetTokenValue(void*);
extern "C" unsigned long long WirelessSettings_GetDecodedIdentifier();
// Original: arm9/ov031 @ 0x02211608; symbol: func_ov031_02211608; size: 0x3C.
extern "C" ARM int Ov031_IsObjectTokenCurrent(void* object) {
    unsigned long long token = SwcaRecord_GetTokenValue((char*)object + 0x10);
    if (token == 0) return 1;
    return token == WirelessSettings_GetDecodedIdentifier();
}
