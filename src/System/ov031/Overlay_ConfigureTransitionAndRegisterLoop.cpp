#include <globaldefs.h>
ARM
extern "C" unsigned ReadSelectedContextByte9(int);
extern "C" void func_ov031_02222ddc();
extern "C" void func_ov031_0223c078(int, int, int, int);
extern "C" void SetMainLoopCallback(void (*)(void));
extern "C" void func_ov031_02234bb8();
extern "C" unsigned char data_ov031_02290ce4;
// Original: arm9/ov031 @ 0x02234B4C; symbol: func_ov031_02234b4c; size: 0x6C.
extern "C" void Overlay_ConfigureTransitionAndRegisterLoop(void) {
    if (ReadSelectedContextByte9(1)) return;
    func_ov031_02222ddc();
    unsigned value = (unsigned char)(data_ov031_02290ce4 + 0xfe);
    if (value <= 1) func_ov031_0223c078(3, 1, 1, 8);
    func_ov031_0223c078(3, 0, 0x15, 8);
    SetMainLoopCallback(func_ov031_02234bb8);
}
