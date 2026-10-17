#include <globaldefs.h>
ARM
extern "C" unsigned int data_ov031_02290cfc[];
extern "C" void Util_ParseFourThreeByteNumbers(const char *, unsigned char *);

// Original: arm9/ov031 @ 0x02235EEC; symbol: func_ov031_02235eec; size: 0x20.
extern "C" void Util_ParseFourThreeByteNumbersIntoGlobalBuffer(const char *source) {
    Util_ParseFourThreeByteNumbers(source, (unsigned char *)data_ov031_02290cfc[0] + 0x4cc);
}
