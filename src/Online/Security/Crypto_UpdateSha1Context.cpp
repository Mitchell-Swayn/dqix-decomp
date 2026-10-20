#include <globaldefs.h>
#include <System/Memory.h>
ARM
#pragma force_active on
#pragma optimization_level 4
extern "C" void Crypto_CompressSha1Block(unsigned*, const void*);
struct Sha1Context { unsigned state[5], highBits, lowBits; unsigned char buffer[64]; };
// Original: arm9/ov031 @ 0x0220B8F4; symbol: func_ov031_0220b8f4; size: 0xB8.
// Accumulates SHA-1 input bit length and compresses complete buffered blocks.
extern "C" void Crypto_UpdateSha1Context(Sha1Context* context, const unsigned char* input, unsigned length)
{
    unsigned previous = context->lowBits;
    unsigned buffered = (previous >> 3) & 63;
    context->lowBits += length << 3;
    if (context->lowBits < (length << 3)) ++context->highBits;

    unsigned take = 64 - buffered;
    context->highBits += length >> 29;
    if (length >= take) {
        MI_CpuCopy8(input, context->buffer + buffered, take);
        buffered = 0;
        Crypto_CompressSha1Block(context->state, context->buffer);
        if (take + 63 < length) do {
            Crypto_CompressSha1Block(context->state, input + take);
            take += 64;
        } while (take + 63 < length);
    } else take = 0;
    MI_CpuCopy8(input + take, context->buffer + buffered, length - take);
}
