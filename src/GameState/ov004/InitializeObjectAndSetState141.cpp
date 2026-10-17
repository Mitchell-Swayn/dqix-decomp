#include <globaldefs.h>
ARM
extern "C" void func_ov004_02167b78(void *object, unsigned int mode);
extern "C" void func_ov011_021848a0(void *state, unsigned int value);
// Original: arm9/ov004 @ 0x021684B0; symbol: func_ov004_021684b0; size: 0x24.
extern "C" int InitializeObjectAndSetState141(void *object) {
    func_ov004_02167b78(object, 0);
    func_ov011_021848a0(object, 0x8d);
    return 0;
}
