#include <globaldefs.h>
ARM
extern "C" void func_ov017_021ac32c(void *object, unsigned value);
// Original: arm9/ov017 @ 0x021ACA00; symbol: func_ov017_021aca00; size: 0x14.
extern "C" void Ov017_SetFlagAndForward(void *object) {
    *(unsigned char *)((char *)object + 1) = 1;
    func_ov017_021ac32c(object, 1);
}
