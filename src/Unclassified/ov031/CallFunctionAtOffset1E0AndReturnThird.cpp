#include <globaldefs.h>
ARM
extern "C" void func_ov031_0220bab8(void *);
// Original: arm9/ov031 @ 0x022093F4; symbol: func_ov031_022093f4; size: 0x18.
extern "C" int CallFunctionAtOffset1E0AndReturnThird(void *object, void *unused, int result) {
    func_ov031_0220bab8((unsigned char *)object + 0x1e0);
    return result;
}
