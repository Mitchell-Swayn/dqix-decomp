#include <globaldefs.h>
ARM
extern "C" void *func_ov000_02160c84(void *);
// Original: arm9/ov017 @ 0x021B8438; symbol: func_ov017_021b8438; size: 0x18.
extern "C" void Unclassified_ProcessObjectField6ACIfPresent(void *object) {
    void *value = *(void **)((unsigned char *)object + 0x6AC);
    if (value == 0)
        return;
    func_ov000_02160c84(value);
}
