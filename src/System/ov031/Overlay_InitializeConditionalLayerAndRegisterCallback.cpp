#include <globaldefs.h>
ARM
extern "C" unsigned int ReadSelectedContextByte9(int);
extern "C" void func_ov031_02222ddc(void);
extern "C" unsigned char data_ov031_02290cb0;
extern "C" void func_ov031_0223c078(int, int, int, int);
extern "C" void SetMainLoopCallback(void (*)(void));
extern "C" void func_ov031_022317a8(void);
// Original: arm9/ov031 @ 0x02231744; symbol: func_ov031_02231744; size: 0x64.
extern "C" void Overlay_InitializeConditionalLayerAndRegisterCallback(void) {
    if (ReadSelectedContextByte9(1) != 0) return;
    func_ov031_02222ddc();
    if (data_ov031_02290cb0 == 0) func_ov031_0223c078(3, 1, 1, 8);
    func_ov031_0223c078(3, 0, 0x15, 8);
    SetMainLoopCallback(func_ov031_022317a8);
}
