#include <globaldefs.h>
ARM
extern "C" {
// Original: arm9/main @ 0x020D1B68; symbol: func_020d1b68; size: 0x38.
void CRC8_UpdateWithLookupTable(const unsigned char *table, unsigned char *crc, const unsigned char *data, unsigned int length) {
    unsigned char value = *crc;
    unsigned int i = 0;
    if (!(length <= i)) do {
        unsigned char input = *data++;
        i++;
        value = table[(unsigned char)(value ^ input)];
    } while (i < length);
    *crc = value;
}
}
