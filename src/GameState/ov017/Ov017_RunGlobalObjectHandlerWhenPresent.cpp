#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov017_021d83ec[];
extern "C" void func_ov006_02158478(void);
// Original: arm9/ov017 @ 0x021B1D04; symbol: func_ov017_021b1d04; size: 0x20.
extern "C" void Ov017_RunGlobalObjectHandlerWhenPresent(void) {
    if (*(void **)data_ov017_021d83ec != 0) func_ov006_02158478();
}
