#include <globaldefs.h>
ARM

// Replaces the low nibble of byte 0x56B in the record linked at offset 0x150, if any.
// Original: arm9/ov017 @ 0x0218F57C; symbol: func_ov017_0218f57c; size: 0x28.
extern "C" void LinkedRecord_SetByte56BLowNibble(char *object, int value)
{
    unsigned char *record = *(unsigned char **)(object + 0x150);
    if (record == NULL) {
        return;
    }
    record[0x56b] = (record[0x56b] & ~0xf) | ((unsigned char)value & 0xf);
}
