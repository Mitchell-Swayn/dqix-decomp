#include <globaldefs.h>
extern "C" int func_ov031_022032a4(void *);
extern "C" void InitializeSha1FiveWordDigestState(unsigned *);
extern "C" void InitializeFourWordDigestState(unsigned *);
extern "C" int func_ov031_0220a474(void *);
// Original: arm9/ov031 @ 0x0220A540; symbol: func_ov031_0220a540; size: 0x54.
extern "C" int OV031_InitializeContextDigestState(void *owner) {
    unsigned char *p = (unsigned char *)owner;
    unsigned char mode = p[8];
    unsigned char *context = *(unsigned char **)(p + 0xc);
    if (mode != 4 && func_ov031_022032a4(owner)) return 1;
    context[0x455] = 0;
    *(unsigned *)(context + 0x1d4) = 0;
    context[0x454] = 0;
    InitializeSha1FiveWordDigestState((unsigned *)(context + 0x2ec));
    InitializeFourWordDigestState((unsigned *)(context + 0x3a4));
    return func_ov031_0220a474(owner);
}
