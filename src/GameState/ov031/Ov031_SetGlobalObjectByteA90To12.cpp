#include <globaldefs.h>
ARM
extern "C" unsigned char *data_ov031_02290d20;
// Original: arm9/ov031 @ 0x0223AFF8; symbol: func_ov031_0223aff8; size: 0x18.
extern "C" void Ov031_SetGlobalObjectByteA90To12(void) {
    data_ov031_02290d20[0xa90] = 0x0c;
}
