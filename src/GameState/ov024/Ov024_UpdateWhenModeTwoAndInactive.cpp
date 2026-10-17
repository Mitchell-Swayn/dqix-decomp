#include <globaldefs.h>
extern "C" int TestFlag2AndModeTwo(void*);
extern "C" void func_ov024_021fd160(void*, unsigned);
// Original: arm9/ov024 @ 0x021FD3F0; symbol: func_ov024_021fd3f0; size: 0x38.
extern "C" ARM void Ov024_UpdateWhenModeTwoAndInactive(void* object) {
    void* nested = *(void**)((char*)object + 0x668);
    if (!TestFlag2AndModeTwo(*(void**)((char*)nested + 0x138))) return;
    if (*((unsigned char*)object + 0x661)) return;
    func_ov024_021fd160(object, 2);
}
