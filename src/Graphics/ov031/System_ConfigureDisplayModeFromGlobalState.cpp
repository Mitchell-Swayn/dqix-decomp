#include <globaldefs.h>
extern "C" unsigned ReadSelectedContextByte9(int);
extern "C" void func_ov031_02222ddc();
extern "C" unsigned char data_ov031_02290c58;
extern "C" void func_ov031_0223c078(int, int, int, int);
extern "C" void SetMainLoopCallback(void (*)());
extern "C" void Graphics_ConfigureDisplayPlanesForPrimaryContextMode();
// Original: arm9/ov031 @ 0x022287F4; symbol: func_ov031_022287f4; size: 0x64.
extern "C" void System_ConfigureDisplayModeFromGlobalState() {
    if (ReadSelectedContextByte9(1)) return;
    func_ov031_02222ddc();
    if (data_ov031_02290c58 == 0) func_ov031_0223c078(3, 1, 1, 8);
    func_ov031_0223c078(3, 0, 0x15, 8);
    SetMainLoopCallback(Graphics_ConfigureDisplayPlanesForPrimaryContextMode);
}
