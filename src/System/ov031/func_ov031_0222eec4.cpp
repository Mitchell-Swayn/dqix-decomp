#include <globaldefs.h>
ARM
extern "C" unsigned int ReadSelectedContextByte9(int screen);
extern "C" void SetMainLoopCallback(void (*callback)());
extern "C" void func_ov031_0222eef8();
// Original: arm9/ov031 @ 0x0222EEC4; symbol: func_ov031_0222eec4; size: 0x34.
extern "C" void func_ov031_0222eec4(void) {
    if (ReadSelectedContextByte9(1) != 0) return;
    if (ReadSelectedContextByte9(0) != 0) return;
    SetMainLoopCallback(func_ov031_0222eef8);
}
