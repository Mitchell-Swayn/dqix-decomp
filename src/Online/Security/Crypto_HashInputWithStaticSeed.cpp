#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e528; symbol: data_ov031_0224e528.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 19 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char SslFillNonzeroRandomBytes_UnknownRoleZeroInitializedStorage_Variant3[];
// Original data: arm9/ov031 @ 0x224e3b0; symbol: data_ov031_0224e3b0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char SslFillNonzeroRandomBytes_UnknownRoleZeroInitializedStorage_Variant2;
extern "C" void Crypto_InitializeSha1Context(unsigned int *);
extern "C" int _Z20DisableIRQInterruptsv(void);
extern "C" int _Z20SetIRQInterruptStatei(int);
extern "C" void Crypto_UpdateSha1Context(void *, const void *, unsigned);
extern "C" void Crypto_TransformAndSerializeBlockWords(void *, const void *);
// Original: arm9/ov031 @ 0x02209E28; symbol: func_ov031_02209e28; size: 0x70.
extern "C" void Crypto_HashInputWithStaticSeed(const void *data, unsigned length) {
    unsigned int state[23];
    Crypto_InitializeSha1Context(state);
    int irq = _Z20DisableIRQInterruptsv();
    Crypto_UpdateSha1Context(state, SslFillNonzeroRandomBytes_UnknownRoleZeroInitializedStorage_Variant3, 0x14);
    Crypto_UpdateSha1Context(state, data, length);
    Crypto_TransformAndSerializeBlockWords(state, SslFillNonzeroRandomBytes_UnknownRoleZeroInitializedStorage_Variant3);
    _Z20SetIRQInterruptStatei(irq);
    SslFillNonzeroRandomBytes_UnknownRoleZeroInitializedStorage_Variant2 = 1;
}
