#include <globaldefs.h>
ARM
extern "C" void func_ov017_02190264(void *, int);
// Original: arm9/ov017 @ 0x02190238; symbol: func_ov017_02190238; size: 0x2C.
extern "C" void Unclassified_InvokeIndexedHelperFourTimes(void *object) {
    for (int index = 0; index < 4; ++index)
        func_ov017_02190264(object, index);
}
