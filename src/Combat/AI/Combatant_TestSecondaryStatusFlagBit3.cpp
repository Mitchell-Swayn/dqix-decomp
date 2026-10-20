#include <globaldefs.h>

// HasNestedFlagBit3; field semantics beyond the observed offsets and masks remain unknown.
// Original: arm9/ov024 @ 0x021F273C; symbol: func_ov024_021f273c; size: 0x18.
extern "C" int Combatant_TestSecondaryStatusFlagBit3(const void *object)
{
    const unsigned char *bytes = (const unsigned char *)object;
    const unsigned int *flags = (const unsigned int *)(*(const unsigned int *)(bytes + 0x138) + 0x18);
    return ((*flags & 8u) != 0);
}
