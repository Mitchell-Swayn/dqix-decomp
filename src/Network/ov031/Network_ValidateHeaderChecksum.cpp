#include <globaldefs.h>
ARM
extern "C" int Util_IsHeaderMagicAndValueValid(void*);
extern "C" unsigned CRC32_ComputeThreeWordHeaderChecksum(const void*);
// Original: arm9/ov031 @ 0x0221156C; symbol: func_ov031_0221156c; size: 0x38.
extern "C" int Network_ValidateHeaderChecksum(unsigned* header) {
    if (!Util_IsHeaderMagicAndValueValid(header)) return 0;
    return header[0xf] == CRC32_ComputeThreeWordHeaderChecksum(header);
}
