#include <globaldefs.h>
ARM
extern "C" unsigned int ReadSelectedContextByte9(int);
extern "C" void func_ov031_02222ddc(void);
extern "C" unsigned char data_ov031_02290c80[];
extern "C" void func_ov031_0223c078(int, int, int, int);
extern "C" void SetMainLoopCallback(void (*)(void));
extern "C" void func_ov031_0222b290(void);
// Original: arm9/ov031 @ 0x0222B22C; symbol: func_ov031_0222b22c; size: 0x64.
extern "C" void Graphics_InitializeContextPlanesAndCallback(void) {
    if (ReadSelectedContextByte9(1) != 0) return;
    func_ov031_02222ddc();
    if (data_ov031_02290c80[0] == 0) func_ov031_0223c078(3, 1, 1, 8);
    func_ov031_0223c078(3, 0, 0x15, 8);
    SetMainLoopCallback(func_ov031_0222b290);
}
