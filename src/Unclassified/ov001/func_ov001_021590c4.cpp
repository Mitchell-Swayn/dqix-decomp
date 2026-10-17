#include <globaldefs.h>
ARM
extern "C" void *func_ov001_02158dcc(void);

// Original: arm9/ov001 @ 0x021590C4; symbol: func_ov001_021590c4; size: 0x18.
extern "C" void *func_ov001_021590c4(void) {
    void *result = func_ov001_02158dcc();
    if (result != 0)
        *(int *)result = 9;
    return result;
}
