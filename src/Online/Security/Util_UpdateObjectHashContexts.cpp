#include <globaldefs.h>
ARM
extern "C" void Crypto_UpdateSha1Context(void *);
extern "C" void Util_Update64ByteBlockHash(void *, unsigned int, unsigned int);
// Original: arm9/ov031 @ 0x022098AC; symbol: Util_UpdateObjectHashContexts; size: 0x2C.
// Updates hash state at object+0x2ec, then updates the integrated 64-byte block hash at object+0x3a4 with the supplied data and length.
extern "C" void Util_UpdateObjectHashContexts(void *self, unsigned int a, unsigned int b) {
    Crypto_UpdateSha1Context((char *)self + 0x2ec);
    Util_Update64ByteBlockHash((char *)self + 0x3a4, a, b);
}
