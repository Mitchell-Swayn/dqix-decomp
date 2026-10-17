#pragma optimization_level 4
// Original: arm9/main @ 0x02049EC0; symbol: func_02049ec0; size: 0x28.
// Tests the unsigned high nibble of byte C1; object identity is unproven.
struct NibbleOwner { unsigned char prefix[0xc1]; unsigned char low : 4; unsigned char high : 4; };
extern "C" int TestByteC1HighNibbleOutsideTwoThroughFive(const NibbleOwner* owner)
{
    // Integral promotions preserve the original comparison chain in MWCC.
    if (owner->high == 2 || (unsigned)owner->high == 3 || (int)owner->high == 4 || (unsigned char)owner->high == 5)
        return 0;
    return 1;
}
