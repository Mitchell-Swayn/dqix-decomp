#include <globaldefs.h>
extern "C" int Network_ConnectTcpSocketWithRetries(void *);
extern "C" void Crypto_InitializeSha1Context(unsigned *);
extern "C" void Ssl_InitializeMd5Context(unsigned *);
extern "C" int Ssl_RunClientHandshake(void *);
// Original: arm9/ov031 @ 0x0220A540; symbol: func_ov031_0220a540; size: 0x54.
extern "C" int Ssl_InitializeAndRunClientHandshake(void *owner) {
    unsigned char *p = (unsigned char *)owner;
    unsigned char mode = p[8];
    unsigned char *context = *(unsigned char **)(p + 0xc);
    if (mode != 4 && Network_ConnectTcpSocketWithRetries(owner)) return 1;
    context[0x455] = 0;
    *(unsigned *)(context + 0x1d4) = 0;
    context[0x454] = 0;
    Crypto_InitializeSha1Context((unsigned *)(context + 0x2ec));
    Ssl_InitializeMd5Context((unsigned *)(context + 0x3a4));
    return Ssl_RunClientHandshake(owner);
}
