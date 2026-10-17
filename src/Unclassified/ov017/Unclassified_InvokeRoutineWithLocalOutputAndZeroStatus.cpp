#include <globaldefs.h>
ARM
extern "C" void func_ov017_02190884(void *, void *, int *, int, int, int);
// Original: arm9/ov017 @ 0x021907DC; symbol: func_ov017_021907dc; size: 0x3C.
extern "C" void Unclassified_InvokeRoutineWithLocalOutputAndZeroStatus(void *unused, void *input, int selector, int argument3, int argument4, int argument5) {
    int output[4];
    int initialized = 0;
    func_ov017_02190884(input, output, &initialized, selector, argument3, argument4);
}
