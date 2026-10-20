// Original: arm9/main @ 0x02009668; symbol: func_02009668; compiler-generated unused return, 4B inventory alias.
#include "System/RuntimeDecimal.h"
#pragma thumb off
// Original: arm9/main @ 0x0200961C; symbol: func_0200961c; inventory size: 0x4C.
// Original compiler tail: arm9/main @ 0x02009668; symbol: func_02009668; size: 0x4.
// The compiler emits one 0x50-byte function including an unreachable final return.
// Preserve both inventory entries through ELF extent/alias metadata only.
// MSL decimal round-up carry helper (__dorounddecup).
extern "C" void __dorounddecup(RuntimeDecimal* decimal, int count)
{
    unsigned char* first = decimal->digits;
    unsigned char* digit = first + count - 1;
    for (;;) {
        if (*digit < 9) {
            ++*digit;
            return;
        }
        if (digit == first) {
            *digit = 1;
            ++decimal->exponent;
            return;
        }
        *digit-- = 0;
    }
}
