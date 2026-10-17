#include <globaldefs.h>
ARM
extern "C" unsigned *data_ov031_02290cfc;
extern "C" void Util_ParseFourThreeByteNumbers(void *, void *);
// Original: arm9/ov031 @ 0x02235E90; symbol: func_ov031_02235e90; size: 0x1C.
extern "C" void func_ov031_02235e90(void *argument) {
    Util_ParseFourThreeByteNumbers(argument, (char *)data_ov031_02290cfc + 0x4f0);
}
