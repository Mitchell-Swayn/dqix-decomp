#include <globaldefs.h>
ARM
extern "C" void func_ov011_021848a0(void* self, unsigned value);
extern "C" char data_ov004_021707d8;
// Original: arm9/ov004 @ 0x0215AFF0; symbol: func_ov004_0215aff0; size: 0x3C.
extern "C" int GameState_ApplyModeSpecificState(void* self) {
    if (*((unsigned char*)(*(char**)(&data_ov004_021707d8 + 8)) + 0x6e) == 1)
        func_ov011_021848a0(self, 0x39c);
    else
        func_ov011_021848a0(self, 0x39b);
    return 0;
}
