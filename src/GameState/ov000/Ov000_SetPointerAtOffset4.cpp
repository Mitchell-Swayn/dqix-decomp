#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov000_02184288[];
// Original: arm9/ov000 @ 0x021744F4; symbol: func_ov000_021744f4; size: 0x10.
extern "C" void Ov000_SetPointerAtOffset4(void *unused, void *value) {
    *(void **)(data_ov000_02184288 + 4) = value;
}
