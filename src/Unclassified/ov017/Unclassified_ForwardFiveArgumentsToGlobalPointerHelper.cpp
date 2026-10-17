#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov017_021d83ac[];
extern "C" void func_ov002_0216c2d8(void *, int, int, int, int);
// Original: arm9/ov017 @ 0x021A5A88; symbol: func_ov017_021a5a88; size: 0x28.
extern "C" void Unclassified_ForwardFiveArgumentsToGlobalPointerHelper(void *arg0, int arg1, int arg2, int arg3, unsigned char arg4) {
    void *object = *(void **)data_ov017_021d83ac;
    if (object != 0)
        func_ov002_0216c2d8(object, arg1, arg2, arg3, arg4);
}
