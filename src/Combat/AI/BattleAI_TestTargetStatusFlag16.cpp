#include <globaldefs.h>

// HasNestedFlagBit16; field semantics beyond the observed offsets and masks remain unknown.
// Original: arm9/ov024 @ 0x021FB460; symbol: func_ov024_021fb460; size: 0x18.
extern "C" int BattleAI_TestTargetStatusFlag16(const void *object)
{
    const unsigned char *bytes = (const unsigned char *)object;
    const unsigned int *flags = (const unsigned int *)(*(const unsigned int *)(bytes + 0x138) + 0x14);
    return ((*flags & 0x10000u) != 0);
}
