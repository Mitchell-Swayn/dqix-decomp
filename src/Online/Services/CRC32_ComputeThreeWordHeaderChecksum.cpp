#include <globaldefs.h>
ARM
extern "C" void CRC32_BuildReflectedPolynomialTable(unsigned *table, unsigned polynomial);
extern "C" unsigned CRC32_ComputeComplementedChecksum(const unsigned *table, const void *data, unsigned size);
// Original: arm9/ov031 @ 0x02211720; symbol: func_ov031_02211720; size: 0x34.
extern "C" unsigned CRC32_ComputeThreeWordHeaderChecksum(const void *data) {
    unsigned table[256];
    CRC32_BuildReflectedPolynomialTable(table, 0xedb88320);
    return CRC32_ComputeComplementedChecksum(table, data, 0x3c);
}
