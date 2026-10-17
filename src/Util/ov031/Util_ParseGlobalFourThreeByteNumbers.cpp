#include <globaldefs.h>
ARM
extern "C" char *data_ov031_02290cfc;
extern "C" void Util_ParseFourThreeByteNumbers(const char *src, unsigned char *dst);
// Original: arm9/ov031 @ 0x02235EAC; symbol: func_ov031_02235eac; size: 0x20.
extern "C" void Util_ParseGlobalFourThreeByteNumbers(const char *src) {
    Util_ParseFourThreeByteNumbers(src, (unsigned char *)(data_ov031_02290cfc + 0x4c4));
}
