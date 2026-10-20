#include <globaldefs.h>
extern "C" void* memset(void*, int, unsigned int);
struct BitFlagOwner { unsigned char unknown[0x8c]; unsigned char flags[1]; };
// Original: arm9/main @ 0x0206DFE8; symbol: func_0206dfe8; size: 0x98.
// Clears a bit range in the flag array at offset 0x8c while retaining boundary bits.
extern "C" ARM void ClearOwnerFlagBitRange(BitFlagOwner* owner, int firstBit, int bitCount)
{
    unsigned int firstByte;
    int firstBits;
    int remaining;
    int wholeBytes;
    int lastBits;

    firstBits = 8 - firstBit % 8;
    firstByte = firstBit / 8 + 1;
    remaining = bitCount - firstBits;
    wholeBytes = remaining / 8;
    lastBits = remaining % 8;
    if (wholeBytes > 0) memset(owner->flags + firstByte, 0, wholeBytes);
    wholeBytes = firstByte + wholeBytes;
    owner->flags[wholeBytes] >>= lastBits;
    owner->flags[wholeBytes] <<= lastBits;
    owner->flags[firstByte - 1] <<= firstBits;
    owner->flags[firstByte - 1] >>= firstBits;
}
