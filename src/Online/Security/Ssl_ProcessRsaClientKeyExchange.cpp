#include <globaldefs.h>
extern "C" void Ssl_DecryptRsaPremasterSecretWithCrt(void*, unsigned, unsigned);
extern "C" void System_BuildAndCopyThreeContextRecords(void*);
extern "C" void SslSessionCache_StoreMasterSecret(void*, unsigned, unsigned);
extern "C" void Ssl_DeriveRecordKeysAndInitializeRc4(void*);
// Original: arm9/ov031 @ 0x0220911C; symbol: func_ov031_0220911c; size: 0x3C.
extern "C" void Ssl_ProcessRsaClientKeyExchange(void* object, unsigned a, unsigned b) {
    Ssl_DecryptRsaPremasterSecretWithCrt(object, a, *(unsigned*)((char*)object + 0x81c));
    System_BuildAndCopyThreeContextRecords(object);
    SslSessionCache_StoreMasterSecret(object, 0, 0);
    Ssl_DeriveRecordKeysAndInitializeRc4(object);
    *((unsigned char*)object + 0x455) = 5;
}
