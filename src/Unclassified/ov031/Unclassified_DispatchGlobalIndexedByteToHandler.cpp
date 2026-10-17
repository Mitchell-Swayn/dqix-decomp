#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov031_02290c5c[];
extern "C" unsigned char data_ov031_02248dc4[];
extern "C" void ConfigureOverlayCoordinateTransform(void *, unsigned int, unsigned int);

// Original: arm9/ov031 @ 0x02229748; symbol: func_ov031_02229748; size: 0x2C.
extern "C" void Unclassified_DispatchGlobalIndexedByteToHandler(void) {
    unsigned int index = data_ov031_02290c5c[0];
    unsigned int value = data_ov031_02248dc4[index];
    ConfigureOverlayCoordinateTransform(*(void **)(data_ov031_02290c5c + 4), value, value);
}
