#include <globaldefs.h>
ARM
extern "C" unsigned int FileCache_UpdateCRCWithByte(unsigned int byte, unsigned int crc);
// Original: arm9/itcm @ 0x01FF860C; symbol: func_01ff860c; size: 0x34.
extern "C" unsigned int FileCache_CalculateStringCRC(const unsigned char *data) {
    unsigned int crc = 0xFFFFFFFF;
    if (data != 0) {
        while (*data != 0) {
            crc = FileCache_UpdateCRCWithByte(*data, crc);
            data++;
        }
    }
    return ~crc;
}
