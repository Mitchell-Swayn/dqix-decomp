#include <globaldefs.h>

// HasNestedFlagBit10; field semantics beyond the observed offsets and masks remain unknown.
// Original: arm9/ov024 @ 0x021FCAC0; symbol: func_ov024_021fcac0; size: 0x18.
extern "C" int HasNestedFlagBit10(const void *object)
{
    const unsigned char *bytes = (const unsigned char *)object;
    const unsigned int *flags = (const unsigned int *)(*(const unsigned int *)(bytes + 0x138) + 0x18);
    return ((*flags & 0x400u) != 0);
}
