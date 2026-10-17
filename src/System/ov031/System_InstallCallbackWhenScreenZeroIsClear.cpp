#include <globaldefs.h>
ARM
extern "C" unsigned ReadSelectedContextByte9(int screen);
extern "C" void func_ov031_02223568(int value);
extern "C" void SetMainLoopCallback(void (*callback)());
extern "C" void System_SetCallbackWhenSharedByte22NotMinusTwo(void);
// Original: arm9/ov031 @ 0x02228A58; symbol: func_ov031_02228a58; size: 0x2C.
extern "C" void System_InstallCallbackWhenScreenZeroIsClear(void) {
    if (ReadSelectedContextByte9(0) != 0) return;
    func_ov031_02223568(5);
    SetMainLoopCallback(System_SetCallbackWhenSharedByte22NotMinusTwo);
}
