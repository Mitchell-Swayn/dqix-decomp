#include <globaldefs.h>
ARM
extern "C" void OV017_DestroyResourceAndRestoreOverlay(void *object);
// Original: arm9/ov017 @ 0x021B1D24; symbol: func_ov017_021b1d24; size: 0x18.
extern "C" void Util_InitializeObjectAndSetByte1(void *object) {
    OV017_DestroyResourceAndRestoreOverlay(object);
    *(unsigned char *)((char *)object + 1) = 1;
}
