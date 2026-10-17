#include <globaldefs.h>
ARM
extern "C" void func_ov004_02167b78(void *, int);
extern "C" void func_ov011_021848a0(void *, unsigned int);
// Original: arm9/ov004 @ 0x0216848C; symbol: func_ov004_0216848c; size: 0x24.
extern "C" int State_InitializeWithZeroAndSetValue150(void *state) {
    func_ov004_02167b78(state, 0);
    func_ov011_021848a0(state, 0x96);
    return 0;
}
