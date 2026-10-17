#include <globaldefs.h>
ARM
extern "C" unsigned char data_02108760[];
extern "C" unsigned char data_ov001_0216587c[];
extern "C" void DispatchValueToAlternateOrEmbeddedResource(unsigned char *p, void *target, unsigned amount);
// Original: arm9/ov001 @ 0x021599B8; symbol: func_ov001_021599b8; size: 0x24.
extern "C" int Resource_DispatchGlobalPairAndReturnZero(void) {
    DispatchValueToAlternateOrEmbeddedResource(data_02108760, data_ov001_0216587c, 0);
    return 0;
}
