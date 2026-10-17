#include <globaldefs.h>
ARM
extern void *data_ov017_021d83ec;
extern "C" void func_ov006_021580b8(void *);
// Original: arm9/ov017 @ 0x021B1CC4; symbol: func_ov017_021b1cc4; size: 0x20.
extern "C" void Resource_ProcessGlobalHandleIfPresent(void) {
    void *handle = data_ov017_021d83ec;
    if (handle)
        func_ov006_021580b8(handle);
}
