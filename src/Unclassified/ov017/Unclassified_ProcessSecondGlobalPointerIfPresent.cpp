#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov017_021d8478[];
extern "C" void func_ov003_02154eec(void *);
// Original: arm9/ov017 @ 0x021C162C; symbol: func_ov017_021c162c; size: 0x20.
extern "C" void Unclassified_ProcessSecondGlobalPointerIfPresent(void) {
    void *object = *(void **)data_ov017_021d8478;
    if (object != 0)
        func_ov003_02154eec(object);
}
