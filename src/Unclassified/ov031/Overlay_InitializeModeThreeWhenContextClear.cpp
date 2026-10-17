#include <globaldefs.h>
ARM
extern "C" unsigned ReadSelectedContextByte9(int screen);
extern "C" unsigned char data_ov031_02290cac[];
extern "C" void func_ov031_02222ddc(void);
extern "C" void func_ov031_0223c078(unsigned, unsigned, unsigned, unsigned);
extern "C" void SetMainLoopCallback(void (*callback)(void));
extern "C" void func_ov031_022313a0(void);
// Original: arm9/ov031 @ 0x0223132C; symbol: func_ov031_0223132c; size: 0x74.
extern "C" void Overlay_InitializeModeThreeWhenContextClear(void) {
    if (ReadSelectedContextByte9(1) != 0) return;
    if (data_ov031_02290cac[0] == 0) func_ov031_02222ddc();
    if (data_ov031_02290cac[0] == 0) func_ov031_0223c078(3, 1, 1, 8);
    func_ov031_0223c078(3, 0, 0x15, 8);
    SetMainLoopCallback(func_ov031_022313a0);
}
