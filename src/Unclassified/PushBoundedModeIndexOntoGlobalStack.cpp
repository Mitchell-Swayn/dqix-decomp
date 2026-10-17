#include <globaldefs.h>

extern "C" volatile unsigned char data_02109da4;
extern "C" volatile signed char data_020f1962[];
extern "C" volatile unsigned char data_02109dae[];
extern "C" void DisableInterruptsAndHaltForever();
extern "C" void func_020a1940(int);

// Original: arm9/main @ 0x020A1DF8; symbol: func_020a1df8; size: 0x5C.
extern "C" void PushBoundedModeIndexOntoGlobalStack(unsigned int index) {
    if (data_02109da4 >= 8) {
        DisableInterruptsAndHaltForever();
    }
    if (index >= 7) {
        return;
    }
    func_020a1940(data_020f1962[index]);
    data_02109dae[data_02109da4] = (unsigned char)index;
    data_02109da4 = data_02109da4 + 1;
}
