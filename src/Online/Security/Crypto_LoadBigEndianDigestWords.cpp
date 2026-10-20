#include <globaldefs.h>
ARM
#pragma force_active on
#pragma optimization_level 4
// Original: arm9/ov031 @ 0x0220B1D0; symbol: func_ov031_0220b1d0; size: 0x48.
// Loads four-byte big-endian groups into native digest words; length is in bytes.
extern "C" void Crypto_LoadBigEndianDigestWords(unsigned* output, const void* source, unsigned length)
{
    const unsigned char* input = (const unsigned char*)source;
    unsigned i = 0;
    if (i < length) do {
        *output++ = ((unsigned)input[i] << 24) | ((unsigned)input[i + 1] << 16) | ((unsigned)input[i + 2] << 8) | input[i + 3];
        i += 4;
    } while (i < length);
}
