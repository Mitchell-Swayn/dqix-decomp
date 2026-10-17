#include <globaldefs.h>
ARM
extern "C" void *data_ov017_021d83ac;
extern "C" void func_ov002_02155f4c(void *object);
// Original: arm9/ov017 @ 0x021A5954; symbol: func_ov017_021a5954; size: 0x20.
extern "C" void RunOverlayContextRoutineWhenGlobalObjectPresent(void) {
    void *object = data_ov017_021d83ac;
    if (object) func_ov002_02155f4c(object);
}
