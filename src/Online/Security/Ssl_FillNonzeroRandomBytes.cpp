#include <globaldefs.h>
#include <System/Interrupts.h>
ARM
#pragma optimization_level 4
#pragma optimize_for_size off
struct Sha1Context { unsigned state[5], highBits, lowBits; unsigned char buffer[64]; };
extern "C" void Crypto_InitializeSha1Context(unsigned*);
extern "C" void Crypto_UpdateSha1Context(Sha1Context*, const unsigned char*, unsigned);
extern "C" void Network_InitializeDestinationAndSerialize20Bytes(void*, unsigned*);
extern "C" void Crypto_HashInputWithStaticSeed(const void*, unsigned);
// Original data: arm9/ov031 @ 0x0224E3B0; symbol: data_ov031_0224e3b0.
// Mutable initialization flag; zero at overlay load.
extern "C" unsigned char SslFillNonzeroRandomBytes_UnknownRoleZeroInitializedStorage_Variant2;
// Original data: arm9/ov031 @ 0x0224C9E8; symbol: data_ov031_0224c9e8.
// Mutable 64-bit LCG state, multiplier and increment at offsets 0, 8 and 16.
extern "C" unsigned long long SslFillNonzeroRandomBytes_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov031 @ 0x0224E528; symbol: data_ov031_0224e528.
// Mutable 20-byte big-endian random seed, zero at overlay load.
extern "C" unsigned char SslFillNonzeroRandomBytes_UnknownRoleZeroInitializedStorage_Variant3[];
// Original data: arm9/ov031 @ 0x0224E53B; symbol: data_ov031_0224e53b.
// Last byte of the shared mutable seed.
extern "C" unsigned char SslFillNonzeroRandomBytes_UnknownRoleZeroInitializedStorage_Variant4;
// Original: arm9/ov031 @ 0x02209CF8; symbol: func_ov031_02209cf8; size: 0x130.
// Hashes and increments shared seed state, discarding zero bytes from the generated blocks.
extern "C" void Ssl_FillNonzeroRandomBytes(unsigned char* output, int length)
{
    unsigned initial;
    unsigned char block[20];
    Sha1Context hash;
    if (!SslFillNonzeroRandomBytes_UnknownRoleZeroInitializedStorage_Variant2) {
        unsigned long long* lcg = SslFillNonzeroRandomBytes_UnknownRoleZeroInitializedStorage;
        lcg[0] = lcg[1] * lcg[0] + lcg[2];
        initial = lcg[0] >> 32;
        Crypto_HashInputWithStaticSeed(&initial, 4);
    }
    int written = 0;
    int index = 20;
    if (length <= 0) return;
    do {
        if (index == 20) {
            Crypto_InitializeSha1Context(hash.state);
            int irq = DisableIRQInterrupts();
            Crypto_UpdateSha1Context(&hash, SslFillNonzeroRandomBytes_UnknownRoleZeroInitializedStorage_Variant3, 20);
            Network_InitializeDestinationAndSerialize20Bytes(&hash, (unsigned*)block);
            int i;
            unsigned carry;
            unsigned char* generated;
            unsigned char* seed;
            unsigned sum;
            seed = &SslFillNonzeroRandomBytes_UnknownRoleZeroInitializedStorage_Variant4;
            carry = 1;
            i = 19;
            generated = block + 19;
            do {
                sum = carry + (*seed + *generated);
                // DS byte addresses are 32 bits; integer updates keep the final,
                // unused cursors from performing out-of-range C++ pointer arithmetic.
                generated = (unsigned char*)((unsigned)generated - 1);
                *seed = sum;
                seed = (unsigned char*)((unsigned)seed - 1);
                carry = sum >> 8;
            } while (--i >= 0);
            initial = sum;
            SetIRQInterruptState(irq);
            index = 0;
        }
        unsigned char byte = ((unsigned char*)block)[index++];
        if (byte) output[written++] = byte;
    } while (written < length);
}
