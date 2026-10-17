#include <globaldefs.h>
ARM
extern "C" unsigned ReadSelectedContextByte9(int);
extern "C" void func_ov031_02222ddc();
extern "C" unsigned char data_ov031_02290c74[];
extern "C" void func_ov031_0223c078(int, int, int, int);
extern "C" void SetMainLoopCallback(void*);
extern "C" void Graphics_ConfigureDisplayPlanesAndSelectLoopCallback();
// Original: arm9/ov031 @ 0x0222A5B8; symbol: func_ov031_0222a5b8; size: 0x64.
extern "C" void ConfigureThirdContextAfterTransition() {
    if (ReadSelectedContextByte9(1) != 0) return;
    func_ov031_02222ddc();
    if (data_ov031_02290c74[1] == 0) func_ov031_0223c078(3, 1, 1, 8);
    func_ov031_0223c078(3, 0, 0x15, 8);
    SetMainLoopCallback((void*)Graphics_ConfigureDisplayPlanesAndSelectLoopCallback);
}
