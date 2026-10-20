#include <globaldefs.h>
ARM

// Original data: arm9/ov031 @ 0x224c9c0; symbol: data_ov031_0224c9c0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void (*SslSendClientHello_UnknownRoleZeroInitializedStorage_Variant2)(void *);

// Original: arm9/ov031 @ 0x0220AA30; symbol: func_ov031_0220aa30; size: 0x38.
extern "C" void Ssl_ResetConnectionAndFreeReceiveBuffer(void *object) {
    char *state = (char *)*(void **)((char *)object + 0xc);
    state[0x455] = 0;
    void *argument = *(void **)(state + 0x824);
    if (argument != 0) {
        SslSendClientHello_UnknownRoleZeroInitializedStorage_Variant2(argument);
    }
    *(void **)(state + 0x824) = 0;
}
