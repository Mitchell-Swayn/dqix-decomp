#include <globaldefs.h>
extern "C" volatile unsigned char data_02109da4[];
extern "C" signed char data_020f1977[];
extern "C" volatile unsigned char data_02109da6[];
extern "C" void DisableInterruptsAndHaltForever();
extern "C" void func_020a1940(int);
// Original: arm9/main @ 0x020A1EF0; symbol: func_020a1ef0; size: 0x5C.
extern "C" void OverlayLoader_PushMappedOverlaySlot(unsigned int index) {
    if (data_02109da4[1] >= 8) DisableInterruptsAndHaltForever();
    if (index >= 7) return;
    func_020a1940(data_020f1977[index]);
    data_02109da6[data_02109da4[1]] = (unsigned char)index;
    data_02109da4[1] = data_02109da4[1] + 1;
}
