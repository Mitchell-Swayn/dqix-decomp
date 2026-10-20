#include <globaldefs.h>
ARM
extern "C" int DispatchModeIndexedMemberFunctionIfPresent(void *);
// Original: arm9/ov003 @ 0x02173788; symbol: func_ov003_02173788; size: 0x5C.
extern "C" void UpdateHandlerModeState(void *self) {
    DispatchModeIndexedMemberFunctionIfPresent((unsigned char *)self + 0xd8);
    if (*((unsigned char *)self + 0xef) != 0) return;
    if (*((unsigned char *)self + 0xcb) != 0) {
        *((unsigned char *)self + 0xcb) = 0;
        *((unsigned char *)self + 0xed) = 3;
        *((unsigned char *)self + 0xef) = 0;
        return;
    }
    if (*((unsigned char *)self + 0xca) != 0) {
        *((unsigned char *)self + 0xed) = 4;
        *((unsigned char *)self + 0xef) = 0;
    }
}
