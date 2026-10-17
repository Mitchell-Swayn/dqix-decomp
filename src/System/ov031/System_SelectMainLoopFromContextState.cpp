#include <globaldefs.h>
ARM
extern "C" unsigned ReadSelectedContextByte9(int screen);
extern "C" unsigned char data_ov031_02290c78[];
extern "C" void func_ov031_022277e4(void);
extern "C" void func_ov031_02227874(void);
extern "C" void func_ov031_0222a9c0(void);
extern "C" void SetMainLoopCallback(void (*callback)(void));
// Original: arm9/ov031 @ 0x0222A964; symbol: func_ov031_0222a964; size: 0x5C.
extern "C" void System_SelectMainLoopFromContextState(void) {
    if (ReadSelectedContextByte9(1) != 0)
        return;
    if (ReadSelectedContextByte9(0) != 0)
        return;
    if (data_ov031_02290c78[0] == 0 && data_ov031_02290c78[1] == 1)
        func_ov031_02227874();
    else
        func_ov031_022277e4();
    SetMainLoopCallback(func_ov031_0222a9c0);
}
