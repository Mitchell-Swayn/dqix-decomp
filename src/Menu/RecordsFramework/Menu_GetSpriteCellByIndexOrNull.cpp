#include <globaldefs.h>

// GetIndexedRecordAddressOrZero; field semantics beyond the observed offsets and masks remain unknown.
// Original: arm9/ov023 @ 0x021FA854; symbol: func_ov023_021fa854; size: 0x28.
extern "C" void * Menu_GetSpriteCellByIndexOrNull(const void *object, unsigned int index)
{
    const unsigned char *bytes = (const unsigned char *)object;
    unsigned int records = *(const unsigned int *)(bytes + 0x40);
    unsigned int address = 0;
    if (records != 0 && index < *(const unsigned short *)(bytes + 0x4e))
        address = records + index * 0x28;
    return (void *)address;
}
