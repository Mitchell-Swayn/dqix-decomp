#include <globaldefs.h>
ARM
extern "C" void KrakPot_ReleaseFieldMenuSession(void *object);
// Original: arm9/ov017 @ 0x021B1D24; symbol: func_ov017_021b1d24; size: 0x18.
extern "C" void KrakPot_CancelFieldMenuSession(void *object) {
    KrakPot_ReleaseFieldMenuSession(object);
    *(unsigned char *)((char *)object + 1) = 1;
}
