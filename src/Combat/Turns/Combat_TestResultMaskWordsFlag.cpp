#include <globaldefs.h>
ARM
#pragma force_active on
// Original: arm9/ov000 @ 0x02159F18; symbol: func_ov000_02159f18; size: 0x64.
// Status bit identifiers are bounded to0..62; known original callers use0..41.
// Tests the split result mask using the bit numbering shared with Combat_SetResultMaskFlag.
extern "C" bool Combat_TestResultMaskWordsFlag(void*, unsigned long long mask, unsigned bit)
{
    if (bit > 31) mask &= ((unsigned long long)(int)(1U << (bit - 31)) << 32) & 0xffffffff00000000ULL;
    else mask &= (unsigned long long)(int)(1U << bit) & 0xffffffffULL;
    return mask != 0;
}
#pragma force_active off
