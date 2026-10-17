#include <globaldefs.h>
ARM
extern "C" void System_ActivateGlobalControlForObject(void);
extern "C" unsigned int Unclassified_InvokeHelperWithZeroFifthArgument(unsigned int, void (*)(void), unsigned int, unsigned int);
// Original: arm9/ov031 @ 0x022277E4; symbol: func_ov031_022277e4; size: 0x20.
extern "C" unsigned int func_ov031_022277e4(void) {
    return Unclassified_InvokeHelperWithZeroFifthArgument(0, System_ActivateGlobalControlForObject, 0, 0x78);
}
