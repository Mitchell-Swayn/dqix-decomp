#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov017_021d840c[];
extern "C" void Graphics_ResetEnabledTransfersAndWindow(char *object);
// Original: arm9/ov017 @ 0x021B2F2C; symbol: func_ov017_021b2f2c; size: 0x20.
extern "C" void Graphics_ResetEnabledTransfersAndWindowIfActive(void) {
    char *object = *(char **)data_ov017_021d840c;
    if (object)
        Graphics_ResetEnabledTransfersAndWindow(object);
}
